#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int calc(int na, int nb, int nc) {
    return na * a + nb * b + nc * c;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);
        int grid[3][3] = {
            {calc(1, 0, 0), calc(-2, -1, 4), calc(1, 1, -1)},
            {calc(0, 1, 0), calc(0, 0, 1), calc(0, -1, 2)},
            {calc(-1, -1, 3), calc(2, 1, -2), calc(-1, 0, 2)},
        };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}