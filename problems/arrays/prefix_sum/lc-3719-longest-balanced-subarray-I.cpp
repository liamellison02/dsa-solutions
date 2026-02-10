/*
platform: lc
id: 3719
name: longest balanced subarray I
pattern: arrays/prefix_sum
tags: prefix-sum,hashing,hashmap,hashtable,array
complexity:
- time = O(n*n)
- space = O(n)
notes:
check all subarrays using prefix hashmap to check balance
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
using vll = vector<ll>;
using si = set<int>;
using usi = unordered_set<int>;
using mi = map<int, int>;
using umi = unordered_map<int, int>;

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
  int longestBalanced(vector<int> &nums) {
    int res{};
    umi odd, even;
    rep(i, nums.size()) {
      odd.clear();
      even.clear();
      FOR(j, i, nums.size()) {
        auto &c = (nums[j] & 1) ? odd : even;
        ++c[nums[j]];
        if (odd.size() == even.size() && ((j - i + 1) > res))
          res = max(res, j - i + 1);
      }
    }
    return res;
  }
};
