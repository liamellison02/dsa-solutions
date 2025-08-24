#include <iostream>
#include <vector>
#include <algorithm>
typedef vector<int> vi;
using namespace std;

static inline int ask(int x, const vi& S) {
    cout << "? " << x << " " << (int)S.size();
    for (int v : S) cout << " " << v;
    cout << endl;
    int ans;
    if (!(cin >> ans)) exit(0);
    if (ans == -1) exit(0);
    return ans;
}

static inline void answer_path(const vi& path) {
    cout << "! " << (int)path.size();
    for (int v : path) cout << " " << v;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        if (!(cin >> n)) return 0;

        vi all(n);
        for (int i = 0; i < n; ++i) all[i] = i + 1;

        vi dp(n + 1, 1);
        for (int u = 1; u <= n; ++u) {
            dp[u] = ask(u, all);
        }

        int L = 1, start = 1;
        for (int u = 1; u <= n; ++u) {
            if (dp[u] > L) { L = dp[u]; start = u; }
        }
        vi B(L + 1);
        for (int u = 1; u <= n; ++u) B[dp[u]].push_back(u);

        vi path;
        path.reserve(L);
        int cur = start;
        path.push_back(cur);

        for (int d = L - 1; d >= 1; --d) {
            int nextv = -1;
            for (int v : B[d]) {
                vi S; S.reserve(2);
                S.push_back(cur);
                S.push_back(v);
                int res = ask(cur, S);
                if (res == 2) { 
                    nextv = v;
                    break;
                }
            }
            if (nextv == -1) {
                exit(0);
            }
            path.push_back(nextv);
            cur = nextv;
        }

        answer_path(path);
    }

    return 0;
}
