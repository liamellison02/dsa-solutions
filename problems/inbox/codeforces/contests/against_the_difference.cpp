#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vi a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vvi pos(n + 1);
        for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);

        vector<vector<pair<int,int>>> end_at(n + 1);
        for (int v = 1; v <= n; ++v) {
            const auto &p = pos[v];
            int c = (int)p.size();
            if (c >= v) {
                for (int j = v - 1; j < c; ++j) {
                    int L = p[j - v + 1];
                    int R = p[j];
                    end_at[R].push_back({L, v});
                }
            }
        }

        vi dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int best = dp[i - 1];
            for (auto &iv : end_at[i]) {
                int L = iv.first, w = iv.second;
                if (dp[L - 1] + w > best) best = dp[L - 1] + w;
            }
            dp[i] = best;
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
