# 好运咕咕

1000ms  262144K

## Description

好运的咕咕有着许多幸运数。

对于一个数 $x$，如果它的二进制表示中的 $1$ 的数量恰为奇数，那么咕咕认为这是一个幸运数。

例如，对于数字 $7$，其二进制表示为 $111$，其中恰有三个 $1$，因此咕咕认为 $7$ 是她的幸运数。

现在咕咕想考考你，区间 $[l,r]$ 包含了多少幸运数呢？

## Input

第一行一个整数 $t$，表示有 $t$ 组测试用例。

接下来 $t$ 组测试用例，每组测试用例仅一行。

唯一的第一行包含两个整数 $l,r$，表示区间 $[l,r]$。

对于 $30\%$ 的数据，$t \leq 10, r \leq 10^4$。

对于 $70\%$ 的数据，$t \leq 10^4, r \leq 2 \cdot 10^6$。

对于 $100\%$ 的数据，$1 \leq t \leq 2 \cdot 10^5, 0 \leq l \leq r \leq 10^{18}$。

## Output

对于每组测试用例，输出一行，唯一的一行里包含一个整数，表示幸运数的数量。

## Sample Input

```
2
1 10
1 100
```

## Sample Output

```
5
51
```

## Note

在样例的第一组测试用例中，区间 $[1,10]$ 中 $1,2,4,7,8$ 共 $5$ 个数符合条件。
