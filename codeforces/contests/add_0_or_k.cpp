#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll &x : a) cin >> x;

        for (ll &x : a) {
            ll s = x % (k + 1);
            x += s * k;
        }

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
