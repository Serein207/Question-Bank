#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
#define MOD 1000000007
#define N 501

int arr[N];
int64 dp0[N][N];  // (...)
int64 dp1[N][N];  // (...)(...)
int64 dp(int i, int j) {
    return (dp0[i][j] + dp1[i][j]) % MOD;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            if (i < n) {
                dp0[i + 1][i] = 1;
            }
            for (int j = i + 1; j <= n; j += 2) {
                dp0[i][j] = dp1[i][j] = 0;
            }
        }
        for (int i = n; i > 0; i--) {
            for (int j = i + 1; j <= n; j += 2) {
                if (arr[i] == 0 && arr[j] == 0) {
                    dp0[i][j] = dp(i + 1, j - 1) * m % MOD;
                } else if (arr[i] == 0 || arr[j] == 0) {
                    if (arr[i] > 0 || arr[j] < 0) {
                        dp0[i][j] = dp(i + 1, j - 1);
                    }
                } else if (arr[i] == -arr[j] && arr[i] > 0) {
                    dp0[i][j] = dp(i + 1, j - 1);
                }

                for (int k = i + 1; k < j; k += 2) {
                    int temp = dp0[i][k] * dp(k + 1, j) % MOD;
                    dp1[i][j] = (dp1[i][j] + temp) % MOD;
                }
            }
        }
        printf("%lld\n", dp(1, n));
    }
    return 0;
}
