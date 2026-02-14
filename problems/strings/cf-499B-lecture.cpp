/*
platform: cf
id: 499B
name: lecture
pattern: strings
tags: string,hashing
complexity:
- time = O(n + m)
- space = O(m)
notes: translate words to shorter form
*/

#include <iostream>
#include <unordered_map>
using namespace std;
typedef unordered_map<string, string> hmss;
typedef unordered_map<string, int> hmsi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    hmss mp;
    int n, m;
    cin >> n >> m;
    while (m--) {
        string a,b;
        cin >> a >> b;
        (a.size() <= b.size()) ? mp[a]=a, mp[b]=a : mp[a]=b, mp[b]=b;
    }
    while (n--) {
        string w;
        cin >> w;
        cout << mp[w] << (n == 0 ? '\n' : ' ');
    }
}
