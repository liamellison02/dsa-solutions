/*
platform: lc
id: 1266
name: minimum time visiting all points
pattern: math/geometry
tags: math,array,geometry
complexity:
- time = O(n)
- space = O(1)
notes:
just think about it for like two seconds lol
*/

#include <algorithm>
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

using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VC = vector<char>;
using VI = vector<int>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVS = vector<VS>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

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
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int n = points.size(), res{};
    for (int i{1}; i < n; ++i)
      res += max(abs(points[i][0] - points[i - 1][0]),
                 abs(points[i][1] - points[i - 1][1]));
    return res;
  }
};
