#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
 
#define FOR(i,a,b) for (int i = a; i < b; i++)
 
 
void solution() {
    int n; string s;
    cin >> n >> s;
    int c = 0;
    for (char ch : s) if (ch == '1') c++;
    int left = n - c, ans = 0;
    FOR(i, 0, left) if (s[i] == '1') ans++;
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
