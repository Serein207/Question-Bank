#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) {
    return x & (-x);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        puts(lowbit(n) == n ? "Black" : "White");
    }
    return 0;
}
