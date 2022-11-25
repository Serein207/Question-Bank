#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

#define popcount __builtin_popcountll

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int64 l, r;
        scanf("%lld%lld", &l, &r);
        int64 xl = l + (l & 1);
        int64 xr = r - !(r & 1);
        int64 num = (xr - xl + 1) / 2;
        if (l < xl && popcount(l) & 1) {
            num++;
        }
        if (xr < r && popcount(r) & 1) {
            num++;
        }
        printf("%lld\n", num);
    }
    return 0;
}