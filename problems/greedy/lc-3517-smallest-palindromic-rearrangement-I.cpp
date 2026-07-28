/*
platform: lc
id: 3517
name: smallest palindromic rearrangement I
difficulty: medium
url: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
pattern: greedy
tags: greedy,string,palindrome,counting,frequency,two-pointers
complexity:
k = 128 ascii alphabet size
- time = O(n + k)
- space = O(k) = O(1)
notes:
1. count freqs
2. iterate inwards on palindrome, replacing chars in lexicographical order
*/

#include <string>

using namespace std;

class Solution {
public:
  string smallestPalindrome(string s) {
    int n = s.size();
    int cnt[128] = {0};
    for (unsigned char c : s)
      ++cnt[c];

    int a{0}, b{n - 1};
    for (int c{0}; c < 128; ++c) {
      int frq{cnt[c]};
      if (frq == 0)
        continue;

      if (frq & 1) {
        s[n / 2] = static_cast<char>(c);
        --frq;
      }
      while (frq > 0) {
        s[a++] = static_cast<char>(c);
        s[b--] = static_cast<char>(c);
        frq -= 2;
      }
    }
    return s;
  }
};
