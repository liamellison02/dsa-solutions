/*
platform: lc
id: 3798
name: largest even number
difficulty: easy
url: https://leetcode.com/problems/largest-even-number/
pattern: greedy
tags: greedy,string,bit
complexity:
- time = O(n)
- space = O(1)
notes: just find rightmost 2 and truncate suffix
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
  string largestEven(string s) {
    int p{-1};
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '2') {
        p = i;
        break;
      }
    }
    if (p == -1)
      return "";
    s.erase(p + 1);
    return s;
  }
};
