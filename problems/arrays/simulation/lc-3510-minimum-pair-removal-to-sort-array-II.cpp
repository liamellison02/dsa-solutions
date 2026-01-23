/*
platform: lc
id: 3510
name: minimum pair removal to sort array II
pattern: arrays/simulation
tags: array,arrays,minheap,priority-queue,heap,linked-list,simulation
complexity:
- time = O(nlogn)
- space = O(n)
notes:
optimized version of part I for larger input constraints:
- heap for O(1) min sum lookup
- linked list (implemented via prev & nxt vectors) for O(1) neighbor lookup &
deletion
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

using TSII = tuple<ll, int, int>;

class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    int n = nums.size(), ops{};
    priority_queue<TSII, vector<TSII>, greater<>> pq;

    vector<ll> vals(nums.begin(), nums.end());
    vector<int> prev(n), nxt(n);

    for (int i{}; i < n; ++i) {
      prev[i] = i - 1;
      nxt[i] = i + 1;
    }

    int rem{};
    for (int i{}; i < n - 1; ++i) {
      pq.emplace(vals[i] + vals[i + 1], i, i + 1);
      if (vals[i] > vals[i + 1])
        ++rem;
    }

    while (rem > 0) {
      auto [s, l, r] = pq.top();
      pq.pop();

      if (nxt[l] != r || (ll)vals[l] + vals[r] != s)
        continue;

      if (prev[l] >= 0 && vals[prev[l]] > vals[l])
        --rem;
      if (nxt[r] < n && vals[nxt[r]] < vals[r])
        --rem;
      if (vals[l] > vals[r])
        --rem;

      vals[l] = s;
      nxt[l] = nxt[r];
      nxt[r] = -1;
      ++ops;

      if (prev[l] >= 0) {
        if (vals[prev[l]] > vals[l])
          ++rem;
        pq.emplace((ll)vals[prev[l]] + vals[l], prev[l], l);
      }
      if (nxt[l] < n) {
        prev[nxt[l]] = l;
        if (vals[nxt[l]] < vals[l])
          ++rem;
        pq.emplace((ll)vals[l] + vals[nxt[l]], l, nxt[l]);
      }
    }

    return ops;
  }
};
