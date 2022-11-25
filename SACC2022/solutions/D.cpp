#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100001

ll f[N];
int n, m;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1, w, v; i <= n; i++) {
            scanf("%d%d", &w, &v);
            for (int j = N - 1; j >= v; j--) {
                f[j] = min(f[j], f[j - v] + w);
            }
        }
        int add = N - 1;
        while (f[add] > m) add--;
        printf("%d\n", add);
    }
    return 0;
}