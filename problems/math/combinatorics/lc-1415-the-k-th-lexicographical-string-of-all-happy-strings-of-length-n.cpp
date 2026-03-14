/*
platform: lc
id: 1415
name: the k-th lexicographical string of all happy strings of length n
pattern: math/combinatorics
tags: combinatorics,permutations,modulus,string
complexity:
- time = O(n)
- space = O(1)
notes:
technically O(n) but n <= 10 so it's still way faster
than any non-combinatorics-based solution.
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

/*

n = 2
k = 4
total = 6
THIRD = 2

ab  ac
ba  bc
ca  cb


tot = 3(2)^(n-1)
THIRD = tot / 3
idx = k mod (THIRD)

if k < THIRD:
    starts with a
if k > THIRD && k < 2 * THIRD:
    starts with b
else:
    starts with c

*/

class Solution {
public:
  string getHappyString(int n, int k) {
    int total{3 * (1 << (n - 1))};
    if (k > total)
      return "";

    map<char, char> small = {
        {'a', 'b'},
        {'b', 'a'},
        {'c', 'a'},
    };
    map<char, char> large{
        {'a', 'c'},
        {'b', 'c'},
        {'c', 'b'},
    };

    string res;
    int third{total / 3};

    --k;
    res += 'a' + k / third;
    k %= third;
    third /= 2;

    for (int i{1}; i < n; ++i) {
      res += (k / third) ? large[res.back()] : small[res.back()];
      k %= third;
      third /= 2;
    }

    return res;
  }
};
