#include <bits/stdc++.h>
using namespace std;

#define int64 long long
#define MOD 1000000007
#define N 100001

class BinaryIndexedTree {
private:
    int c[N];

    int lowbit(int x) {
        return x & (-x);
    }

public:
    void add(int x, int y) {
        for (int i = x; i < N; i += lowbit(i)) {
            c[i] = (c[i] + y) % MOD;
        }
    }

    int query(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) {
            ret = (ret + c[i]) % MOD;
        }
        return ret;
    }
} bit[11];

class SegmentTree {
private:
    int tree[N << 2];

    void pushup(int i) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }

public:
    void build(char* str, int i, int l, int r) {
        if (l == r) {
            tree[i] = str[l] - '0';
            return;
        }
        int mid = (l + r) / 2;
        build(str, i << 1, l, mid);
        build(str, i << 1 | 1, mid + 1, r);
        pushup(i);
    }

    void update(int i, int l, int r, int x, int val) {
        if (l == r) {
            tree[i] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (x <= mid) {
            update(i << 1, l, mid, x, val);
        } else {
            update(i << 1 | 1, mid + 1, r, x, val);
        }
        pushup(i);
    }

    int query(int i, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            return tree[i];
        }

        int maxm = 0, mid = (l + r) / 2;
        if (x <= mid) {
            maxm = max(maxm, query(i << 1, l, mid, x, y));
        }
        if (y > mid) {
            maxm = max(maxm, query(i << 1 | 1, mid + 1, r, x, y));
        }
        return maxm;
    }
} segmentTree;

int64 quick_pow(int64 x, int64 n, int64 p) {
    int64 ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return ret;
}

int64 inv(int64 x) {
    return quick_pow(x, MOD - 2, MOD);
}

char str[N];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", str + 1);

    auto update = [&](int x, int y) {
        for (int i = 1; i <= 10; i++) {
            bit[i - 1].add(x, y * quick_pow(i, n - x, MOD) % MOD);
        }
    };

    auto querySum = [&](int p, int l, int r) {
        int temp = (bit[p - 1].query(r) - bit[p - 1].query(l - 1) + MOD) % MOD;
        return temp * inv(quick_pow(p, n - r, MOD)) % MOD;
    };

    auto queryMax = [&](int l, int r) { return segmentTree.query(1, 1, n, l, r); };

    segmentTree.build(str, 1, 1, n);

    for (int i = 1; i <= n; i++) {
        update(i, str[i] - '0');
    }

    int t, x, y;
    while (q--) {
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1) {
            int p = queryMax(x, y) + 1;
            printf("%lld\n", querySum(p, x, y));
        } else if (t == 2) {
            int dis = (y - str[x] + '0' + MOD) % MOD;
            update(x, dis);
            str[x] = y + '0';
            segmentTree.update(1, 1, n, x, y);
        }
    }
    return 0;
}