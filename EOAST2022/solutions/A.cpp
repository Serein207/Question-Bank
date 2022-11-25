#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int64 calcArea(int64 ax1, int64 ay1, int64 ax2, int64 ay2, int64 bx1, int64 by1, int64 bx2, int64 by2) {
    int64 area1 = (ax2 - ax1) * (ay2 - ay1);
    int64 area2 = (bx2 - bx1) * (by2 - by1);
    int64 overlapWidth = min(ax2, bx2) - max(ax1, bx1);
    int64 overlapHeight = min(ay2, by2) - max(ay1, by1);
    int64 overlapArea = max(overlapWidth, 0ll) * max(overlapHeight, 0ll);
    return area1 + area2 - overlapArea;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int64 ax1, ay1, ax2, ay2;
        scanf("%lld%lld%lld%lld", &ax1, &ay1, &ax2, &ay2);
        assert(ax1 <= ax2 && ay1 <= ay2);

        int64 bx1, by1, bx2, by2;
        scanf("%lld%lld%lld%lld", &bx1, &by1, &bx2, &by2);
        assert(bx1 <= bx2 && by1 <= by2);

        printf("%lld\n", calcArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));
    }
    return 0;
}