#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;

void solution() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return;
    vvi radj(n + 1);
    vi outdeg(n + 1, 0);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        radj[v].push_back(u);
        outdeg[u]++;
    }
    vector<char> red(n + 1, 0), w0(n + 1, 1), w1(n + 1, 1);
    vi cnt_true(n + 1), cnt_false(n + 1);
    FOR(i, 1, n + 1) {
        cnt_true[i] = outdeg[i];
        cnt_false[i] = 0;
    }
    vi qv;
    qv.reserve(n * 2);
    auto push_state = [&](int v, int p){ qv.push_back((v<<1)|p); };
    FOR(i, 0, q) {
        int t, u;
        cin >> t >> u;
        if (t == 1) {
            if (red[u]) continue;
            red[u] = 1;
            qv.clear();
            if (w0[u]) { w0[u] = 0; push_state(u,0); }
            if (w1[u]) { w1[u] = 0; push_state(u,1); }
            int head = 0;
            while (head < (int)qv.size()) {
                int s = qv[head++], v = s >> 1, p = s & 1;
                if (p == 1) {
                    for (int pr : radj[v]) {
                        if (cnt_true[pr] > 0) {
                            --cnt_true[pr];
                            if (cnt_true[pr] == 0 && w0[pr]) {
                                w0[pr] = 0;
                                push_state(pr,0);
                            }
                        }
                    }
                } else {
                    for (int pr : radj[v]) {
                        ++cnt_false[pr];
                        if (cnt_false[pr] == 1 && w1[pr]) {
                            w1[pr] = 0;
                            push_state(pr,1);
                        }
                    }
                }
            }
        } else {
            cout << (w0[u] ? "YES\n" : "NO\n");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
