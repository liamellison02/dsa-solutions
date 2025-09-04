#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a = "", b = "";
    int t, teamA = 0, teamB = 0;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        if (a == n) teamA++;
        else if (b == n) teamB++;
        else {
            if (a == "") { a = n; teamA++; }
            else { b = n; teamB++; }
        }
    }
    cout << ((teamA > teamB) ? a : b) << '\n';
    return 0;
}
