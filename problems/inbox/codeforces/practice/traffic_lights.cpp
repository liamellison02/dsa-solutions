#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef double db;

int main() {
    int l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;
 
    int cycle = r + g;
    db rem = l - d;
    db t = d / (db) v;
    db curr = fmod(t, cycle);
 
    if (curr >= g) {
        db wait = cycle - curr;
        t += wait;
    }
 
    t += rem / (db) v;
    cout << fixed << setprecision(10) << t << "\n";

    return 0;
}
