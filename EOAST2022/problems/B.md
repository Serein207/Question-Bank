# 算式重排

1000ms  262144K

## Description

咕咕最近在学习加法算式！

她的手上有许多写有加法符号或者数字 $1$ 到 $9$ 的卡牌，她不断地排列这些卡牌，然后计算这个表达式的结果。

例如，对于卡牌组 `1234+`，咕咕可以将它们重新排列为 `12+34`，然后计算得到结果为 $45$。

**注意**：排列 `+1234` 或 `1234+` 这样的排列是非法的。

现在咕咕想要知道，对于所有合法的排列，它们对应的表达式的结果的最小值是多少呢？

## Input

第一行一个整数 $t$，表示有 $t$ 组测试用例。

接下来 $t$ 组测试用例，每组测试用例共两行。

第一行一个整数 $n$，表示字符串的长度。

唯一的一行包含一个字符串 $s$，表示了咕咕拥有的所有卡牌。

输入数据保证存在合法的排列，且 $\sum n \leq 5 \cdot 10^5$。

对于 $30\%$ 的数据，$t = 1, n \leq 10$，$s$ 中不包含加法符号。

对于 $70\%$ 的数据，$t \leq 10, n \leq 1000$，$s$ 中恰包含一个加法符号。

对于 $100\%$ 的数据，$1 \leq t \leq 10^4, 0 \leq n \leq 10^5$。

## Output

对于每组测试用例，输出一行，唯一的一行里包含一个整数，表示对于所有合法的排列，它们对应的表达式的结果的最小值。

## Sample Input

```
3
5
1+133
6
323123
7
11+2+33
```

## Sample Output

```
26
122333
28
```

## Note

在样例的第一组测试用例中，对应表达式结果最小的合法排列为 `13+13`。

在样例的第二组测试用例中，对应表达式结果最小的合法排列为 `122333`。

在样例的第三组测试用例中，对应表达式结果最小的**其中一种**合法排列为 `13+13+2`。
