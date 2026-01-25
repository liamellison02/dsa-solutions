/*
platform: lc
id: 134
name: gas station
pattern: greedy
tags: greedy,arrays
complexity:
- time = O(n)
- space = O(1)
notes:
must recognize two things:
1) if sum(gas) < sum(cost), then there is no solution.
2) if you cannot reach j when starting at i, then no idx from [i..j] is a
solution.
*/

#include <map>
#include <set>
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
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVS = vector<VS>;
using VVPI = vector<VPI>;
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
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int tot{0}, tnk{0}, res{0};

    for (int i{}; i < gas.size(); ++i) {
      int d = gas[i] - cost[i];
      tot += d;
      tnk += d;

      if (tnk < 0) {
        tnk = 0;
        res = i + 1;
      }
    }

    return tot >= 0 ? res : -1;
  }
};
