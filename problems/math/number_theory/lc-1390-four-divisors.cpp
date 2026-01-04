/*
platform: lc
id: 1390
name: four divisors
pattern: math/number_theory
tags: math,number-theory,factorization,primes
complexity:
m = max(nums)
- time = O(n * sqrt(m))
- space = O(1)
notes: sum divisors up to 4 w/ early exiting on divisor calculation
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

class Solution {
  int dsum(int n) {
    int res{0}, cnt{0}, rt = sqrt(n);

    for (int i{1}; i <= rt; ++i) {
      if (n % i == 0) {
        res += (i + n / i);
        cnt += 2;
      }
      if (cnt > 5)
        return 0;
    }

    if (rt * rt == n)
      --cnt;
    return cnt == 4 ? res : 0;
  }

public:
  int sumFourDivisors(vector<int> &nums) {
    int res{0};
    for (int num : nums)
      res += dsum(num);
    return res;
  }
};
