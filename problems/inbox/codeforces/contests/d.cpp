#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef unsigned int uint;

void solution() {
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    FOR(i, 1, n + 1) cin >> a[i];

    vi L(n + 1), R(n + 1), st;

    st.clear();
    FOR(i, 1, n + 1) {
        while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
        L[i] = st.empty() ? 0 : st.back();
        st.push_back(i);
    }

    st.clear();
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && a[st.back()] > a[i]) st.pop_back();
        R[i] = st.empty() ? n + 1 : st.back();
        st.push_back(i);
    }

    vvi bucket(n + 1);
    FOR(i, 1, n + 1) if (L[i] > 0) bucket[L[i]].push_back(R[i]);

    vi best(n + 2, n + 1);
    int curr_min = n + 1;
    for (int l = n; l >= 1; --l) {
        for (int v : bucket[l]) curr_min = min(curr_min, v);
        best[l] = curr_min;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (best[l] <= r ? "NO\n" : "YES\n");
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
