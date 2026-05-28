"""
platform: lc
id: 3093
name: longest common suffix queries
pattern: strings/trie
tags: trie,string,suffix,hashmap
complexity:
C, Q = total chars in wordsContainer, wordsQuery
- time = O(C + Q)
- space = O(C)
notes:
finding common suffix is just a trie over reversed words (suffix tree)
each node caches its best candidate as (len, idx) to account for tie-breakers

insert():
walks the reversed word
relaxes min(key) at every node

query():
walks the reversed word as far as it matches
returns the best idx at the deepest node reached
"""

from typing import List


class Solution:
    def stringIndices(
        self, wordsContainer: List[str], wordsQuery: List[str]
    ) -> List[int]:
        trie = [{}, (float("inf"), -1)]

        for idx, word in enumerate(wordsContainer):
            key = (len(word), idx)
            curr = trie
            if key < curr[1]:
                curr[1] = key
            for ch in reversed(word):
                nxt = curr[0].get(ch)
                if nxt is None:
                    nxt = [{}, key]
                    curr[0][ch] = nxt
                elif key < nxt[1]:
                    nxt[1] = key
                curr = nxt

        res = []
        for word in wordsQuery:
            curr = trie
            for ch in reversed(word):
                if ch not in curr[0]:
                    break
                curr = curr[0][ch]
            res.append(curr[1][1])
        return res
