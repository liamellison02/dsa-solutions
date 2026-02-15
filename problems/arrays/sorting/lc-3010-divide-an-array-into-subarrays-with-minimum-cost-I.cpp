/*
platform: lc
id: 3010
name: divide an array into subarrays with minimum cost I
difficulty: medium
url: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
pattern: arrays/sorting
tags: array,sorting,enumeration
complexity:
- time = O(n)
- space = O(1)
notes:
nums[0] is fixed as 1 of the subarray costs.
find the two min elements following nums[0].
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

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

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
  int minimumCost(vector<int> &nums) {
    int m1 = 51, m2 = 51;
    for (int i{1}; i < nums.size(); ++i) {
      if (nums[i] < m1)
        m2 = m1, m1 = nums[i];
      else if (nums[i] < m2)
        m2 = nums[i];
    }
    return nums[0] + m1 + m2;
  }
};
