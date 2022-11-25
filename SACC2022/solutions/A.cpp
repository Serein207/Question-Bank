#include <bits/stdc++.h>
using namespace std;

int s[3];

int main() {
    scanf("%d%d%d", &s[0], &s[1], &s[2]);
    sort(s, s + 3);
    printf("%d\n", (s[0] & s[1] & s[2] & 1) ? s[0] * s[1] : 0);
    return 0;
}