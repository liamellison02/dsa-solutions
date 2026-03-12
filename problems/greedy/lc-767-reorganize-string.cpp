/*
platform: lc
id: 767
name: reorganize string
pattern: greedy
tags: greedy,priority-queue,maxheap,heap,string,frequency,counting
complexity:
- time = O(n)
- space = O(26) = O(1)
notes:
use pq to greedily place the two most frequent chars in the res str
if any char frequency > N+1/2 -> return ""
if you run out of chars/only have one left, valid string
*/

#include <cstdint>
#include <map>
#include <queue>
#include <set>
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
  string reorganizeString(string s) {
    int n = s.size();
    int mx_cnt{(n + 1) / 2};

    int freq[26] = {0};
    for (char c : s)
      ++freq[c - 'a'];

    pq<pair<int, char>> heap;
    rep(i, 26) {
      if (freq[i])
        heap.push({freq[i], i + 'a'});
      if (freq[i] > mx_cnt)
        return "";
    }

    str res;
    while (heap.size() >= 2) {
      auto [odd_freq, odd_ch] = heap.top();
      heap.pop();
      auto [even_freq, even_ch] = heap.top();
      heap.pop();

      res += odd_ch;
      res += even_ch;
      --odd_freq;
      --even_freq;

      if (odd_freq)
        heap.emplace(odd_freq, odd_ch);
      if (even_freq)
        heap.emplace(even_freq, even_ch);
    }

    if (!heap.empty())
      res += heap.top().second;

    return res;
  }
};
