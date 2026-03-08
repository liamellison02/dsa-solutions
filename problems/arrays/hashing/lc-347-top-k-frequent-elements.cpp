/*
platform: lc
id: 347
name: top k frequent elements
pattern: arrays/hashing
tags: bucket-sort,counting,frequency,minheap,heap,hashing,sorting,arrays
complexity:
- time = O(n)
- space = O(n)
notes:
brute force approach:
1) go through array, storing frequencies in hashmap for all numbers
    - O(n) time & space
2) sort hashmap entries into array based on char frequency/count,
highest->lowest.
    - O(nlogn) time + O(n) space (dependent on sorting implementation)
3) returning the first k elements from the array
    - O(k) time

linear-time approach:
bucket-sort using array (buckets) of size n+1 where:
 - idx = element frq in nums
 - buckets[idx] = vector/list of the elements w/ frequency/count=idx
return list of first k elements found in buckets, when iterating in reverese
order

algorithm:
1) populate frequencies into frq hashmap
2) for each num,cnt pair in frq, add num to end of buckets[cnt]
3) iterate in reverse order through buckets and return first k elements found
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
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

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using ll = long long;
using ull = unsigned long long;
using str = string;
using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using Vll = vector<ll>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVll = vector<Vll>;
using VVS = vector<VS>;
using VVPI = vector<VPI>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename K, typename V> using umap = unordered_map<K, V>;

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
  vector<int> topKFrequent(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    for (auto num : nums)
      ++cnt[num];

    vector<vector<int>> buckets(n + 1);
    for (auto &[num, idx] : cnt)
      buckets[idx].push_back(num);

    vector<int> res;
    int i{n};
    while (k > 0 && i >= 0) {
      for (auto num : buckets[i]) {
        res.push_back(num);
        --k;
        if (k == 0)
          return res;
      }
      --i;
    }

    return res;
  }
};
