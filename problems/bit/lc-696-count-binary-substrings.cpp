/*
platform: lc
id: 696
name: count binary substrings
pattern: bit
tags: binary,bit-operations,enumeration,subsequence,bitstring
complexity:
- time = O(n)
- space = O(1)
notes:
we must enumerate all sequences of consecutive bits, tracking
the indices of the first bit in each sequences and adding the
length of the smallest of two neighboring sequences to the result
after we find the end of a sequence (omitting the first sequence)
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
  int countBinarySubstrings(string s) {
    int n = s.size(), res{0};
    char prev_ch = s[0];
    int i1{0}, i2{0};

    FOR(i, 1, n) {
      if (prev_ch != s[i]) {
        prev_ch = s[i];
        if (i1 != i2) {
          res += min(i2 - i1, i - i2);
          i1 = i2;
        }
        i2 = i;
      }
    }

    res += min(i2 - i1, n - i2);
    return res;
  }
};
