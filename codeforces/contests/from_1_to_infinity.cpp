#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>
using namespace std;
using u64 = unsigned long long;

static inline u64 sum_digits_to(u64 n) {
    if (n == 0) return 0;
    u64 res = 0;
    for (u64 factor = 1; factor <= n; factor *= 10) {
        u64 higher = n / (factor * 10);
        u64 cur    = (n / factor) % 10;
        u64 lower  = n % factor;
        res += higher * 45ULL * factor;
        res += (cur * (cur - 1) / 2ULL) * factor;
        res += cur * (lower + 1ULL);
    }
    return res;
}

static inline u64 sum_digits_range(u64 a, u64 b) {
    if (a > b) return 0;
    return sum_digits_to(b) - sum_digits_to(a - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    u64 p10[19];
    p10[0] = 1;
    for (int i = 1; i <= 18; ++i) p10[i] = p10[i-1] * 10ULL;

    while (t--) {
        u64 k;
        cin >> k;

        u64 ans = 0;
        u64 remaining = k;

        for (int d = 1; d <= 18; ++d) {
            u64 base = p10[d-1];
            u64 cnt  = 9ULL * p10[d-1];
            u64 lenBlock = (u64)d * cnt;

            if (remaining >= lenBlock) {
                ans += sum_digits_range(base, base + cnt - 1);
                remaining -= lenBlock;
            } else {
                u64 q = remaining / d;
                u64 r = remaining % d;
                if (q > 0) {
                    ans += sum_digits_range(base, base + q - 1);
                }
                if (r > 0) {
                    u64 x = base + q;
                    string s = to_string(x);
                    for (u64 i = 0; i < r && i < s.size(); ++i) ans += (s[i] - '0');
                }
                break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
