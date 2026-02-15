/*
platform: lc
id: 3799
name: word squares II
difficulty: medium
url: https://leetcode.com/problems/word-squares-ii/
pattern: arrays/hashing
tags: hashing,bruteforce,combinatorics,backtracking
- time = O(n^4) worst case
- space = O(n)
notes: bucket words by (first,last) letters, enumerate valid 4-word squares
using prefiltered buckets
*/

#include <algorithm>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VC = vector<char>;
using VI = vector<int>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVS = vector<VS>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

class Solution {
public:
  vector<vector<string>> wordSquares(vector<string> &words) {
    int n = words.size();

    VVI bt(26 * 26);
    VI dne0;

    for (int i{}; i < n; ++i) {
      int a{words[i][0] - 'a'}, b{words[i][3] - 'a'};
      int k{a * 26 + b};

      if (bt[k].empty())
        dne0.push_back(k);
      bt[k].push_back(i);
    }

    VVS res;

    for (int li{0}; li < n; ++li) {
      int l0 = words[li][0] - 'a';
      int l3 = words[li][3] - 'a';

      for (int rpk : dne0) {
        int r0 = rpk / 26;
        int r3 = rpk % 26;
        int tk = l0 * 26 + r0;
        int bk = l3 * 26 + r3;

        auto &t = bt[tk];
        auto &b = bt[bk];
        auto &r = bt[rpk];

        if (t.empty() || b.empty())
          continue;

        for (int ri : r) {
          if (ri == li)
            continue;
          for (int ti : t) {
            if (ti == li || ti == ri)
              continue;
            for (int bi : b) {
              if (bi == li || bi == ri || bi == ti)
                continue;
              res.push_back({words[ti], words[li], words[ri], words[bi]});
            }
          }
        }
      }
    }

    sort(res.begin(), res.end());
    return res;
  }
};
