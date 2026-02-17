/*
platform: lc
id: 401
name: binary watch
pattern: bit
tags: binary,math,bit-operations,simulation,backtracking,combinations
complexity:
- time = O(12 * 60) = O(720) = O(1)
- space = O(1)
notes:

the key observation to make is that the digits shown on the binary
watch (from image in problem statement) match the place value
of each digit in binary.

ex: the hour on the watch has numbers 8 4 2 1.
if the hour == 4 (only 4 is lit up), then the binary representation
of the hour would be 0100.
if the hour == 7 (4, 2, and 1 are lit up), then the binary
representation of the hour would be 0111.

this makes the solution straightforward:
- enumerate all possible values for hr and min,
- check the number of bits in the binary representation of both
- if the total == turnedOn, add the string representation to res.

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
  vector<string> readBinaryWatch(uint32_t turnedOn) {
    VS res;
    auto bits = [](uint32_t a, uint32_t b) -> int {
      int r{0};
      while (a) {
        if (a & 1)
          ++r;
        a >>= 1;
      }
      while (b) {
        if (b & 1)
          ++r;
        b >>= 1;
      }
      return r;
    };
    for (uint32_t h{0}; h < 12; ++h)
      for (uint32_t m{0}; m < 60; ++m)
        if (bits(h, m) == turnedOn)
          res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") +
                        to_string(m));
    return res;
  }
};
