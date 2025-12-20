#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<ll> p(40, 1);
    for (int i = 1; i < 40; ++i) p[i] = p[i - 1] * 3LL;
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll n;
        cin >> n;
        ll r = n, ans = 0;
        for (int i = 39; i >= 0; --i) {
            if (p[i] > r) continue;
            ll cnt = r / p[i];
            r -= cnt * p[i];
            if (cnt == 0) continue;
            ll cost_i = (i == 0) ? 3LL : (p[i + 1] + (ll)i * p[i - 1]);
            ans += cnt * cost_i;
        }
        cout << ans << '\n';
    }
    return 0;
}
