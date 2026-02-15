/*
platform: cf
id: 281A
name: word-capitalization
url: https://codeforces.com/problemset/problem/281/A
pattern: strings
tags: string,case-conversion
complexity:
- time = O(n)
- space = O(1)
notes: capitalize first letter
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int c = s[0];
    if (c > 96 && c < 123) c -= 32;

    s[0] = (char)c;
    cout << s;

    return 0;
}
