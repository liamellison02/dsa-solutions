#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        ll ans = 0;
        ll total_add = 0;
        ll max_prev2 = 0;
        ll prevY = 0;
        bool have_prevY = false;

        ll pref = 0;
        for (int r = 1; r <= n; ++r) {
            ll s = ( (r % 2 == 0) ? a[r] : -a[r] );
            pref += s;

            ll Yr = pref + total_add;

            if (r >= 2 && Yr < max_prev2) {
                ll delta = max_prev2 - Yr;
                ans += delta;
                total_add += delta;
                Yr += delta;
                if (r % 2 == 0) {
                    if (have_prevY) prevY += delta;
                }
            }

            if (r - 1 >= 1 && have_prevY) {
                if (prevY > max_prev2) max_prev2 = prevY;
            }

            prevY = Yr;
            have_prevY = true;
        }

        cout << ans << "\n";
    }
    return 0;
}
