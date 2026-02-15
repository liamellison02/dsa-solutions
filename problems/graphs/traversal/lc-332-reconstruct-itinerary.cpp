/*
platform: lc
id: 332
name: reconstruct itinerary
difficulty: medium
url: https://leetcode.com/problems/reconstruct-itinerary/
pattern: graphs/traversal
tags: dfs,hierholzer,eulerian-path
complexity:
E = tickets.size(), V=|airports|
- time = O(E * logE)
- space = O(E + V)
notes: eulerian path finding problem (path using all edges once)
*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using VS = vector<string>;

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    unordered_map<string, VS> adj;

    for (VS &t : tickets)
      adj[t[0]].push_back(t[1]);
    for (auto &[src, dest] : adj)
      sort(dest.rbegin(), dest.rend());

    VS res, stk;

    stk.push_back("JFK");
    while (!stk.empty()) {
      string curr = stk.back();
      if (adj[curr].empty()) {
        res.push_back(curr);
        stk.pop_back();
      } else {
        stk.push_back(adj[curr].back());
        adj[curr].pop_back();
      }
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
