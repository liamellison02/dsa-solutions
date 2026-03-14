#!/usr/bin/env python3
"""
Test runner for DSA solutions.
Supports LeetCode (Python) and Codeforces (Python/C++).

Test file format (.txt companion file):
  - Test cases separated by '==='
  - Within each test case, '---' separates input from expected output
  - Lines starting with '#' are comments

Codeforces example:
    4
    ---
    2
    ===
    3
    ---
    1

LeetCode example (one method arg per line, as Python literals):
    [2,7,11,15]
    9
    ---
    [0,1]
"""

import sys
import os
import ast
import subprocess
import re
import importlib.util
import inspect
import tempfile
from collections import deque
from pathlib import Path

# ── colors ──────────────────────────────────────────────────────────────────

PASS  = "\033[32mPASS\033[0m"
FAIL  = "\033[31mFAIL\033[0m"
ERR   = "\033[33mERROR\033[0m"
INFO  = "\033[36m?\033[0m"

# ── platform detection ──────────────────────────────────────────────────────

def detect_platform(filepath: str) -> str:
    with open(filepath) as f:
        head = f.read(500)
    m = re.search(r"platform:\s*(\S+)", head)
    return m.group(1) if m else "unknown"

# ── test case parsing ───────────────────────────────────────────────────────

def parse_test_file(path: str) -> list[tuple[list[str], list[str]]]:
    """Returns list of (input_lines, expected_output_lines)."""
    with open(path) as f:
        content = f.read().strip()

    cases = []
    for raw_case in re.split(r"^={3,}\s*$", content, flags=re.MULTILINE):
        raw_case = raw_case.strip()
        if not raw_case:
            continue

        # strip comment lines
        lines = [l for l in raw_case.split("\n") if not l.strip().startswith("#")]
        raw_case = "\n".join(lines)

        parts = re.split(r"^-{3,}\s*$", raw_case, flags=re.MULTILINE)
        inp = [l for l in parts[0].strip().splitlines() if l.strip()]
        exp = [l for l in parts[1].strip().splitlines() if l.strip()] if len(parts) > 1 else []
        cases.append((inp, exp))

    return cases

# ── CF runner (stdin → stdout) ──────────────────────────────────────────────

def _run_process(cmd: list[str], stdin: str) -> tuple[str, str, int]:
    try:
        p = subprocess.run(cmd, input=stdin, capture_output=True, text=True, timeout=10)
        return p.stdout, p.stderr, p.returncode
    except subprocess.TimeoutExpired:
        return "", "TLE (>10s)", -1

def run_cf_python(path: str, cases):
    results = []
    for i, (inp, exp) in enumerate(cases):
        stdout, stderr, rc = _run_process([sys.executable, path], "\n".join(inp) + "\n")
        actual = [l.strip() for l in stdout.strip().splitlines() if l.strip()]
        results.append(_judge(i + 1, inp, exp, actual, stderr if rc != 0 else ""))
    return results

def run_cf_cpp(path: str, cases):
    binary = tempfile.mktemp()
    lib_cpp = str(Path(__file__).resolve().parent.parent / "cpp")
    p = subprocess.run(
        ["g++", "-std=c++17", "-O2", "-DLOCAL", f"-I{lib_cpp}", "-o", binary, path],
        capture_output=True, text=True,
    )
    if p.returncode != 0:
        print(f"  {ERR} compilation failed:\n{p.stderr}")
        return []

    results = []
    for i, (inp, exp) in enumerate(cases):
        stdout, stderr, rc = _run_process([binary], "\n".join(inp) + "\n")
        actual = [l.strip() for l in stdout.strip().splitlines() if l.strip()]
        err = stderr if rc != 0 else ""
        results.append(_judge(i + 1, inp, exp, actual, err))

    try:
        os.unlink(binary)
    except OSError:
        pass
    return results

# ── LC Python runner (method call) ──────────────────────────────────────────

