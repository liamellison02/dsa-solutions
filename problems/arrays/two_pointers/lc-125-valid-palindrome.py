"""
platform: lc
id: 125
name: valid palindrome
difficulty: easy
url: https://leetcode.com/problems/valid-palindrome/
pattern: arrays/two_pointers
tags: palindrome,string
complexity:
notes: convert to digits and use two pointers expanding from center; handle odd/even length separately
"""

def solve():
    pass

def isPalindrome(self, x: int) -> bool:
    if x < 0:
        return False

    def digitize(n):
        rem = n
        digits = []
        while rem > 0:
            digits.append(rem % 10)
            rem //= 10
        return digits

    arr = digitize(x)
    mid = len(arr)//2

    # odd case
    if len(arr) % 2 > 0:
        l, r = mid, mid
        while l >= 0 and r < len(arr):
            if arr[l] != arr[r]:
                return False
            l-=1
            r+=1

    # even case
    else:
        l, r = mid-1, mid
        while l >= 0 and r < len(arr):
            if arr[l] != arr[r]:
                return False
            l-=1
            r+=1
    return True


if __name__ == "__main__":
    solve()
