/*
platform: lc
id: 846
name: hand of straights
pattern: greedy
tags: greedy,sorting,hashing
complexity:
- time = O(n*logn)
- space = O(n)
notes: sort hand, then form groups using greedy selection from freq map
*/

#include <algorithm>
#include <cmath>
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
using UMII = unordered_map<int, int>;
using MII = map<int, int>;

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    int N = hand.size();
    if (N % groupSize > 0)
      return false;

    sort(hand.begin(), hand.end());

    unordered_map<int, int> frq;
    for (int n : hand)
      ++frq[n];

    for (int i{}; i < N; ++i) {
      int start{hand[i]};
      auto it0 = frq.find(start);

      if (it0 == frq.end())
        continue;

      int cnt{it0->second};
      for (int k{}; k < groupSize; ++k) {
        int v{start + k};
        auto it = frq.find(v);
        if (it == frq.end() || it->second < cnt)
          return false;
        it->second -= cnt;
        if (it->second == 0)
          frq.erase(it);
      }
    }

    return true;
  }
};
