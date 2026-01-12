#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define pb(e) push_back(e)

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vi out; out.reserve(n);
    for (int x = k + 1; x >= 1; --x) out.pb(x);
    for (int x = k + 2; x <= n; ++x) out.pb(x);

    FOR(i,0,n) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << '\n';
    return 0;
}
