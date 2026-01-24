/*
platform: cf
id: 58A
name: chat-room
pattern: strings
tags: strings,subsequence
complexity:
- time = O(n)
- space = O(1)
notes: check if "hello" is a subsequence
*/

#include <iostream>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string in, h = "hello";
    cin >> in;

    int c = 0;
    FOR(i, 0, in.size()) {
        if (in[i] == h[c]) c++;
        if (c > 4) { cout << "YES" << "\n"; return 0; }
    }

    cout << "NO" << "\n";
    return 0;
}
