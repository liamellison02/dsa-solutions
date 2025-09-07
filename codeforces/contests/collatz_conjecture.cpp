#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef long long ll;

void solution() {
    int k, x;
    cin >> k >> x;
    cout << ( (ll)x << k ) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();

    return 0;
}