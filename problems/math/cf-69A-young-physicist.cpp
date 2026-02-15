/*
platform: cf
id: 69A
name: young-physicist
url: https://codeforces.com/problemset/problem/69/A
pattern: math
tags: math,vectors
complexity:
- time = O(n)
- space = O(1)
notes: check if force vectors sum to zero
*/

#include <iostream>
using namespace std;

int main() {
    int n, x = 0, y = 0, z = 0, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }

    (x == 0 && y == 0 && z == 0) ? cout << "YES" : cout << "NO";
    return 0;
}
