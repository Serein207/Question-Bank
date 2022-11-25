#include <bits/stdc++.h>
using namespace std;

#define N 2000007

char arr[N];
int pi[N];
int num1[N], num2[N];

void calc(int *num, int n) {
    for (int i = 0; i < n; i++) num[pi[i]]++;
    for (int i = n - 1; i > 0; i--) num[pi[i - 1]] += num[i];
    for (int i = 0; i <= n; i++) num[i]++;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", arr);
        arr[n] = '*';
        for (int i = 0; i < n; i++) {
            arr[2 * n - i] = arr[i];
        }
        int m = n * 2 + 1;
        for (int i = 0; i <= m; i++) {
            num1[i] = num2[i] = 0;
        }
        for (int i = 1; i < m; i++) {
            int j = pi[i - 1];
            while (j && arr[i] != arr[j]) {
                j = pi[j - 1];
            }
            if (arr[i] == arr[j]) j++;
            pi[i] = j;
        }
        calc(num1, n);
        calc(num2, m);
        for (int i = 1; i <= n; i++) {
            printf("%d ", num2[i] - num1[i]);
        }
        printf("\n");
    }
    return 0;
}