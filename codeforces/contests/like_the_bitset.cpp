#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        bool bad = false;
        if (k == 1) {
            for (char c : s) if (c == '1') { bad = true; break; }
        } else {
            int run = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '1') {
                    ++run;
                    if (run >= k) { bad = true; break; }
                } else run = 0;
            }
        }
        if (bad) {
            cout << "NO\n";
            continue;
        }

        vi zeros, ones;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') zeros.push_back(i);
            else ones.push_back(i);
        }

        vi p(n, 0);
        int cur = n;
        for (int idx : zeros) p[idx] = cur--;
        for (int idx : ones)  p[idx] = cur--;

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    }
    return 0;
}