def _load_module(path: str):
    spec = importlib.util.spec_from_file_location("_solution", path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod

def _find_method(mod):
    """Return (instance, method_name, param_names, type_hints)."""
    cls = getattr(mod, "Solution", None)
    if cls is None:
        return None, None, [], {}

    inst = cls()
    for name in dir(inst):
        if name.startswith("_"):
            continue
        attr = getattr(inst, name)
        if callable(attr):
            sig = inspect.signature(attr)
            params = list(sig.parameters.keys())
            hints = getattr(attr, "__annotations__", {})
            return inst, name, params, hints
    return None, None, [], {}

def _build_tree(vals, node_cls):
    """Build binary tree from level-order list using the solution's own TreeNode."""
    if not vals or vals[0] is None:
        return None
    root = node_cls(vals[0])
    q = deque([root])
    i = 1
    while i < len(vals):
        node = q.popleft()
        if i < len(vals) and vals[i] is not None:
            node.left = node_cls(vals[i])
            q.append(node.left)
        i += 1
        if i < len(vals) and vals[i] is not None:
            node.right = node_cls(vals[i])
            q.append(node.right)
        i += 1
    return root

def _build_linked_list(vals, node_cls):
    """Build linked list from list using the solution's own ListNode."""
    if not vals:
        return None
    head = node_cls(vals[0])
    cur = head
    for v in vals[1:]:
        cur.next = node_cls(v)
        cur = cur.next
    return head

def _tree_to_list(root):
    if not root:
        return []
    result, q = [], deque([root])
    while q:
        node = q.popleft()
        if node:
            result.append(node.val)
            q.append(node.left)
            q.append(node.right)
        else:
            result.append(None)
    while result and result[-1] is None:
        result.pop()
    return result

def _linked_list_to_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

def _parse_arg(raw: str, hint: str | None, mod):
    """Parse a test input line into a Python value, converting to TreeNode/ListNode if needed."""
    val = ast.literal_eval(raw.strip())
    if hint and "TreeNode" in hint:
        node_cls = getattr(mod, "TreeNode", None)
        if node_cls and isinstance(val, list):
            return _build_tree(val, node_cls)
    if hint and "ListNode" in hint:
        node_cls = getattr(mod, "ListNode", None)
        if node_cls and isinstance(val, list):
            return _build_linked_list(val, node_cls)
    return val

def _normalize_result(result, return_hint: str | None = None):
    """Convert TreeNode/ListNode results back to plain Python for comparison."""
    cls_name = type(result).__name__
    if cls_name == "TreeNode":
        return _tree_to_list(result)
    if cls_name == "ListNode":
        return _linked_list_to_list(result)
    # handle None return when hint says TreeNode/ListNode (e.g. empty tree/list)
    if result is None and return_hint:
        if "TreeNode" in return_hint or "ListNode" in return_hint:
            return []
    return result

def run_lc_python(path: str, cases):
    try:
        mod = _load_module(path)
    except Exception as e:
        print(f"  {ERR} failed to import: {e}")
        return []

    inst, method_name, params, hints = _find_method(mod)
    if inst is None:
        print(f"  {ERR} no Solution class found")
        return []

    method = getattr(inst, method_name)
    hint_strs = {k: str(v) for k, v in hints.items()}
    return_hint = hint_strs.get("return")

    results = []
    for i, (inp, exp) in enumerate(cases):
        if len(inp) != len(params):
            results.append(("error", i + 1, inp, exp, [],
                f"method {method_name}() takes {len(params)} args "
                f"({', '.join(params)}), got {len(inp)} input lines"))
            continue
        try:
            args = [_parse_arg(line, hint_strs.get(p), mod) for line, p in zip(inp, params)]
            result = method(*args)
            result = _normalize_result(result, return_hint)
            actual_str = repr(result)

            if not exp:
                results.append(("no_expected", i + 1, inp, [], [actual_str], ""))
                continue

            expected_val = ast.literal_eval(exp[0].strip())

            if _values_equal(result, expected_val):
                results.append(("pass", i + 1, inp, exp, [actual_str], ""))
            else:
                results.append(("fail", i + 1, inp, exp, [actual_str], ""))
        except Exception as e:
            results.append(("error", i + 1, inp, exp, [], str(e)))

    return results

# ── comparison helpers ──────────────────────────────────────────────────────

def _values_equal(a, b) -> bool:
    """Compare values, treating lists and tuples as equal if contents match."""
    if isinstance(a, float) or isinstance(b, float):
        return abs(float(a) - float(b)) < 1e-6
    if isinstance(a, (list, tuple)) and isinstance(b, (list, tuple)):
        return len(a) == len(b) and all(_values_equal(x, y) for x, y in zip(a, b))
    return a == b

# ── judging ─────────────────────────────────────────────────────────────────

def _judge(num, inp, exp, actual, err=""):
    if err:
        return ("error", num, inp, exp, actual, err)
    if not exp:
        return ("no_expected", num, inp, exp, actual, "")
    exp_clean = [l.strip() for l in exp]
    if actual == exp_clean:
        return ("pass", num, inp, exp, actual, "")
    return ("fail", num, inp, exp, actual, "")

# ── output ──────────────────────────────────────────────────────────────────

def print_results(results):
    total = len(results)
    passed = 0

    for status, num, inp, exp, actual, err in results:
        if status == "pass":
            print(f"  {PASS}  test {num}")
            passed += 1
        elif status == "fail":
            print(f"  {FAIL}  test {num}")
            print(f"        input:    {' | '.join(inp)}")
            print(f"        expected: {' | '.join(exp)}")
            print(f"        actual:   {' | '.join(actual)}")
        elif status == "error":
            print(f"  {ERR} test {num}: {err}")
            if inp:
                print(f"        input: {' | '.join(inp)}")
        elif status == "no_expected":
            print(f"  {INFO}     test {num}")
            print(f"        input:  {' | '.join(inp)}")
            print(f"        output: {' | '.join(actual)}")

    print()
    if total > 0:
        color = "\033[32m" if passed == total else "\033[31m"
        print(f"  {color}{passed}/{total} passed\033[0m")
    else:
        print("  no test cases found")

# ── main ────────────────────────────────────────────────────────────────────

def main():
    if len(sys.argv) < 2:
        print("usage: test <solution-file> [test-file]")
        print()
        print("  if no test file given, looks for <solution>.txt")
        print()
        print("test file format:")
        print("  input lines   (one arg per line for LC, raw stdin for CF)")
        print("  ---")
        print("  expected output")
        print("  ===            (separates test cases)")
        sys.exit(1)

    solution = sys.argv[1]
    if not os.path.exists(solution):
        print(f"error: {solution} not found")
        sys.exit(1)

    # resolve test file
    if len(sys.argv) >= 3:
        test_file = sys.argv[2]
    else:
        test_file = os.path.splitext(solution)[0] + ".txt"

    if not os.path.exists(test_file):
        print(f"error: test file not found: {test_file}")
        print(f"  create {test_file} or pass one: test {solution} <test-file>")
        sys.exit(1)

    platform = detect_platform(solution)
    lang = "py" if solution.endswith(".py") else "cpp"

    print(f"\n  testing {os.path.basename(solution)} ({platform}/{lang})\n")

    cases = parse_test_file(test_file)
    if not cases:
        print("  no test cases found in test file")
        sys.exit(1)

    if platform == "lc" and lang == "py":
        results = run_lc_python(solution, cases)
    elif lang == "py":
        results = run_cf_python(solution, cases)
    else:
        results = run_cf_cpp(solution, cases)

    print_results(results)

    if any(r[0] in ("fail", "error") for r in results):
        sys.exit(1)


if __name__ == "__main__":
    main()
