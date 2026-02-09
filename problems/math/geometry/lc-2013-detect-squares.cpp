/*
platform: lc
id: 2013
name: detect squares
pattern: math/geometry
tags: design,math,geometry,hashing,hashmap
complexity:
notes:
simple design problem, just need to read problem statement carefully
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

class DetectSquares {
  unordered_map<int, unordered_map<int, int>> frq;

public:
  DetectSquares() {}
  void add(vector<int> point) { ++frq[point[0]][point[1]]; }

  int count(vector<int> point) {
    int tot{0};

    for (auto &[y, f] : frq[point[0]]) {
      if (y == point[1])
        continue;

      int d = abs(y - point[1]);

      tot += f * frq[point[0] + d][point[1]] * frq[point[0] + d][y];
      tot += f * frq[point[0] - d][point[1]] * frq[point[0] - d][y];
    }

    return tot;
  }
};
