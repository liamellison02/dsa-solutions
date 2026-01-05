/*
platform: lc
id: 1975
name: maximum matrix sum
pattern: greedy
tags: greedy,matrix,math
complexity:
- time = O(n*n)
- space = O(1)
notes: trick is that the flip operation allows you to flip any target cell's
sign arbitrarily. this reduces the problem to choosing final signs and
maximizing the sum by taking all abs vals, and if total # of negatives is odd,
flip the smallest abs value since one cell will have to remain negative.
*/

#include <algorithm>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
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
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

class Solution {
public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    ll res{};
    int neg{}, min_abs = INT_MAX;

    for (auto &row : matrix) {
      for (auto cell : row) {
        res += llabs((ll)cell);
        if (cell < 0)
          neg++;
        min_abs = min(min_abs, (int)llabs((ll)cell));
      }
    }

    return neg % 2 == 0 ? res : res - 2LL * min_abs;
  }
};
