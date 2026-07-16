/*
platform: lc
id: 1889
name: minimum space wasted from packaging
difficulty: hard
url: https://leetcode.com/problems/minimum-space-wasted-from-packaging/
pattern: binary_search/on_array
tags: binary-search,sorting
complexity:
n = len(pkgs), m = sum(len(boxes[i])
- time = O(nlogn + mlogm + mlogn)
- space = O(1)
notes:
waste = sum(box_sz * pkgs_it_clears) - total_pkg_volume
1. sort pkgs
2. for each supplier, sort the boxes
3. keep running total of box volume, and for each box:
    - bin search on pkgs to find how many boxes it clears
    - add numboxescleared * box_volume to running total
4. wasted space for supplier i = total_pkg_volume - running_total
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

constexpr int MOD = 1e9 + 7;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define rrep(i, n) for (int i{(n) - 1}; i >= 0; --i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using str = string;

using ll = long long;
using ull = unsigned long long;
using ui8 = uint8_t;
using ui16 = uint16_t;
using ui32 = uint32_t;
using ui64 = uint64_t;

using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ti = tuple<int, int, int>;
using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vpi = vector<pi>;
using vti = vector<ti>;
using vvc = vector<vc>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvs = vector<vs>;
using vvpi = vector<vpi>;

using si = set<int>;
using usi = unordered_set<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;

template <typename T> using vec = vector<T>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename K, typename V> using umap = unordered_map<K, V>;

class Solution {
public:
    int minWastedSpace(vector<int>& pkgs, vector<vector<int>>& boxes) {
        sort(pkgs.begin(), pkgs.end());
        int n = pkgs.size();

        ll res {LLONG_MAX}, tot {0};
        for (auto pkg : pkgs) tot += pkg;

        for (auto& supply : boxes) {
            sort(supply.begin(), supply.end());
            if (supply[supply.size()-1] < pkgs[n-1]) continue;

            ll running{0};
            auto last{pkgs.begin()};

            for (auto& box : supply) {
                auto j = upper_bound(last, pkgs.end(), box);
                if (j == last) continue;
                running += (ll)(box * (j - last));
                last = j;
                if (last == pkgs.end()) break;
            }
            res = min(running - tot, res);
        }

        return res < LLONG_MAX ? (res % MOD) : -1;
    }
};
