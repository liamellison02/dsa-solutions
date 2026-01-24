/*
platform: cf
id: 227B
name: effective-approach
pattern: arrays/hashing
tags: arrays,precompute
complexity:
- time = O(n + m)
- space = O(n)
notes: compare left vs right linear search costs
*/

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi pos(n + 1);
    for (int i = 1, x; i <= n; ++i) { cin >> x; pos[x] = i; }

    int m; cin >> m;
    ll vasya = 0, petya = 0;
    for (int i = 0, b; i < m; ++i) {
        cin >> b;
        int p = pos[b];
        vasya += p;
        petya += (n - p + 1);
    }
    cout << vasya << ' ' << petya << '\n';
    return 0;
}
