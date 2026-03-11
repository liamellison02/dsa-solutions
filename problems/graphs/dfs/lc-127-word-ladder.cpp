/*
platform: lc
id: 127
name: word ladder
pattern: graphs/dfs
tags: string,bfs,hashtable,hashmap
complexity:
m = wordList.length
n = endWord.length = beginWord.length = wordList[i].length
- time = O(m * n)
- space = O(m * n)

notes:
BFS to find shortest possible sequence of transformations.
approach:
1) map each word to it's wildcard candidates.
for e.g. the word "cat" has wildcard candidates:
- "*at"
- "c*t"
- "ca*"
we also will store the reverse mapping of all
possible wildcards (reachable vertices in the graph)
to their associated word in wordList.
2) after building these adjacency mappings for all
reachable wildcards & wildcard candidates in each word,
we perform BFS level search using a queue to find the
shortest sequence in this loop.

edge cases / other notes:
- if endWord not in wordList: return False
- use visited set to avoid reprocessing stale/invalid entries.
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
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    bool fnd{false};
    for (auto &w : wordList)
      if (w == endWord)
        fnd = true;
    if (!fnd)
      return false;

    int m = endWord.size(), n = wordList.size();

    unordered_map<string, vector<string>>
        word_adj; // word in wordList -> all possible wcs
    unordered_map<string, vector<string>> wc_adj; // wc -> word in wordList

    for (int i{0}; i < n; ++i) {
      auto word = wordList[i];
      for (int c{0}; c < m; ++c) {
        auto wc = word;
        wc[c] = '*';
        wc_adj[wc].push_back(word);
        word_adj[word].push_back(wc);
      }
    }

    // BFS
    queue<pair<string, int>> bfs;
    for (int c{0}; c < m; ++c) {
      auto wc = beginWord;
      wc[c] = '*';
      wc_adj[wc].push_back(beginWord);
      word_adj[beginWord].push_back(wc);
    }
    bfs.emplace(beginWord, 0);

    unordered_set<string> visited;
    visited.insert(beginWord);

    while (!bfs.empty()) {
      auto [word, i] = bfs.front();
      bfs.pop();

      if (word == endWord)
        return i + 1;

      visited.insert(word);

      for (auto &wc : word_adj[word]) {
        for (auto &nxt : wc_adj[wc]) {
          if (nxt == word || visited.count(nxt))
            continue;
          bfs.emplace(nxt, i + 1);
          visited.insert(nxt);
        }
        wc_adj[wc].clear();
      }
    }

    return 0;
  }
};
