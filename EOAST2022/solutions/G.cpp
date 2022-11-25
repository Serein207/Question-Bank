#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
#define N 1000001
int arr_x[N];
int arr_y[N];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr_x[i], &arr_y[i]);
    }

    vector<int64> ans(n, LONG_LONG_MAX);

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            vector<int64> vec;
            for (int i = 0; i < n; i++) {
                int64 dx = abs(arr_x[x] - arr_x[i]);
                int64 dy = abs(arr_y[y] - arr_y[i]);
                vec.push_back(dx + dy);
            }
            sort(vec.begin(), vec.end());
            for (int i = 0; i < n; i++) {
                if (i > 0) vec[i] += vec[i - 1];
                ans[i] = min(ans[i], vec[i]);
            }
        }
    }
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x - 1]);
    }
    return 0;
}