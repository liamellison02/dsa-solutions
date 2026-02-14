/*
platform: lc
id: 3714
name: longest balanced substring II
pattern: arrays/prefix_sum
tags: prefix-sum,string,hashing
complexity:
- time = O()
- space = O()
notes:
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using Vll = vector<ll>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVll = vector<Vll>;
using VVS = vector<VS>;
using VVPI = vector<VPI>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int longestBalanced(string s) {
    int n = s.size(), res{1};
    if (n == 1)
      return res;

    rep(c, 3) {
      int p{-1};
      rep(i, n) {
        if (s[i] - 'a' != c)
          p = i;
        else if (i - p > res)
          res = i - p;
      }
    }

    static constexpr int pairs[][2] = {{0, 1}, {0, 2}, {1, 2}};
    for (const auto &pr : pairs) {
      int a{pr[0]}, b{pr[1]}, f0{0}, f1{0};
      UMII dti;
      dti[0] = -1;

      rep(i, n) {
        int c = s[i] - 'a';
        if (c == a)
          ++f0;
        else if (c == b)
          ++f1;
        else {
          f0 = f1 = 0;
          dti.clear();
          dti[0] = i;
          continue;
        }
        if (dti.count(f0 - f1)) {
          if (res < i - dti[f0 - f1])
            res = i - dti[f0 - f1];
        } else
          dti[f0 - f1] = i;
      }
    }

    {
      int f[]{0, 0, 0};
      map<PI, int> dti;
      dti[{0, 0}] = -1;

      rep(i, n) {
        ++f[s[i] - 'a'];
        PI d = {f[0] - f[1], f[0] - f[2]};
        if (dti.count(d)) {
          if (i - dti[d] > res)
            res = i - dti[d];
        } else
          dti[d] = i;
      }
    }

    return res;
  }
};
