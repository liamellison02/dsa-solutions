/*
platform: lc
id: 3801
name: minimum cost to merge sorted lists
difficulty: hard
url: https://leetcode.com/problems/minimum-cost-to-merge-sorted-lists/
pattern: dp/bitmask
tags: dp,bitmask,merge,median
complexity:
k = avg list length
- time = O(3^n + n * (2^n) * k)
- space = O(2^n * k)
notes: precompute merged lists, sizes, and medians for all subsets; dp over
subset partitions with cost = size + median distance
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
using VI = vector<int>;
using Vll = vector<ll>;
using VVll = vector<Vll>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using UMII = unordered_map<int, int>;

class Solution {
public:
  long long minMergeCost(vector<vector<int>> &a) {
    int n = a.size();
    int N = 1 << n;
    VVI v(N);
    VI sz(N, 0);
    Vll md(N, 0);

    for (int i{}; i < n; ++i) {
      int m = 1 << i;
      v[m] = a[i];
      sz[m] = a[i].size();
      md[m] = v[m][(sz[m] - 1) / 2];
    }

    for (int m{1}; m < N; ++m)
      if (m & (m - 1)) {
        int k{};
        while (((m >> k) & 1) == 0)
          ++k;
        int p = m ^ (1 << k);

        auto &x = v[p];
        auto &y = v[1 << k];

        sz[m] = sz[p] + sz[1 << k];

        int i{}, j{};
        while (i < x.size() || j < y.size())
          (j == y.size() || (i < x.size() && x[i] <= y[j]))
              ? v[m].push_back(x[i++])
              : v[m].push_back(y[j++]);

        md[m] = v[m][(sz[m] - 1) / 2];
      }

    Vll dp(N, (ll)4e18);
    for (int i{}; i < n; ++i)
      dp[1 << i] = 0;

    for (int m{1}; m < N; ++m)
      if (m & (m - 1)) {
        for (int s = (m - 1) & m; s; s = (s - 1) & m) {
          int t = m ^ s;
          if (s > t)
            continue;

          ll cost = (ll)sz[s] + (ll)sz[t] + llabs(md[s] - md[t]);
          dp[m] = min(dp[m], dp[s] + dp[t] + cost);
        }
      }

    return dp[N - 1];
  }
};
