/*
platform: lc
id: 3699
name: number of zigzag arrays I
difficulty: hard
url: https://leetcode.com/problems/number-of-zigzag-arrays-i/
pattern: dp/state_machine
tags: dp,state-machine,prefix-sum,counting
complexity:
m = r - l + 1
- time = O(n * m)
- space = O(m)
notes:
state machine dp

dp[i][j]:
"num of arrays going in direction i ending with j"
- i = 0 -> decreasing
- i = 1 -> increasing

*/

constexpr int MOD = 1e9 + 7;

#define rep(i, n) for (int i{0}; i < (n); ++i)
#define FOR(i, a, b) for (int i{(a)}; i < (b); ++i)

using ll = long long;
using vi = vector<int>;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m {r-l+1};

        vi dp0(m, 0), dp1(m, 0);
        vi sum0(m+1, 0), sum1(m+1, 0);

        rep(j, m) {
            dp0[j] = m-j-1;
            dp1[j] = j;
        }

        // walk up each layer from 2...n
        FOR(i, 2, n) {
            // populate prefix sums for this layer
            rep(j, m) {
                sum0[j+1] = (sum0[j] + dp0[j]) % MOD; // running sum up to j (inclusive)
                sum1[j+1] = (sum1[j] + dp1[j]) % MOD; // running sum up to j (inclusive)
            }

            // transition to next state for all j
            rep(j, m) {
                dp0[j] = (sum1[m] - sum1[j+1] + MOD) % MOD; // decreasing into j = curr prefix sums from j+1...m-1
                dp1[j] = sum0[j]; // increasing into j = curr prefix sums from 0...j-1
            }
        }


        int res{0};
        rep(j,m) res = ((ll)res + dp0[j] + dp1[j]) % MOD;

        return res;
    }
};
