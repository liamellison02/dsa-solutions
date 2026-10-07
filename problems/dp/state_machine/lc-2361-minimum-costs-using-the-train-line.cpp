/*
platform: lc
id: 2361
name: minimum costs using the train line
difficulty: hard
url: https://leetcode.com/problems/minimum-costs-using-the-train-line/
pattern: dp/state_machine
tags: dp,state-machine,1d-dp,bottom-up,array
complexity:
- time = O(n)
- space = O(1) extra, O(n) for the output
notes:
two states per stop: on regular or on express. only switching reg -> exp costs
expressCost exp starts at expressCost (pay to get on at stop 0), reg starts at 0
reaching stop i on express can come from riding express in, or arriving on
regular then paying to hop over answer at each stop is min of both states,
rolling vars instead of a full dp table

dp[i][j] = min cost to get to stop i when on ((j) ? express : regular)

dp[i][0] = min(dp[i-1][1] + express[i-1], dp[i-1][0] + regular[i-1])
dp[i][1] = min(express[i-1] + min(expressCost + dp[i-1][0], dp[i-1][1]),
dp[i][0] + expressCost)


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

/*

*/

class Solution {
public:
  vector<long long> minimumCosts(vector<int> &regular, vector<int> &express,
                                 int expressCost) {
    int n = regular.size();
    vector<ll> res(n);
    ll reg{0}, exp{expressCost};

    for (int i{1}; i <= n; ++i) {
      ll nreg{min(exp + express[i - 1], reg + regular[i - 1])};
      ll nexp{min(express[i - 1] + min(expressCost + reg, exp),
                  nreg + expressCost)};
      reg = nreg;
      exp = nexp;
      res[i - 1] = min(reg, exp);
    }

    return res;
  }
};
