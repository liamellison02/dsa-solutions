/*
platform: lc
id: 4
name: median of two sorted arrays
pattern: binary_search/on_array
tags: binary-search,array,divide-and-conquer,median
complexity:
- time = O(log(min(m, n)))
- space = O(1)
notes:
binary search on smaller arr
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
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    VI &A{nums1}, B{nums2};
    if (A.size() > B.size())
      swap(A, B);
    int m = A.size(), n = B.size();

    int target{(m + n + 1) / 2};
    int l{0}, r{m};

    while (l <= r) {
      int a{(l + r) / 2};
      int b{target - a};

      int a0 = a > 0 ? A[a - 1] : INT_MIN;
      int b0 = b > 0 ? B[b - 1] : INT_MIN;
      int a1 = a < m ? A[a] : INT_MAX;
      int b1 = b < n ? B[b] : INT_MAX;

      if (a0 <= b1 && b0 <= a1)
        return (m + n) % 2 ? max(a0, b0) : (max(a0, b0) + min(a1, b1)) / 2.0;

      if (a0 > b1)
        r = a - 1;
      else
        l = a + 1;
    }

    return -1;
  }
};
