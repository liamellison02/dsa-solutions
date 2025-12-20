#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        bool blue_centered = ((n - b) % 2 == 0);
        bool ok = blue_centered && (a <= b || ((n - a) % 2 == 0));
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
