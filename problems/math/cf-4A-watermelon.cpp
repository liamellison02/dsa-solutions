/*
platform: cf
id: 4A
name: watermelon
url: https://codeforces.com/problemset/problem/4/A
pattern: math
tags: math,divisibility
complexity:
- time = O(1)
- space = O(1)
notes: check if weight can be split into two even parts
*/

#include <iostream>
using namespace std;

int main() {
    int w;
    cin >> w;

    if (w % 2 == 0 && w > 2) cout << "YES";
    else cout << "NO";

    return 0;
}
