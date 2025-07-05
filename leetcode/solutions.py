class Solution:
    def __init__(self):
        pass

    # 9. Palindrome Number
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
