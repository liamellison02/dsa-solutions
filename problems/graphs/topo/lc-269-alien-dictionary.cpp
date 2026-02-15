/*
platform: lc
id: 269
name: alien dictionary
difficulty: hard
url: https://leetcode.com/problems/alien-dictionary/
pattern: graphs/topo
tags: topological,queue,cycle
complexity:
L = # of unique chars in words
- time = O(L + 26^2) = O(L)
- space = O(26^2) = O(1)
notes: topological sorting w/ edges denoting lexicographical order of chars
*/

#include <deque>
#include <tuple>
#include <vector>

using namespace std;
using TI = tuple<int, int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;

class Solution {
public:
  string alienOrder(vector<string> &words) {
    int n = words.size();

    VC present(26, 0);
    VVC edge(26, VC(26, 0));
    VI ind(26, 0);
    VVI adj(26);

    for (auto &w : words)
      for (char c : w)
        present[c - 'a'] = 1;

    for (int i{}; i < n - 1; ++i) {
      auto &w = words[i];
      auto &nw = words[i + 1];

      int m = min(w.size(), nw.size());
      int c = 0;

      while (c < m && w[c] == nw[c])
        ++c;

      if (c == m && w.size() > nw.size())
        return "";

      if (c < m) {
        int c1 = w[c] - 'a', c2 = nw[c] - 'a';
        if (!edge[c1][c2]) {
          edge[c1][c2] = 1;
          adj[c1].push_back(c2);
          ++ind[c2];
        }
      }
    }

    deque<int> q;
    int needed{};
    for (int i{}; i < 26; ++i) {
      if (present[i]) {
        ++needed;
        if (ind[i] == 0)
          q.push_back(i);
      }
    }

    string res{};
    while (!q.empty()) {
      int i = q.front();
      q.pop_front();
      res.push_back('a' + i);
      for (int nei : adj[i])
        if (--ind[nei] == 0)
          q.push_back(nei);
    }

    return res.size() == needed ? res : "";
  }
};
