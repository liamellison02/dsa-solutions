/*
platform: lc
id: 358
name: rearrange string k distance apart
pattern: heap
tags: greedy,priority-queue,frequency,string,queue
complexity:
- time = O(nlogn)
- space = O(k)
notes:
calculate char freqs and then populate heap by ch frq and greedily place
chars in str while maintaining a cooldown queue for distancing.
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
  string rearrangeString(string s, int k) {
    if (k == 0)
      return s;

    int n = s.size();
    int frq[26];
    for (auto &c : s)
      ++frq[c - 'a'];

    pq<PI> heap;
    rep(i, 26) if (frq[i]) heap.emplace(frq[i], i);
    queue<PI> cool;

    rep(i, n) {
      if (cool.size() >= k) {
        auto [a, b] = cool.front();
        cool.pop();
        if (a > 0)
          heap.emplace(a, b);
      }

      if (heap.empty())
        return "";

      auto [f, c] = heap.top();
      heap.pop();
      cool.emplace(f - 1, c);
      s[i] = c + 'a';
    }

    return s;
  }
};
