# 喷涂面积

当两个矩形不重叠的时候，答案即为两个矩形的面积之和。

当两个矩形重叠的时候，我们需要计算两个矩形重叠部分的面积。

可以知道，两个矩形重叠的部分也是矩形，我们分别计算该重叠部分的 $x$ 轴与 $y$ 轴上的长度即可。

以重叠部分的 $x$ 轴上的长度为例，其左边界为两矩形的左边界的较大值，其右边界为两矩形的右边界的较小值。用右边界减去左边界即可得到 $x$ 轴上的长度。

将 $x$ 轴上的长度与 $y$ 轴上的长度相乘即可得到矩形的面积。

# 算式重排

记加号的数量为 $\texttt{num}_k$，那么最终的表达式中恰有 $\texttt{num}_k+1$ 个数。

我们记这 $\texttt{num}_k+1$ 个数的为待填数，我们只需要贪心地将较大的数字放在待填数尽可能小的位置上即可。

具体地，我们首先记录每一个数字出现的次数，然后从大到小枚举每一个数字，将它填入当前所有待填数中的还未填的最低位即可。

当我们得到所有的待填数，只需要将这些待填数的最低位对齐（最右侧为个位，也就是最低位），逐位相加即可得到最后的结果。

以 `1122233+` 为例，待填数有两个，我们首先填入所有的 $3$：

```
ˍˍˍ3
 ˍˍ3
```

然后填入所有的 $2$：

```
ˍ223
 ˍ23
```

最后填入所有的 $1$：

```
1223
 123
```

最终的结果即为：$1223+123=1346$。

# 好运咕咕

注意到对于 $2k$ 和 $2k + 1$（$k\in Z$），后者的二进制表示的必然恰好比前者多 $1$。

这意味着这两个数必然有一个为幸运数，而另一个不是幸运数。

因此对于区间 $[2a,2b+1]$（$a,b \in Z,a \leq b$），其中的幸运数的数量即为 $\frac{b-a+1}{2}$。

这样我们只需要将区间 $[l,r]$ 向上述区间靠拢。注意需要特判区间两旁是否是幸运数即可。

# 祖玛游戏

可以发现是 $m$ 种不同的括号的括号序列问题。

使用区间 DP 即可，令 $f_{i,j}$ 表示区间 $(i,j)$ 中 `(...)` 型的序列的方案数，$g_{i,j}$ 表示区间 $(i,j)$ 中 `(...)(...)` 型的序列的方案数。

$f_{i,j}$ 只需从 $f_{i+1,j}+g_{i+1,j}$ 转移得来。

$g_{i,j}$ 则需要枚举分界点 $k$，从 $f_{i,k} \times g_{k+1,j}$ 转移得来。

最后的答案即为 $f_{1,n}+g_{1,n}$。

# 井字棋局

对于一个方格盘，每个格子只有三种状态：`O`、`X` 或 空着。

整个棋盘只有三种合法状态：白咕咕获胜、黑咕咕获胜、平局。

对于一个填满的棋盘，其状态很容易判定。直接判断两人是否达成获胜条件即可，其预测结果即为其当前的状态。

特别地，对于两人均达成获胜条件的状态棋盘，如：

```
OOO
XXX
OXO
```

落子过程中将提前达成某一方的胜利，因此该状态是非法的，无需考虑。

对于一个未填满的棋盘，假设当前落子者为 $A$，我们可以用这种方法来计算其预测结果：

1. 递归计算其下一步落子后的所有可能的状态的预测结果。
2. 如果下一步的预测结果中存在 $A$ 获胜，那么 $A$ 必将选取该状态，最终 $A$ 将获胜。
3. 否则如果下一步的预测结果中存在平局，那么 $A$ 必将选取该状态，最终将平局。
4. 否则最终 $B$ 将获胜。

我们可以计算所有的状态的预测结果，并使用记忆化搜索的方式，存储这些结果，以加速运算。

# 魔力仓库

题意为给定序列，计算最多可以执行多少次操作：从 $n$ 个数里选择一个 $n-1$ 个数，让它们减一。

直接进行操作很困难，因为很难选择贪心策略。可以使用二分答案。

将题目给定操作转化为选择一个数加一，然后让所有数减一。记前者为操作一，后者为操作二。假设我们进行了 $k$ 次操作，那么等价于先执行 $k$ 次操作一，然后后执行 $k$ 次操作二。

这样我们遍历序列中的每一个元素 $x$，如果 $x \geq k$，那么我们无需对该元素执行操作一，否则我们需要进行 $k-x$ 次操作一，来保证最后序列元素都非负。我们将需要的操作一的次数累加，得到 $sum$，如果 $sum \leq k$，那么执行 $k$ 次操作是可行的。

# 极地救援

题意为给定二维平面上的 $n$ 个点，询问对于每一个 $k$：从 $n$ 个点中选 $k$ 个的所有方案中，它们到平面上的某个点的最小曼哈顿距离之和。

当 $k=n$ 时，我们可以将两维分开处理，取各自的中位数作为集合点的坐标。

当 $x_i,y_i$ 范围较小时，我们可以枚举地图上的每一个点作为集合点。

正解是，集合点的横坐标必然为给定的 $n$ 个点的横坐标之一，纵坐标同理。这样我们即可枚举每一个集合点，计算给定的点到集合点的距离即可，时间复杂度（$O(n^3 \log n)$）
