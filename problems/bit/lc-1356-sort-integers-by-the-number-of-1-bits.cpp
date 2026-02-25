/*
platform: lc
id: 1356
name: sort integers by the number of 1 bits
pattern: bit
tags: bit,bit-manipulation,sorting,counting
complexity:
- time = O(nlogn)
- space = O(n)
notes:
1) sort the integers into buckets by bit cnt
2) sort each of the buckets for dup bit cnts
3) iterate through the bkts in order, updating arr in sequence
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

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using ll = long long;
using ull = unsigned long long;
using str = string;
using ui32 = uint32_t;
using ui64 = uint64_t;
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
  vector<int> sortByBits(vector<int> &arr) {
    auto bits = [](ui32 i) -> int {
      int r;
      while (i) {
        r += i & 1;
        i >>= 1;
      }
      return r;
    };

    vec<vec<int>> bkt(32, VI(0, 0));

    for (auto &n : arr) {
      int b = bits(static_cast<ui32>(n));
      bkt[b].push_back(n);
    }

    for (auto &v : bkt)
      sort(v.begin(), v.end());

    int i{0};
    for (auto &v : bkt) {
      for (auto &n : v) {
        arr[i] = n;
        ++i;
      }
    }

    return arr;
  }
};
