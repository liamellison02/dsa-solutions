/*
platform: cf
id: 59A
name: word
pattern: strings
tags: strings,case-conversion
complexity:
- time = O(n)
- space = O(1)
notes: convert to case with more characters
*/

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int upper = 0, lower = 0;
    for (char c : s) {
        if (isupper(c)) upper++;
        else lower++;
    }
    if (upper > lower) {
        for (char &c : s) c = toupper(c);
    } else {
        for (char &c : s) c = tolower(c);
    }
    cout << s;
    return 0;
}
