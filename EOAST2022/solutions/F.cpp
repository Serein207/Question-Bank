#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
#define N 100001
int64 arr[N];
int n;

bool check(int64 x) {
    int64 sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < x) {
            sum += x - arr[i];
        }
    }
    return sum <= x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int64 sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }
        int64 left = 0, right = sum / (n - 1) + 1;
        while (left < right) {
            int64 mid = (left + right) >> 1;
            if (check(mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        printf("%lld\n", left - 1);
    }
    return 0;
}
