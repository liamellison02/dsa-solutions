"""
platform:
id:
name:
pattern:
tags:
complexity:
notes:
"""

import sys

def solve() -> None:
    # write solution here
    pass

def main() -> None:
    input = sys.stdin.readline
    t = 1
    try:
        t = int(input().strip())
    except:
        t = 1
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
