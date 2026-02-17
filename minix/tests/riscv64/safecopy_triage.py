#!/usr/bin/env python3
"""
Classify the first safecopy error in a QEMU boot log as:
  - acceptable noise
  - potential consistency issue
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from dataclasses import dataclass
from pathlib import Path


FATAL_RE = re.compile(
    r"panic|PANIC|SIGSEGV|Segmentation fault|assertion failed|kernel panic"
)
SAFECOPY_RE = re.compile(r"safecopy|do_safecopy", re.IGNORECASE)
SHELL_RE = re.compile(r'MINIX 3\.4\.0|exec path="/bin/sh"|^# ', re.MULTILINE)


@dataclass
class LogLine:
    no: int
    text: str


@dataclass(frozen=True)
class NoiseSignature:
    name: str
    pattern: re.Pattern[str]


# Known non-fatal fallback contexts observed in current riscv64 bring-up.
# Matching requires both error code and request context (caller + direction).
KNOWN_NOISE_SIGNATURES = [
    NoiseSignature(
        name="boot-copy retry: ds/vfs caller with gid=1 pull",
        pattern=re.compile(
            r"rv64: kcall safecopy err=0xfffffffffffffc1c "
            r"caller=(?:ds|vfs)/0x[0-9a-f]+ from_to=0x2 gid=0x1",
            re.IGNORECASE,
        ),
    ),
    NoiseSignature(
        name="boot-copy retry follow-up: do_safecopy_from err -996",
        pattern=re.compile(
            r"do_safecopy_from: err -996 caller=(?:1|6)\b.*from_to=2\b.*gid=1",
            re.IGNORECASE,
        ),
    ),
    NoiseSignature(
        name="fs write fallback: mfs/procfs push with err=EFAULT",
        pattern=re.compile(
            r"rv64: kcall safecopy err=0xfffffffffffffff2 "
            r"caller=(?:mfs|procfs)/0x[0-9a-f]+ from_to=0x1",
            re.IGNORECASE,
        ),
    ),
    NoiseSignature(
        name="fs/procfs write fallback follow-up: do_safecopy_to err -14/-996",
        pattern=re.compile(
            r"do_safecopy_to: err -(?:14|996) caller=(?:10|65550)\b.*from_to=1",
            re.IGNORECASE,
        ),
    ),
    NoiseSignature(
        name="procfs copy fallback detail: safecopy err -996 caller=65550",
        pattern=re.compile(
            r"safecopy: err -996 caller=65550\b.*grantee=65550\b.*access=0x2",
            re.IGNORECASE,
        ),
    ),
]


def match_noise_signature(text: str) -> str | None:
    for signature in KNOWN_NOISE_SIGNATURES:
        if signature.pattern.search(text):
            return signature.name
    return None


def find_first(lines: list[LogLine], pattern: re.Pattern[str]) -> LogLine | None:
    for line in lines:
        if pattern.search(line.text):
            return line
    return None


def count_matches(lines: list[LogLine], pattern: re.Pattern[str]) -> int:
    return sum(1 for line in lines if pattern.search(line.text))


def classify(
    lines: list[LogLine],
    max_total_safecopy: int,
    max_pre_shell_safecopy: int,
) -> tuple[dict, int]:
    first_fatal = find_first(lines, FATAL_RE)
    first_safecopy = find_first(lines, SAFECOPY_RE)

    shell_line_no = None
    for line in lines:
        if SHELL_RE.search(line.text):
            shell_line_no = line.no
            break

    safecopy_total = count_matches(lines, SAFECOPY_RE)
    if shell_line_no is None:
        safecopy_pre_shell = safecopy_total
    else:
        safecopy_pre_shell = sum(
            1 for line in lines if line.no <= shell_line_no and SAFECOPY_RE.search(line.text)
        )

    result = {
        "classification": "",
        "first_safecopy_line": first_safecopy.no if first_safecopy else None,
        "first_safecopy_text": first_safecopy.text if first_safecopy else None,
        "first_safecopy_signature": None,
        "safecopy_total": safecopy_total,
        "safecopy_pre_shell": safecopy_pre_shell,
        "shell_line": shell_line_no,
        "first_fatal_line": first_fatal.no if first_fatal else None,
        "first_fatal_text": first_fatal.text if first_fatal else None,
        "reasons": [],
    }

    if first_fatal is not None:
        result["classification"] = "potential_consistency_issue"
        result["reasons"].append("fatal signature present")
        return result, 2

    if first_safecopy is None:
        result["classification"] = "acceptable_noise"
        result["reasons"].append("no safecopy errors found")
        return result, 0

    signature_name = match_noise_signature(first_safecopy.text)
    result["first_safecopy_signature"] = signature_name
    if signature_name is None:
        result["classification"] = "potential_consistency_issue"
        result["reasons"].append(
            "first safecopy error is not in allowlisted (err+caller+direction) contexts"
        )
        return result, 2

    if safecopy_total > max_total_safecopy:
        result["classification"] = "potential_consistency_issue"
        result["reasons"].append(
            f"safecopy count too high ({safecopy_total} > {max_total_safecopy})"
        )
        return result, 2

    if safecopy_pre_shell > max_pre_shell_safecopy:
        result["classification"] = "potential_consistency_issue"
        result["reasons"].append(
            "too many safecopy errors before shell marker "
            f"({safecopy_pre_shell} > {max_pre_shell_safecopy})"
        )
        return result, 2

    if shell_line_no is None:
        result["classification"] = "potential_consistency_issue"
        result["reasons"].append("no shell marker found")
        return result, 2

    result["classification"] = "acceptable_noise"
    result["reasons"].append(f"known recoverable safecopy context: {signature_name}")
    return result, 0


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("logfile", type=Path)
    parser.add_argument("--json", action="store_true")
    parser.add_argument("--max-total-safecopy", type=int, default=24)
    parser.add_argument("--max-pre-shell-safecopy", type=int, default=8)
    args = parser.parse_args()

    if not args.logfile.exists():
        print(f"log not found: {args.logfile}", file=sys.stderr)
        return 1

    text = args.logfile.read_text(errors="ignore")
    lines = [LogLine(i + 1, line) for i, line in enumerate(text.splitlines())]
    result, rc = classify(
        lines,
        max_total_safecopy=args.max_total_safecopy,
        max_pre_shell_safecopy=args.max_pre_shell_safecopy,
    )

    if args.json:
        print(json.dumps(result, ensure_ascii=True, indent=2))
    else:
        print(f"classification: {result['classification']}")
        print(f"first_safecopy_line: {result['first_safecopy_line']}")
        print(f"safecopy_total: {result['safecopy_total']}")
        print(f"safecopy_pre_shell: {result['safecopy_pre_shell']}")
        if result["first_safecopy_signature"]:
            print(f"first_safecopy_signature: {result['first_safecopy_signature']}")
        if result["reasons"]:
            print("reasons:")
            for reason in result["reasons"]:
                print(f"- {reason}")
        if result["first_safecopy_text"]:
            print(f"first_safecopy_text: {result['first_safecopy_text']}")

    return rc


if __name__ == "__main__":
    raise SystemExit(main())
