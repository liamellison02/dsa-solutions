"""
platform: lc
id: 140
name: word break II
pattern: strings/trie
tags: bfs,string,prefix,trie,prefix-tree,prefix-set,substring,strings,hashset,enumeration
complexity:
- time = O(2^n * n)
- space = O(2^n * n)
notes:
prefix set + bfs solution (two parts)

a) prefix set
milestone = internal "terminal" node (non-leaf) in a trie that:
- signifies end of a vaild word, but
- still contains children & subsequent paths to longer words

in this context, milestone = string in wordDict

b) bfs():
- iterate through string w/ working buffer of chars since last whitespace
- if buffer reaches a milestone, add buffer to words, increment i

"""

from typing import List

from collections import deque
from itertools import accumulate


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        """ """

        prefix, words = set(), set(wordDict)
        for w in wordDict:
            prefix.update(accumulate(w))

        bfs = deque()
        bfs.extend([([p], len(p)) for p in filter(words.__contains__, accumulate(s))])

        res = []
        while bfs:
            curr, i = bfs.popleft()

            if i == len(s):
                res.append(" ".join(curr))

            for x in accumulate(s[i:]):
                if x not in prefix:
                    break
                if x in words:
                    bfs.append((curr + [x], i + len(x)))

        return res
