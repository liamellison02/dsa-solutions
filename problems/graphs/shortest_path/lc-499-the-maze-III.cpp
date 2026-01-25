/*
platform: lc
id: 499
name: the maze III
pattern: graphs/shortest_path
tags: dijkstras,simulation,heap,minheap,priority-queue,hashtable,hashing,graphs,matrix,strings
complexity:
- time = O(m^2 * n^2 * max(m,n) * log(m*n))
- space = O(m^2 * n^2)
notes:
run dijkstras where pq comparisons are done in order (dist, path_str)
at each position/State, simulate the ball roll in each of the 4 directions,
pushing each stopping State from the 4 directions to the pq.
*/

#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using PIS = pair<int, string>;
using TI = tuple<int, int, int>;
using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using VS = vector<string>;
using VPI = vector<PI>;
using VTI = vector<TI>;
using VVC = vector<VC>;
using VVI = vector<VI>;
using VVS = vector<VS>;
using VVPI = vector<VPI>;
using SI = set<int>;
using USI = unordered_set<int>;
using MII = map<int, int>;
using UMII = unordered_map<int, int>;

using State = tuple<int, string, int, int>;

class Solution {
public:
  string findShortestWay(vector<vector<int>> &maze, vector<int> &ball,
                         vector<int> &hole) {
    int m = maze.size(), n = maze[0].size();
    int dirs[4][3] = {{1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}, {-1, 0, 'u'}};

    auto roll = [&](int r, int c, int rd, int cd) -> TI {
      int delta = 0;
      while (true) {
        int nr = r + rd, nc = c + cd;
        if (nc < 0 || nc >= n || nr < 0 || nr >= m || maze[nr][nc] == 1)
          break;
        ++delta;
        r = nr;
        c = nc;
        if (hole[0] == r && hole[1] == c)
          break;
      }
      return {r, c, delta};
    };

    priority_queue<State, vector<State>, greater<>> pq;
    pq.push({0, "", ball[0], ball[1]});

    map<PI, PIS> best;

    while (!pq.empty()) {
      auto [d, s, r, c] = pq.top();
      pq.pop();

      auto b = best.find({r, c});
      if (b != best.end() && b->second <= pair{d, s})
        continue;
      best[{r, c}] = {d, s};

      if (r == hole[0] && c == hole[1])
        return s;

      for (auto &[dr, dc, dlv] : dirs) {
        auto [sr, sc, sd] = roll(r, c, dr, dc);
        if (sd == 0)
          continue;

        string ns = s + static_cast<char>(dlv);
        auto nb = best.find({sr, sc});

        if (nb == best.end() || pair{d + sd, ns} < nb->second)
          pq.push({d + sd, ns, sr, sc});
      }
    }

    return "impossible";
  }
};
