/*
platform: lc
id: 139
name: word break
pattern: dp/linear
tags: dp,1d-dp,string,substring,bottom-up
complexity:
- time = O(n * m)
- space = O(n)
notes: (bottom-up) similar idea to bottom-up solution for jump game.
iterate backwards through string, marking dp[i] as true if both of the following
are true:
  a) there exists a word w in wordDict matching the substring s[i:i+w] and
  b) dp[i+w] is true
where dp[i] means there exists a valid path to s[i] using some combination of
words from wordDict
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
using LL = long long;
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
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();

    vector<char> dp(n + 1, 0);
    dp[n] = 1;

    for (int i{n - 1}; i >= 0; --i) {
      for (auto &w : wordDict) {
        if (w.size() > n - i)
          continue;
        if (s.compare(i, w.size(), w))
          continue;
        else if (dp[i + w.size()]) {
          dp[i] = dp[i + w.size()];
          break;
        }
      }
    }

    return dp[0];
  }
};
