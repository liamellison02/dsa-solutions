/*
platform: lc
id: 3713
name: longest balanced substring I
difficulty: medium
url: https://leetcode.com/problems/longest-balanced-substring-i/
pattern: strings
tags: string,hashing,array,frequency
complexity:
- time = O(n*n)
- space = O(26) = O(1)
notes:
brute-force solution
check all substrings and keep a freq arr for each char
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
    int n = s.size(), res{};
    rep(i, n) {
      int cnt[26] = {}, mx = 0, v = 0;
      FOR(j, i, n) {
        int c = s[j] - 'a';
        if (++cnt[c] == 1)
          ++v;
        if (cnt[c] > mx)
          mx = cnt[c];
        if (mx * v == j - i + 1 && j - i + 1 > res)
          res = j - i + 1;
      }
    }
    return res;
  }
};
