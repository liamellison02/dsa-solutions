/*
platform: lc
id: 961
name: n repeated element in size 2n array
pattern: arrays/hashing
tags: hashing,frequencies
complexity:
- time = O(n)
- space = O(n)
notes: trick is to recognize that you only need to return the element that
occurs twice
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
using UMII = unordered_map<int, int>;

class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {
    int n = nums.size() / 2;
    UMII f;

    for (int i : nums) {
      ++f[i];
      if (f[i] > 1)
        return i;
    }

    for (auto &p : f)
      if (p.second == n)
        return p.first;

    return 0;
  }
};
