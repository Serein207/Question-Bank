#include <bits/stdc++.h>
using namespace std;

#define N 9
#define M 19683

const int base[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561};

int getNumber(int x, int index) {
    return x / base[index] % 3;
}

const int checkList[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

int calcWinner(int x) {
    auto getLineWinner = [&](int a, int b, int c) {
        int numA = getNumber(x, a);
        int numB = getNumber(x, b);
        int numC = getNumber(x, c);
        return numA == numB && numA == numC ? numA : 0;
    };

    int winner = -1;
    for (auto checkItem : checkList) {
        int lineWinner = getLineWinner(checkItem[0], checkItem[1], checkItem[2]);
        if (lineWinner == 0) continue;
        if (winner == -1) {
            winner = lineWinner;
        } else {
            assert(lineWinner == winner);
        }
    }
    return winner;
}

int count0(int x) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        num += getNumber(x, i) == 0;
    }
    return num;
}

int finalWinner[M];

int getWinner(int x) {
    if (finalWinner[x]) {
        return finalWinner[x];
    }
    int currWinner = calcWinner(x);
    int num0 = count0(x);
    if (currWinner > 0 || num0 == 0) {
        return finalWinner[x] = currWinner;
    }

    int player = 2 - num0 % 2;
    bool haveDraw = false;
    for (int i = 0; i < N; i++) {
        if (getNumber(x, i)) continue;
        int y = x + base[i] * player;
        int winner = getWinner(y);
        if (winner == player) {
            return finalWinner[x] = player;
        } else if (winner == -1) {
            haveDraw = true;
        }
    }
    return finalWinner[x] = haveDraw ? -1 : 3 - player;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int winner = -1;
        int state = 0;
        for (int i = 0, x, y; i < n; i++) {
            scanf("%d%d", &x, &y);
            if (winner == -1) {
                state += base[x * 3 + y - 4] * (i % 2 + 1);
                winner = calcWinner(state);
            }
        }
        if (winner == -1) {
            winner = getWinner(state);
        }
        if (winner == -1) {
            puts("Draw");
        } else if (winner == 1) {
            puts("White");
        } else if (winner == 2) {
            puts("Black");
        }
    }
    return 0;
}
