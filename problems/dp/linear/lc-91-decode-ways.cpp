/*
platform: lc
id: 91
name: decode ways
pattern: dp/linear
tags: dp,string
complexity:
- time = O(n)
- space = O(1)
notes: rolling dp using p1/p2 for prev decode counts; check 1-digit + valid
2-digit combos
*/

#include <algorithm>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
using VPI = vector<PI>;
using VTI = vector<TI>;

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0')
      return 0;

    int p1 = 1, p2 = 1;

    for (int i = 1; i < n; ++i) {
      int curr = 0;

      if (s[i] != '0')
        curr += p1;

      int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
      if (two >= 10 && two <= 26)
        curr += p2;

      p2 = p1;
      p1 = curr;

      if (curr == 0)
        return 0;
    }

    return p1;
  }
};
