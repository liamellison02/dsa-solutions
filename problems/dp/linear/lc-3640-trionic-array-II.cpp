/*
platform: lc
id: 3640
name: trionic array II
pattern: dp/linear
tags: dp,array,simulation
complexity:
- time = O(n)
- space = O(1)
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
  long long maxSumTrionic(vector<int> &nums) {
    int n = nums.size();
    ll ans = LLONG_MIN;

    rep(i, n) {
      int j{i + 1};

      // seg1
      for (; j < n && nums[j - 1] < nums[j]; ++j)
        ;

      int p{j - 1};
      if (p == i)
        continue;

      // seg2
      ll res = nums[p - 1] + nums[p];
      for (; j < n && nums[j - 1] > nums[j]; ++j)
        res += nums[j];

      int q{j - 1};
      if (q == p || q == n - 1 || nums[j] <= nums[q]) {
        i = q;
        continue;
      }

      res += nums[q + 1];

      ll mx{0}, sm{0};
      for (int k{q + 2}; k < n && nums[k] > nums[k - 1]; ++k) {
        sm += nums[k];
        if (sm > mx)
          mx = sm;
      }
      res += mx;

      mx = 0;
      sm = 0;
      for (int k{p - 2}; k >= i; --k) {
        sm += nums[k];
        if (sm > mx)
          mx = sm;
      }
      res += mx;

      if (res > ans)
        ans = res;
      i = q - 1;
    }

    return ans;
  }
};
