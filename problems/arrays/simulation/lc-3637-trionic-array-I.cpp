/*
platform: lc
id: 3637
name: trionic array I
difficulty: easy
url: https://leetcode.com/problems/trionic-array-i/
pattern: arrays/simulation
tags: simulation,greedy,two-pointers,array
complexity:
- time = O(n)
- space = O(1)
notes:
greedy/brute force but it's rly just simulation lol.
*/

#include <map>
#include <queue>
#include <set>
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
  bool isTrionic(vector<int> &nums) {
    if (nums[0] >= nums[1])
      return false;
    int i{1}, n = nums.size();

    while (i < n && nums[i - 1] < nums[i])
      ++i;
    if (i == n)
      return false;
    while (i < n && nums[i - 1] > nums[i])
      ++i;
    if (i == n)
      return false;
    while (i < n && nums[i - 1] < nums[i])
      ++i;

    return i == n;
  }
};
