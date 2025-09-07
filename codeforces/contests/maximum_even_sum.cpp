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
    ll a, b;
    if (!(cin >> a >> b)) return;

    ll tmp = b;
    int t = 0;
    while ((tmp & 1LL) == 0) { tmp >>= 1; ++t; }
    ll m = tmp;

    ll ans = -1;

    {
        ll s = a + b;
        if ((s & 1LL) == 0) ans = max(ans, s);
    }

    if (t == 0) {
        ll s = a * b + 1;
        if ((s & 1LL) == 0) ans = max(ans, s);
    }

    if (t >= 2) {
        ll s = a * (b / 2) + 2;
        if ((s & 1LL) == 0) ans = max(ans, s);
    }

    if (t >= 1 && (a % 2 == 0)) {
        ll pow2 = (1ULL << t);
        ll s = a * m + pow2;
        if ((s & 1LL) == 0) ans = max(ans, s);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
