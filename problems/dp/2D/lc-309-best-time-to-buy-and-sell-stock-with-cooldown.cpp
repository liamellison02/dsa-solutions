/*
platform: lc
id: 309
name: best time to buy and sell stock with cooldown
pattern: dp/2D
tags: dp,2d-dp,bottom-up
complexity:
- time = O(n)
- space = O(n)
notes:
can be in 1 of 3 states for any given day (hold, sold, rest).
for each day, compute max profit for each possible state:
  if holding on day i, either:
    a) was already holding yesterday
    b) was resting yesterday and bought today
  if sold today:
    a) i was holding stock yesterday
  if resting today, either:
    a) was already resting yesterday
    b) sold yesterday and was on cooldown today
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
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n <= 1)
      return 0;

    vector<int> hold(n + 2, 0), sold(n + 2, 0), rest(n + 2, 0);
    hold[0] = -prices[0];

    for (int i{1}; i < n; ++i) {
      hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);

      sold[i] = hold[i - 1] + prices[i];

      rest[i] = max(rest[i - 1], sold[i - 1]);
    }

    return max(rest[n - 1], sold[n - 1]);
  }
};
