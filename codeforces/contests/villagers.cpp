#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        vll g(n);
        for (auto &x : g) cin >> x;

        sort(g.begin(), g.end(), greater<ll>());
        ll ans = 0;
        for (int i=0; i < n; i+=2) ans += g[i];
        cout << ans << '\n';
    }
    return 0;
}
