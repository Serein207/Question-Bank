#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define N 100007

int f[N], num[N], n;

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int p[N], p_num;
bool is_p[N];

void prime_init() {
    memset(is_p, 1, sizeof(is_p));
    for (int i = 2; i < N; i++) {
        if (is_p[i]) p[p_num++] = i;
        for (int j = 0; j < p_num; j++) {
            if (i * p[j] >= N) break;
            is_p[i * p[j]] = 0;
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
    prime_init();
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            f[i] = i, num[i] = 1;
        }

        for (int i = 1, j; i <= n; i++) {
            scanf("%d", &j);
            int fi = find(i), fj = find(j);
            if (fi == fj) {
                continue;
            }
            if (num[fi] > num[fj]) {
                swap(fi, fj);
            }
            f[fi] = fj, num[fj] += num[fi];
        }

        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int fi = find(i);
            if (fi != i) continue;
            int x = num[fi];
            for (int i = 0; i < p_num && p[i] * p[i] <= x; i++) {
                int num = 0;
                while (x % p[i] == 0) {
                    x /= p[i];
                    num++;
                }
                if (num > 0) {
                    mp[p[i]] = max(mp[p[i]], num);
                }
            }
            if (x > 1) {
                mp[x] = max(mp[x], 1);
            }
        }

        ll ans = 1;
        for (auto &it : mp) {
            int num = it.second;
            while (num--) {
                ans = ans * it.first % MOD;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
