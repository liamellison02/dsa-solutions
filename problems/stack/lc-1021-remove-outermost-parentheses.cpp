/*
platform: lc
id: 1021
name: remove outermost parentheses
difficulty: easy
url: https://leetcode.com/problems/remove-outermost-parentheses/
pattern: stack
tags: string,stack,counting
complexity:
- time = O(n)
- space = O(n)
notes: track depth instead of an actual stack; '(' at depth 0 and ')' closing back to 0 are the outer ones
mark those indices, then rebuild skipping them
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
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

constexpr int MOD = 1e9 + 7;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using str = string;

using ll = long long;
using ull = unsigned long long;
using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ti = tuple<int, int, int>;
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vpi = vector<pi>;
using vti = vector<ti>;
using vvc = vector<vc>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvs = vector<vs>;
using vvpi = vector<vpi>;

using si = set<int>;
using usi = unordered_set<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename K, typename V> using umap = unordered_map<K, V>;

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
    string removeOuterParentheses(string s) {
        vector<int> rm;
        int curr{0};

        rep(i, s.size()) {
            if (s[i] == '(') {
                if (curr == 0) rm.push_back(i);
                ++curr;
            }
            else {
                if (curr == 1) rm.push_back(i);
                --curr;
            }
        }

        string res{};
        int j{0};

        rep(i, s.size()) {
            if (j < rm.size() && rm[j] == i) ++j;
            else res.push_back(s[i]);
        }
        return res;
    }
};
