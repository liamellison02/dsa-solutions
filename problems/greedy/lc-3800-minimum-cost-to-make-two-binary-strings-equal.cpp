/*
platform: lc
id: 3800
name: minimum cost to make two binary strings equal
difficulty: medium
url: https://leetcode.com/problems/minimum-cost-to-make-two-binary-strings-equal/
pattern: greedy
tags: greedy,math,string
complexity:
- time = O(n)
- space = O(1)
notes: count mismatched 0->1 and 1->0 positions; greedily replace flips with
cheaper swap or swap+cross combinations
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
  long long minimumCost(string s, string t, int flipCost, int swapCost,
                        int crossCost) {
    ll F{flipCost}, S{swapCost}, C{crossCost};

    ll a{}, b{};
    for (int i{}; i < s.size(); ++i)
      if (s[i] != t[i]) {
        if (s[i] == '0')
          ++a;
        else
          ++b;
      }

    ll res = (a + b) * F;

    if (S < 2 * F) {
      ll u = min(a, b);
      res -= u * (2 * F - S);
      a -= u;
      b -= u;
    }

    ll d = max(a, b);
    if (S + C < 2 * F) {
      ll v{d / 2};
      res -= v * (2 * F - (S + C));
    }

    return res;
  }
};
