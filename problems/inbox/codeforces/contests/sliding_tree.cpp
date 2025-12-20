#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vvi g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (n == 1) {
            cout << -1 << "\n";
            continue;
        }

        int leaf_count = 0;
        for (int i = 1; i <= n; i++) if ((int)g[i].size() == 1) leaf_count++;
        if (leaf_count == 2) {
            cout << -1 << "\n";
            continue;
        }

        int a = -1, b = -1, c = -1;
        for (int i = 1; i <= n && b == -1; i++) {
            if ((int)g[i].size() == 1) {
                int nb = g[i][0];
                if ((int)g[nb].size() >= 2) {
                    for (int u : g[nb]) if (u != i) { a = u; b = nb; c = i; break; }
                }
            }
        }

        if (b == -1) {
            cout << -1 << "\n";
        } else {
            cout << a << " " << b << " " << c << "\n";
        }
    }
    return 0;
}
