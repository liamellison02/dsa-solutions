#include <string>
#include <iostream>

using namespace std;

int main() {
    int n, t;
    string q;
    cin >> n >> t >> q;

    while (t--) {
        for (int i = 0; i+1 < n; i++) {
            if (q[i] == 'B' && q[i+1] == 'G') {
                swap(q[i], q[i+1]);
                i++;
            }
        }
    }

    cout << q << '\n';
    return 0;
}
