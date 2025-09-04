#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,a,b;
    cin >> n >> m >> a >> b;

    if (b < m * a) cout << (n / m) * b + min((n % m) * a, b) << '\n';
    else cout << (n * a) << '\n';

    return 0;
}
