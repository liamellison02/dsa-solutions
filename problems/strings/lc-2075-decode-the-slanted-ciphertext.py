"""
platform: lc
id: 2075
name: decode the slanted ciphertext
pattern: strings
tags: simulation,grid,decode,encode
complexity:
- time = O(n)
- space = O(1) -> output doesn't count
notes:
just simulate it bro
"""


class Solution:
    def decodeCiphertext(self, encodedText: str, length: int) -> str:
        n = len(encodedText)
        cols = n // length

        res = []

        for seg in range(cols):
            idx = seg
            for ch in range(length):
                if idx >= n:
                    break
                res.append(encodedText[idx])
                idx += cols + 1

        return "".join(res).rstrip()

    def decodeCiphertextMicroOptimized(self, encodedText: str, length: int) -> str:
        e = encodedText.encode()
        c = len(e) // length
        buf = bytearray()
        for i in range(c):
            buf += e[i :: c + 1]
        return buf.rstrip().decode()
