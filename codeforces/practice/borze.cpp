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
