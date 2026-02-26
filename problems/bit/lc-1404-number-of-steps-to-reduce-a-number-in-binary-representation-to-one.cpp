/*
platform: lc
id: 1404
name: number of steps to reduce a number in binary representation to one
pattern: bit
tags: binary,bit-operations,bit-manipulation,math,simulation
complexity:
- time = O(n)
- space = O(1)
notes:
simulate the problem statement
dividing even num by 2 = remove lowest bit
increment num or div by 2 based on parity until num = 1
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
  int numSteps(string s) {
    int n = s.size();

    auto div = [](string &st) { st.pop_back(); };
    auto inc = [](string &st) {
      int i = st.size() - 1;
      while (i >= 0 && st[i] != '0') {
        st[i] = '0';
        --i;
      }
      if (i < 0)
        st = '1' + st;
      else
        st[i] = '1';
    };

    int ops{0};
    while (s.size() > 1) {
      n = s.size();
      if (s[n - 1] == '0')
        div(s);
      else
        inc(s);
      ++ops;
    }

    return ops;
  }
};
