/*
platform: cf
id: 32B
name: borze
url: https://codeforces.com/problemset/problem/32/B
pattern: strings
tags: string,decoding
complexity:
- time = O(n)
- space = O(n)
notes: decode ternary from morse-like encoding
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> out = {};
    char a, b;

    while (cin >> a) {
        if (a=='.') {
            out.push_back(0);
            continue;
        }
        if (!(cin >> b)) break;
        (b == '.') ? out.push_back(1) : out.push_back(2);
    }

    for (int i : out) cout << i;
    return 0;
}
