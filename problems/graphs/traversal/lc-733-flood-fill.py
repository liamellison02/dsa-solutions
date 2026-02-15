"""
platform: lc
id: 733
name: flood-fill
difficulty: easy
url: https://leetcode.com/problems/flood-fill/
pattern: graphs/traversal
tags: dfs,matrix,recursion
complexity:
- time = O(m*n)
- space = O(m*n) for recursion stack
notes: DFS from starting pixel; the newColor assignment acts as the visited check, but must short-circuit when newColor == original color to avoid infinite recursion
"""
from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        rows, cols, color = len(image)-1, len(image[0])-1, image[sr][sc]

        def fill(sr, sc):
            if not (0 <= sr <= rows and 0 <= sc <= cols):
                return
            if image[sr][sc] != color or image[sr][sc] == newColor:
                return
            else:
                image[sr][sc] = newColor
                fill(sr+1,sc)
                fill(sr,sc+1)
                fill(sr-1,sc)
                fill(sr,sc-1)

        fill(sr, sc)
        return image
