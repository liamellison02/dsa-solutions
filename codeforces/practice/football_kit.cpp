#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef vector<int> vi;
typedef unordered_map<int, int> hmii;

void solution() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    hmii home;
    vi x(n),y(n);

    FOR(i,0,n) {
        cin >> x[i] >> y[i];
        home[x[i]]++;
    }
    
    FOR(i,0,n) {
        int conflict = home[y[i]];
        cout << (n-1+conflict) << ' ' << (n-1-conflict) << '\n';
    }

    return 0;
}
