/*
platform: lc
id: 190
name: reverse bits
pattern: bit/
tags: bit-manipulation
complexity:
- time = O(5) = O(1)
- space = O(1)
notes:
divide and conquer using bitmask
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
  uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((0b11111111000000001111111100000000 & n) >> 8) |
        ((0b00000000111111110000000011111111 & n) << 8);
    n = ((0b11110000111100001111000011110000 & n) >> 4) |
        ((0b00001111000011110000111100001111 & n) << 4);
    n = ((0b11001100110011001100110011001100 & n) >> 2) |
        ((0b00110011001100110011001100110011 & n) << 2);
    n = ((0b10101010101010101010101010101010 & n) >> 1) |
        ((0b01010101010101010101010101010101 & n) << 1);

    return n;
  }
};
