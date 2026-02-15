/*
platform: cf
id: 271A
name: beautiful-year
url: https://codeforces.com/problemset/problem/271/A
pattern: math
tags: math,digits
complexity:
- time = O(k) where k is years checked
- space = O(1)
notes: find next year with all distinct digits
*/

#include <iostream>
using namespace std;

int main() {
    int y;
    cin >> y;
    for (int x = y + 1; ; ++x) {
        int a = x / 1000, b = (x / 100) % 10, c = (x / 10) % 10, d = x % 10;
        if (a != b && a != c && a != d && b != c && b != d && c != d) {
            cout << x << '\n';
            break;
        }
    }
}
