#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> p(41, 1);
    for (int i = 1; i < 41; ++i) p[i] = p[i - 1] * 3LL;

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll s3 = 0, tmp = n;
        while (tmp) { s3 += tmp % 3; tmp /= 3; }

        if (k < s3) {
            cout << -1 << '\n';
            continue;
        }

        ll base_cost = 3LL * n;
        ll need = 0;
        if (n > k) need = (n - k + 1) / 2;

        ll extra = 0;
        for (int x = 1; need > 0; ++x) {
            if (p[x] > n) break;
            ll available = n / p[x];
            ll take = available < need ? available : need;
            extra += take * p[x - 1];
            need -= take;
        }

        cout << base_cost + extra << '\n';
    }
    return 0;
}
