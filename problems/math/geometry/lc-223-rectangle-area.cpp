/*
platform: lc
id: 223
name: rectangle area
pattern: math/geometry
tags: math,geometry,area,overlap
complexity:
- time = O(1)
- space = O(1)
notes:
areaA + areaB - overlap. make sure to account for no overlap cases.
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
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    return ((ay2 - ay1) * (ax2 - ax1)) + ((by2 - by1) * (bx2 - bx1)) -
           ((min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1)));
  }
};
