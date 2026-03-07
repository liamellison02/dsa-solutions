/*
platform: lc
id: 1888
name: minimum number of flips to make the binary string alternating
pattern: sliding_window
tags: sliding-window,string,parity,circular-array,bit,binary-string
complexity:
- time = O(n)
- space = O(n)
notes:
similar to LC #1758,
use sliding window over s + s to account for all rotations.
track num flips needed for standard & inverse alternating form over
the entire sliding window
update the min at each step
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
using ui8 = uint8_t;
using ui16 = uint16_t;
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
  int minFlips(string s) {
    int n = s.size();
    int res{n}, stdAlt{0}, invAlt{0};

    string ss = s + s;

    for (int i{0}; i < ss.size(); ++i) {
      int b{ss[i] - '0'};

      if (b != i % 2)
        ++stdAlt;
      if (b != (i + 1) % 2)
        ++invAlt;

      if (i >= n) {
        int rmb{ss[i - n] - '0'};
        if (rmb != (i - n) % 2)
          --stdAlt;
        if (rmb != ((i - n) + 1) % 2)
          --invAlt;
      }

      if (i >= n - 1)
        res = min({res, stdAlt, invAlt});
    }

    return res;
  }
};
