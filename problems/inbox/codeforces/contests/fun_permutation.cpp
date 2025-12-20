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
    int n;
    cin >> n;
    vi p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vi q(n);
    for (int i = 0; i < n; ++i) q[i] = (n + 1) - p[i];

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << q[i];
    }

    cout << '\n'; 
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();

    return 0;
}
