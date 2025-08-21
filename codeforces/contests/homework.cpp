#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        string a, b, c;
        cin >> n >> a >> m >> b >> c;

        deque<char> dq(a.begin(), a.end());
        for (int i = 0; i < m; ++i) {
            if (c[i] == 'V') dq.push_front(b[i]);
            else dq.push_back(b[i]);
        }

        string res(dq.begin(), dq.end());
        cout << res << '\n';
    }
    return 0;
}
