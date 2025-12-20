#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    const ll ONE = 1000000000LL;
    const ll A = 2 * ONE;

    auto ask = [&](char d, ll k) -> ll {
        cout << "? " << d << " " << k << '\n' << flush;
        ll s;
        if (!(cin >> s)) exit(0);
        if (s == -1) exit(0);
        return s;
    };

    while (t--) {
        int n; cin >> n;
        vll xs(n), ys(n);
        for (int i = 0; i < n; i++) cin >> xs[i] >> ys[i];

        ll M = LLONG_MIN, m = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            M = max(M, xs[i] + ys[i]);
            m = min(m, xs[i] - ys[i]);
        }

        ask('R', ONE);
        ask('R', ONE);
        ask('U', ONE);
        ll sNE = ask('U', ONE);

        ask('L', ONE);
        ask('L', ONE);
        ask('L', ONE);
        ll sNW = ask('L', ONE);

        ll sum = sNE - 2*A + M;
        ll diff = 2*A + m - sNW;
        ll X = (sum + diff) / 2;
        ll Y = (sum - diff) / 2;

        cout << "! " << X << " " << Y << '\n' << flush;
    }
}
