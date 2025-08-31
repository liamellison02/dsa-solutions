#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        auto ok = [&](int x, int y) {
            int M = x > y ? x : y;
            int m = x + y - M;
            int r = (M + 1) / 2;
            if (m < r - 1) return false;
            if (m > 2 * (r + 1)) return false;
            return true;
        };
        int x1 = a, y1 = b;
        int x2 = c - a, y2 = d - b;
        cout << ((ok(x1, y1) && ok(x2, y2)) ? "YES" : "NO") << '\n';
    }
}
