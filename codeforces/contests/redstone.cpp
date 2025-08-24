#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        unordered_set<int> seen;
        bool ok = false;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            if (seen.count(x)) ok = true;
            seen.insert(x);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
