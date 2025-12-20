#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

void solution() {
    int n;
    if (!(cin >> n)) return;
    vi b(n);
    FOR(i, 0, n) cin >> b[i];

    vvi pos(n + 1);
    FOR(i, 0, n) {
        int k = b[i];
        pos[k].push_back(i);
    }

    vi a(n, 0);
    int label = 1;

    for (int k = 1; k <= n; ++k) {
        int cnt = (int)pos[k].size();
        if (cnt % k != 0) {
            cout << -1 << '\n';
            return;
        }
        for (int i = 0; i < cnt; ) {
            for (int t = 0; t < k; ++t, ++i) {
                a[pos[k][i]] = label;
            }
            ++label;
        }
    }

    FOR(i, 0, n) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
