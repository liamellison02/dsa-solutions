/*
platform: lc
id: 3047
name: find the largest area of square inside two rectangles
pattern: math/geometry
tags: math,geometry,area,overlap,array
complexity:
- time = O(n*n)
- space = O(1)
notes:
1) check all possible overlaps.
2) early terminate when overlap w or h = 0
3) return max overlap

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
  long long largestSquareArea(vector<vector<int>> &bottomLeft,
                              vector<vector<int>> &topRight) {
    const int n = bottomLeft.size();
    ll res{0};

    for (int i{}; i < n; ++i) {
      const int ax1 = bottomLeft[i][0], ay1 = bottomLeft[i][1],
                ax2 = topRight[i][0], ay2 = topRight[i][1];
      for (int j = i + 1; j < n; ++j) {
        const int bx1 = bottomLeft[j][0], by1 = bottomLeft[j][1],
                  bx2 = topRight[j][0], by2 = topRight[j][1];

        const int w = max(0, min(ax2, bx2) - max(ax1, bx1));
        const int h = max(0, min(ay2, by2) - max(ay1, by1));

        if (w > 0 && h > 0) {
          const ll s = min(w, h);
          res = max(res, s * s);
        }
      }
    }
    return res;
  }
};
