#include <bits/stdc++.h>
using namespace std;

set<array<int, 9>> st;

void dfs_state(array<int, 9>& state, int dep, int bef) {
    for (int i = 0; i < 9; i++) {
        if (state[i] > 4) return;
    }
    st.insert(state);
    if (dep < 4) {
        for (int i = bef; i < 7; i++) {
            state[i]++, state[i + 1]++, state[i + 2]++;
            dfs_state(state, dep + 1, i);
            state[i]--, state[i + 1]--, state[i + 2]--;
        }
        for (int i = bef; i < 9; i++) {
            state[i] += 3;
            dfs_state(state, dep + 1, i);
            state[i] -= 3;
        }
    }
}

void prepare() {
    array<int, 9> state;
    state.fill(0);
    dfs_state(state, 0, 0);
}

array<int, 34> tilesNum;

class Tiles {
public:
    int startIndex, size;
    vector<int> numsA;  // without eyes
    vector<int> numsB;  // with eyes

    Tiles(int startIndex, int size) : startIndex(startIndex), size(size) {
        numsA.resize(5, -1);
        numsB.resize(5, -1);
    }

    int& getTilesNum(int x) {
        return tilesNum[x + startIndex];
    }

    int getNums(int x, int kind) {
        return (kind ? numsB : numsA)[x];
    }

    void print_nums() {
        for (int i = 0; i <= 4; i++) {
            printf("%d ", numsA[i]);
        }
        printf("\n");
        for (int i = 0; i <= 4; i++) {
            printf("%d ", numsB[i]);
        }
        printf("\n");
    }
};

class NormalTiles : public Tiles {
public:
    NormalTiles(int startIndex) : Tiles(startIndex, 9) {
    }

    void calc() {
        for (auto& s : st) {
            int sum = 0, k = 0;
            int eyes_cost = INT_MAX;
            for (int i = 0; i < 9; i++) {
                sum += max(s[i] - getTilesNum(i), 0);
                if (s[i] <= 2) {
                    int temp = max(s[i] + 2 - getTilesNum(i), 0);
                    eyes_cost = min(eyes_cost, temp);
                }
                k += s[i];
            }
            k /= 3;
            if (numsA[k] == -1 || numsA[k] > sum) {
                numsA[k] = sum;
            }
            if (numsB[k] == -1 || numsB[k] > sum + eyes_cost) {
                numsB[k] = sum + eyes_cost;
            }
        }
    }
};

class HonorTiles : public Tiles {
public:
    HonorTiles(int startIndex) : Tiles(startIndex, 7) {
    }

    void calc() {
        int num[7];
        for (int i = 0; i < 7; i++) {
            num[i] = getTilesNum(i);
        }
        sort(num, num + 7, greater<int>());
        int sum = 0;
        numsA[0] = 0, numsB[0] = num[0] >= 2 ? 0 : 2 - num[0];
        for (int i = 1; i <= 4; i++) {
            sum += num[i - 1] >= 3 ? 0 : 3 - num[i - 1];
            int eyes_cost = num[i] >= 2 ? 0 : 2 - num[i];
            numsA[i] = sum, numsB[i] = sum + eyes_cost;
        }
    }
};

char tmp[3];

int main() {
    prepare();

    int t;
    scanf("%d", &t);
    while (t--) {
        tilesNum.fill(0);
        NormalTiles man(0), sou(9), pin(18);
        HonorTiles hon(27);
        for (int i = 0; i < 13; i++) {
            scanf("%s", tmp);
            int k = tmp[0] - '1';
            if (tmp[1] == 'm') {
                man.getTilesNum(k)++;
            } else if (tmp[1] == 's') {
                sou.getTilesNum(k)++;
            } else if (tmp[1] == 'p') {
                pin.getTilesNum(k)++;
            } else if (tmp[1] == 'z') {
                hon.getTilesNum(k)++;
            }
        }
        man.calc();
        sou.calc();
        pin.calc();
        hon.calc();

        // man.print_nums();
        // sou.print_nums();
        // pin.print_nums();
        // hon.print_nums();

        int ans = INT_MAX;
        for (int s = 0; s < 4; s++) {
            for (int i = 0; i <= 4; i++) {
                for (int j = 0; i + j <= 4; j++) {
                    for (int k = 0; i + j + k <= 4; k++) {
                        int l = 4 - (i + j + k);
                        int sum = man.getNums(i, s == 0) + sou.getNums(j, s == 1) + pin.getNums(k, s == 2) + hon.getNums(l, s == 3);
                        ans = min(ans, sum);
                    }
                }
            }
        }

        // check seven pairs
        {
            int num[34];
            for (int i = 0; i < 34; i++) {
                num[i] = tilesNum[i];
            }
            sort(num, num + 34, greater<int>());
            int sum = 0;
            for (int i = 0; i < 7; i++) {
                sum += num[i] >= 2 ? 0 : 2 - num[i];
            }
            ans = min(ans, sum);
        }

        // check thirteen orphans
        {
            int index[] = {0, 8, 9, 17, 18, 26, 27, 28, 29, 30, 31, 32, 33};
            int num[13];
            for (int i = 0; i < 13; i++) {
                num[i] = tilesNum[index[i]];
            }
            sort(num, num + 13, greater<int>());
            int sum = 1;
            if (num[0] > 1) {
                for (int i = 0; i < 12; i++) {
                    sum += num[i] == 0;
                }
            } else {
                for (int i = 0; i < 13; i++) {
                    sum += num[i] == 0;
                }
            }
            ans = min(ans, sum);
        }

        printf("%d\n", ans - 1);
    }
    return 0;
}