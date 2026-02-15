/*
platform: cf
id: 466A
name: cheap-travel
url: https://codeforces.com/problemset/problem/466/A
pattern: greedy
tags: greedy,math
complexity:
- time = O(1)
- space = O(1)
notes: compare single vs multi-ride ticket cost
*/

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
