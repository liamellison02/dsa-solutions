#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ull n;
        cin >> n;

        vector<ull> ans;
        ull p10 = 10;
        for (int k = 1; k <= 18; ++k) {
            ull denom = 1 + p10;
            if (n % denom == 0) {
                ans.push_back(n / denom);
            }
            if (k < 18) p10 *= 10;
        }

        if (ans.empty()) {
            cout << 0 << '\n';
        } else {
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            cout << ans.size() << '\n';
            for (size_t i = 0; i < ans.size(); ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
