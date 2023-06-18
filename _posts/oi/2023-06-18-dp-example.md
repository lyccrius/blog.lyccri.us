---
layout: post
title:  DP 例题
date:   2023-06-18
categories: oi
---

##  HDU     2602    Bone collector

01 背包。

记 $f_{i, j}$ 表示考虑前 $i$ 个物品占用 $j$ 体积的最大价值。

$$f_{i, j} = \max(f_{i - 1, j}, f_{i, j - v_i} + w_i)$$

时间复杂度 $\mathcal O(nv)$。

```cpp
#include <iostream>
#include <algorithm>

const int maxN = 1000;
const int maxV = 1000;

int t;
int n, V;
int w[maxN + 10];
int v[maxN + 10];
int f[maxN + 10];

void mian() {
    std::fill(f, f + sizeof(f) / 4, 0);
    std::cin >> n >> V;

    for (int i = 1; i <= n; i++)
        std::cin >> w[i];

    for (int i = 1; i <= n; i++)
        std::cin >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);
        }
    }

    for (int i = 1; i <= V; i++)
        f[0] = std::max(f[0], f[i]);

    std::cout << f[0] << '\n';
    return;
}

int main() {
    std::cin >> t;

    while (t--)
        mian();

    return 0;
}
```

##  HDU     1712    ACboy needs your help

分组背包。

把同一门课程的不同复习时间归为一组。

一门课程只能选定一个时间长度复习，类比为一个组内的物品只能选一个。

记 $f_{i, j}$ 表示考虑前 $i$ 门课程，花费 $j$ 天的最大收益。

$$f_{i, j} = \max_{0 \le k \le j} \{ f_{i - 1, j - k} + a_{i, k} \}$$

时间复杂度 $\mathcal O(nm^2)$。

```cpp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxN = 100;

int n, m;
int f[maxN + 10];
int a[maxN + 10];

int main() {
    while (scanf("%d%d", &n, &m) && n && m) {
        memset(f, 0, sizeof(f));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[j]);
            }

            for (int j = m; j > 0; j--) {
                for (int k = j; k > 0; k--) {
                    f[j] = std::max(f[j], f[j - k] + a[k]);
                }
            }
        }

        printf("%d\n", f[m]);
    }

    return 0;
}
```

##  Luogu   P1776   宝物筛选

多重背包。

直接枚举每件物品选多少件需要 $\mathcal O(nmv)$，超时。

在二进制表示下，任意整数都可以表示成若干 $2$ 的整数次幂相加的形式。

对每件物品的数量进行二进制分组，分组后 $n \log m$ 件物品与原 $n$ 件物品等价。

时间复杂度 $\mathcal O(nv \log m)$

```cpp
#include <iostream>

int n, W;
int v[2000], w[1000];
int vv, ww, mm;
int F[40010];
int top = 0;

int main() {

    std::cin >> n >> W;

    for (int i = 1; i <= n; i ++) {
        std::cin >> vv >> ww >> mm;

        for (int j = 1; j <= mm; j *= 2) {
            top ++;
            v[top] = j * vv;
            w[top] = j * ww;
            mm -= j;
        }

        if (mm) {
            top ++;
            v[top] = mm * vv;
            w[top] = mm * ww;
        }
    }

    for (int i = 1; i <= top; i ++)
        for (int j = W; j >= w[i]; j --)
            F[j] = std::max(F[j], F[j - w[i]] + v[i]);

    std::cout << F[W];

    return 0;

}
```

##  Luogu   P2602   数字计数

数位 DP。

考虑一个数字怎么求，其它数字使用相同求法。

当前要求 $[l, r]$ 中 $x$ 出现的次数，可以差分为 $[1, r]$ 中 $x$ 出现的次数减去 $[1, l - 1]$ 中 $x$ 出现的次数。

要求 $n$ 以内 $x$ 出现的次数，现将 $n$ 在十进制表示下的若干位提出来。

从最高位开始记忆化搜索，搜索时需要记录四个信息：
1.  当前搜索到十进制下的哪一位
2.  当前考虑的数码 $x$
3.  高于当前位是否有签到零
4.  高于当前位是否贴着 $n$ 的上限

考虑当前位填那一位数字，根据以上四条信息进行分类讨论计数。

注意当有前导零或贴到上限时不可记忆化。

```cpp
#include <iostream>
#include <vector>

typedef long long lxl;
typedef std::vector<int> vic;

lxl a, b;
vic bits;
lxl p[20];
lxl v[20];
lxl f[20];

lxl pow(lxl a, lxl b) {
    lxl ret = 1;

    while (b) {
        if (b & 1)
            ret = ret * a;

        a = a * a;
        b = b / 2;
    }

    return ret;
}

lxl DFS(int u, int dig, int zer, int lim) {
    if (u < 0)
        return 0;

    if (!lim && !zer && v[u])
        return f[u];

    lxl ret = 0;
    int tot = lim ? bits[u] : 9;

    for (int i = 0; i <= tot; i++) {
        if (i == 0 && zer) {
            ret += DFS(u - 1, dig, zer, lim && i == tot);
        } else if (i == dig) {
            if (lim && i == tot) {
                ret += p[u - 1] + 1 + DFS(u - 1, dig, false, lim && i == tot);
            } else {
                ret += pow(10, u) + DFS(u - 1, dig, false, lim && i == tot);
            }
        } else {
            ret += DFS(u - 1, dig, false, lim && i == tot);
        }
    }

    if ((!zer) && (!lim)) {
        v[u] = true;
        f[u] = ret;
    }

    return ret;
}

lxl calc(lxl n, lxl dig) {
    bits.clear();
    std::fill(p, p + sizeof(p) / 8, 0);
    std::fill(v, v + sizeof(v) / 8, 0);
    std::fill(f, f + sizeof(f) / 8, 0);

    while (n) {
        bits.push_back(n % 10);
        n /= 10;
        p[bits.size() - 1] = p[bits.size() - 2] + 1ll * bits[bits.size() - 1] * pow(10, bits.size() - 1);
    }

    return DFS(bits.size() - 1, dig, true, true);
}

int main() {
    std::cin >> a >> b;

    for (int i = 0; i <= 9; i++)
        std::cout << calc(b, i) - calc(a - 1, i) << ' ';

    return 0;
}
```

##  Luogu   P2657   Windy 数

数位 DP。

在上一道题的基础上新增一维信息，即上一位所填的数字。

枚举当前位所填数字时，如果与上一位所填数字差小于 $2$ 则跳过。

```cpp
#include <iostream>
#include <cstring>

int a, b, len, num[15], f[15][15];

int dfs(int len, int last, bool lim, bool zer) {
    if (!len)
        return 1;

    if (!lim && !zer && ~f[len][last])
        return f[len][last];

    int ret = 0;

    for (int i = 0; i <= 9; i++)
        if ((i <= num[len] || !lim) && (abs(i - last) >= 2 || zer))
            ret += dfs(len - 1, i, lim && (i == num[len]), zer && (!i));

    f[len][last] = ret;
    return ret;
}

int solve(int x) {
    int tmp = x;
    len = 0;
    memset(num, 0, sizeof(num));

    while (tmp) {
        num[++len] = tmp % 10;
        tmp /= 10;
    }

    memset(f, -1, sizeof(f));
    return dfs(len, 11, 1, 1);
}

int main() {
    std::cin >> a >> b;
    std::cout << solve(b) - solve(a - 1) << '\n';
    return 0;
}
```

##  Luogu   P4124   手机号码

数位 DP。

与上一道题同样的思路，在记忆化搜索形式的数位 DP 的基础上继续添加状态维度：
1.  前两位所填数字
2.  前一位所填数字
3.  之前是否出现至少 $3$ 位相邻的数字
4.  是否出现过 $4$
5.  是否出现过 $8$

```cpp
#include <iostream>
#include <cstring>

typedef long long lxl;

int num[12], len;
lxl l, r, f[11][11][11][2][2][2][2];

lxl dfs(int p, int a, int b, bool c, bool d, bool _4, bool _8) {
    if (_4 && _8) return 0;
    if (p <= 0) return c;
    if (~f[p][a][b][c][d][_4][_8]) return f[p][a][b][c][d][_4][_8];
    lxl ret = 0;
    int lim = !d ? num[p] : 9;
  	for (int i = 0; i <= lim; i++)
        ret += dfs(p - 1, i, a, c || (i == b && i == a), d || (i < lim), _4 || (i == 4), _8 || (i ==8 ));
    return f[p][a][b][c][d][_4][_8]=ret;
}

lxl solve(lxl x) {
    if (x < 1e10) return 0;
    memset(f, -1, sizeof(f));
    for (len = 0; x; x /= 10) num[++len] = x % 10;
	lxl ret = 0;
	for (int i = 1; i <= num[len]; i++) ret += dfs(10, i, 0, 0, i < num[len], i == 4, i == 8);
	return ret;
}

int main() {
    std::cin >> l >> r;
    std::cout << solve(r) - solve(l - 1) << '\n';
    return 0;
}
```

##  POJ     2411    Mondriaan's dream

轮廓线 DP。

枚举当前要处理的格子，使用大小为 $2^w$ 的状态压缩表示当前行该点左侧及上一行该点右侧的骨牌堆放情况。

对于当前格子有三种决策：
1.  横放（向左）
    *   左侧格子为空时
2.  竖放（向上）
    *   上侧格子为空时
3.  留空（不动）
    *   左侧上侧非空时

依次检查当前状态能否满足上述三种情况，若满足则累加计数。

需要滚动数组优化。

```cpp
#include <iostream>
#include <cstring>

typedef long long lxl;

const int maxM = 10;

int n, m;
int cur;
int p[maxM + 10];
lxl f[2][(1 << maxM) + 10];

void mian() {
    if (n < m) std::swap(n, m);
    memset(f, 0, sizeof(f));
    cur = 0;
    f[0][(1 << m) - 1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cur ^= 1;
            memset(f[cur], 0, sizeof(f[cur]));
            for (int k = 0; k < (1 << m); k++) {
                if (k & p[j]) f[cur][k ^ p[j]] += f[cur ^ 1][k];
                if (i != 1 && (k & p[j]) == 0) f[cur][k ^ p[j]] += f[cur ^ 1][k];
                if (j != 1 && (k & p[j - 1]) == 0 && (k & p[j])) f[cur][k ^ p[j - 1]] += f[cur ^ 1][k];
            }
        }
    }
    printf("%lld\n", f[cur][(1 << m) - 1]);
    return;
}

int main() {
    for (int j = 1; j <= maxM; j++) p[j] = 1 << (j - 1);
    while (scanf("%d%d", &n, &m) != EOF) mian();
    return 0;
}
```

##  HDU     4539    排兵布阵

状压 DP。

相邻的三行都有可能相互攻击，因此需要枚举连续三行的状态。

但是这样的状态数有 $(2^10)^3$ 达到了 $1e9$ 级别。

考虑优化，考虑第 $i$ 行时先枚举第 $i, i - 1$ 行的状态，若合法再枚举第 $i - 2$ 行的状态。

*   相邻两行状态 $x, y$ 合法，需要 $x \& (y << 1) = 0, x \& (y >> 1) = 0$。
*   相隔两行状态 $x, y$ 合法，需要 $x \& y = 0$。

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>

int s[200];
int a[200][15];
int f[105][200][200];
int n, m;

int init(int n) {
    int M = 0;

    for (int i = 0; i < n; i++)
        if ((i & (i >> 2)) == 0 && (i & (i << 2)) == 0)
            s[M++] = i;

    return M;
}

int sum(int i, int x) {
    int sum = 0, j = m - 1;

    while (x) {
        if (x & 1)
            sum += a[i][j];

        x >>= 1;
        j --;
    }

    return sum;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        int M = init(1 << m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);

        int ans = 0;
        memset(f, 0, sizeof(f));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    if ((s[j] & (s[k] >> 1)) || (s[j] & (s[k] << 1)))
                        continue;

                    if (i == 0) {
                        f[i][j][k] = sum(i, s[j]);
                        ans = std::max(ans, f[i][j][k]);
                        continue;
                    }

                    int tmp = 0;

                    for (int p = 0; p < M; p++) {
                        if ((s[p] & (s[k] >> 1)) || (s[p] & (s[k] << 1)))
                            continue;

                        if (s[j] & s[p])
                            continue;

                        tmp = std::max(tmp, f[i - 1][k][p]);
                    }

                    f[i][j][k] = tmp + sum(i, s[j]);
                    ans = std::max(ans, f[i][j][k]);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
```

##  HDU     3001 

状压 DP。

解决哈密顿回路的方法是记 $f_{i, j}$ 表示经过的点集二进制压缩后为 $i$，当前在 $j$ 点的最小花费。

这道题要求每个点经过不超过 $2$ 次，可能不存在一种每个点都经过一次的方案。

于是重新设计状态，$f_{i, j}$ 表示各点经过次数三进制压缩后为 $i$，当前在 $j$ 点的最小花费。

状态转移与哈密顿回路一样。

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>

const int inf = 1e9 + 10;

int n, m, ans;
int adj[12][12];
int bit[11] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int f[60000][12];
int num[60000][12];

void init() {
    for (int i = 0; i < bit[10]; i++) {
        int b = i;

        for (int j = 0; j < 10; j++) {
            num[i][j] = b % 3;
            b /= 3;
        }
    }
}

int main() {
    init();

    while (~scanf("%d%d", &n, &m)) {
        memset(adj, -1, sizeof(adj));

        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);

            if (adj[a - 1][b - 1] == -1)
                adj[b - 1][a - 1] = adj[a - 1][b - 1] = c;
            else
                adj[b - 1][a - 1] = adj[a - 1][b - 1] = std::min(adj[a - 1][b - 1], c);
        }

        memset(f, 0x3f3f3f3f, sizeof(f));

        for (int j = 0; j < n; j++)
            f[ bit[j] ][j] = 0;

        int flag, next;
        ans = inf;

        for (int i = 0; i < bit[n]; i++) {
            flag = 1;

            for (int j = 0; j < n; j++) {
                if (num[i][j] == 0)
                    flag = 0;

                if (f[i][j] == inf)
                    continue;

                for (int l = 0; l < n; l++) {
                    if (j == l || num[i][l] >= 2 || adj[l][j] == -1)
                        continue;

                    next = i + bit[l];
                    f[next][l] = std::min(f[next][l], f[i][j] + adj[j][l]);
                }
            }

            if (flag == 1) {
                for (int j = 0; j < n; j++)
                    ans = std::min(ans, f[i][j]);
            }
        }

        if (ans == inf)
            ans = -1;

        printf("%d\n", ans);
    }

    return 0;
}
```

##  Luogu   P1880   石子合并

区间 DP。

$f_{i, j}, g_{i, j}$ 表示 $[i, j]$ 堆石子合并成一堆的最小最大得分。

$$
\begin{aligned}
    f_{i, j} & = \min_{i \le k \lt j} f_{i, k} + f_{k + 1, j} + sum(i, j) \\
    g_{i, j} & = \max_{i \le k \lt j} g_{i, k} + g_{k + 1, j} + sum(i, j)
\end{aligned}
$$

其中 $sum(i, j)$ 表示 $[i, j]$ 的石子个数和，可以使用前缀和 $\mathcal O(1)$ 计算。

时间复杂度 $\mathcal O(n^3)$。

数据范围再大点可以使用四边形不等式优化。

```cpp
#include <iostream>
#include <cstring>

const int maxN = 100;

int N;
int a[maxN * 2 + 10];
int b[maxN * 2 + 10];
int f[maxN * 2 + 10][maxN * 2 + 10];
int g[maxN * 2 + 10][maxN * 2 + 10];

int main() {
    std::memset(f, 0x3f, sizeof(f));
    std::cin >> N;

    for (int i = 1; i <= N; i++)
        std::cin >> a[i], a[N + i] = a[i];

    for (int i = 1; i <= 2 * N; i++)
        b[i] = b[i - 1] + a[i];

    for (int i = 1; i <= 2 * N; i++)
        f[i][i] = 0;

    for (int i = 1; i <= 2 * N; i++)
        g[i][i] = 0;

    for (int len = 2; len <= N; len++) {
        for (int i = 1; i <= 2 * N; i++) {
            int j = i + len - 1;

            if (j > 2 * N)
                break;

            for (int k = i; k < j; k++) {
                f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j]);
                g[i][j] = std::max(g[i][j], g[i][k] + g[k + 1][j]);
            }

            f[i][j] += b[j] - b[i - 1];
            g[i][j] += b[j] - b[i - 1];
        }
    }

    for (int i = 1; i <= N; i++) {
        int j = i + N - 1;
        f[0][0] = std::min(f[0][0], f[i][j]);
        g[0][0] = std::max(g[0][0], g[i][j]);
    }

    std::cout << f[0][0] << '\n' << g[0][0];
    return 0;
}
```

##  HDU     2476    String painter

区间 DP。

先考虑空串变成 $b$ 串的情况，再用 $a$ 串去匹配。

记 $f_{i, j}$ 表示空串变为 $b$ 串 $[i, j]$ 的最小次数。

$$
f_{i, j} = \min_{i \le k \lt j}
\begin{cases}
    f_{k + 1, j} + 1, & i = k \\
    f_{i + 1, k} + f_{k + 1, j} & b_i = b_k
\end{cases}
$$

记 $g_i$ 表示 $a$ 串前 $i$ 为变为 $b$ 串前 $i$ 的最小次数。

$$
g_i = 
\begin{cases}
    g_{i - 1}, & a_i = b_i \\
    \min_{0 \le j \lt i} g_j + f_{j + 1, i} & a_i \neq b_i
\end{cases}
$$

时间复杂度 $\mathcal O(n^3)$。

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>

char a[110], b[110];
int f[110][110];
int g[110];

int main() {
    while (scanf("%s%s", a, b) != EOF) {
        int len = strlen(a);
        int cnt = 1;

        for (int i = 0; i < len; i++) {
            f[i][i] = 1;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; i + j < len; j++) {
                f[j][i + j] = 1e9;

                for (int k = j; k <= i + j; k++) {
                    if (k != j && b[j] == b[k])
                        f[j][i + j] = std::min(f[j][i + j], f[j + 1][k] + f[k + 1][i + j]);
                    else
                        f[j][i + j] = std::min(f[j + 1][i + j] + 1, f[j][i + j]);
                }
            }
        }

        for (int i = 0; i < len ; i++) {
            if (a[i] == b[i]) {
                if (i == 0) {
                    g[i] = 0;
                } else
                    g[i] = g[i - 1];
            } else {
                g[i] = f[0][i];

                for (int j = 0; j < i; j++)
                    g[i] = std::min(g[i], g[j] + f[j + 1][i]);
            }
        }

        printf("%d\n", g[len - 1]);
    }
    return 0;
}
```

##  HDU     4283    You are the one

区间 DP。

$f_{i, j}$ 表示 $[i, j]$ 的最小愤怒值。

$$f_{i, j} = \min_{i \le k \lt j} (k - i) \times diaosi_i + f_{i + 1, k} + (k - i + 1) \times (sum_j - sum_k) + f_{k + 1, j}$$

时间复杂度 $\mathcal O(n^3)$。

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>

const int inf = 1e9 + 10;

int n, a[105], sum[105], f[105][105];

int main() {
    int t, i, j, k, l, cas = 1;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        memset(sum, 0, sizeof(sum));

        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }

        memset(f, 0, sizeof(f));

        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++)
                f[i][j] = inf;
        }

        for (l = 1; l < n; l++) {
            for (i = 1; i <= n - l; i++) {
                j = i + l;

                for (k = 1; k <= j - i + 1; k++)
                    f[i][j] = std::min(f[i][j], f[i + 1][i + k - 1] + f[i + k][j] + k * (sum[j] - sum[i + k - 1]) + a[i] * (k - 1));
            }
        }

        printf("Case #%d: %d\n", cas++, f[1][n]);
    }

    return 0;
}
```

##  CF      1198D   Rectangle painting

二维区间 DP。

$f(x_1, y_1, x_2, y_2)$ 表示 $(x_1, y_1)$ 到 $(x_2, y_2)$ 这一矩形内的最小代价。

分别枚举 $x$ 轴和 $y$ 轴的分界点，使用记忆化搜索形式实现。

时间复杂度 $\mathcal O(n^5)$。

```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>

int n, m;
int f[51][51][51][51];
char ch[55][55];

int dfs(int x, int y, int x2, int y2) {
    if (f[x][y][x2][y2] != -1)
        return f[x][y][x2][y2];

    if (x == x2 && y == y2) {
        f[x][y][x2][y2] = (ch[x][y] == '#');
        return f[x][y][x2][y2];
    }

    int ret = std::max(x2 - x + 1, y2 - y + 1);

    for (int i = x; i < x2; ++i)
        ret = std::min(ret, dfs(x, y, i, y2) + dfs(i + 1, y, x2, y2));

    for (int i = y; i < y2; ++i)
        ret = std::min(ret, dfs(x, y, x2, i) + dfs(x, i + 1, x2, y2));

    f[x][y][x2][y2] = ret;
    return ret;
}

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%s", ch[i] + 1);

    printf("%d\n", dfs(1, 1, n, n));
    return 0;
}
```

##  Luogu   P2015   二叉苹果树

树形 DP。

$f_{u, i}$ 表示 $u$ 的子树内保留 $i$ 根树枝的最多苹果数。

$$f_{u, i} = \max_{v \in son_u} f_{u, i - j - 1} + f_{v, j} + w$$

需要倒序枚举。

时间复杂度 $\mathcal O(nq^2)$。

```cpp
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct node {
    int v, val;
};

int n, q, ans;
vector<node> edge[110];
int f[110][30010], son[110];

void dfs(int x, int fa) {

    memset(f[x], 0, sizeof(f[x]));

    for (int i = 0; i < edge[x].size(); i ++) {
        if (edge[x][i].v == fa)
            continue;

        dfs(edge[x][i].v, x);
        son[x] += son[edge[x][i].v] + 1;

        for (int j = min(q, son[x]); j >= 1; j --)
            for (int k = 0; k <= min(son[edge[x][i].v], j - 1); k ++)
                f[x][j] = max(f[x][j], f[x][j - k - 1] + f[edge[x][i].v][k] + edge[x][i].val);
    }

    return ;

}

int main() {

    cin >> n >> q;
    int x, y, val;

    for (int i = 1; i <= n - 1; i ++) {
        cin >> x >> y >> val;
        edge[x].push_back((node) {
            y, val
        });
        edge[y].push_back((node) {
            x, val
        });
    }

    dfs(1, 0);

    cout << f[1][q];

    return 0;

}
```

##  Luogu   P1352   没有上司的舞会

树形 DP。

树上最大权独立集问题。

$f_{u, 0/1}$ 表示 $u$ 子树内 $u$ 是否选择的最大快乐指数。

$$
\begin{aligned}
    f_{u, 0} & = \sum_{v \in son_u} \max(f_{v, 0}, f_{v, 1}) \\
    f_{u, 1} & = \sum_{v \in son_u} f_{v, 0} + r_u
\end{aligned}
$$

时间复杂度 $\mathcal O(n)$。

```cpp
#include <bits/stdc++.h>

using namespace std;

int n;

int happy[6010];
int visit[6010];

int root;
vector<int>son[6010];

int F[6010][2];

void DFS(int x){
	F[x][0] = 0;
	F[x][1] = happy[x];
	
	for (int i = 0; i < son[x].size(); i ++) {
		DFS(son[x][i]);
		
		F[x][0] += max(F[son[x][i]][0], F[son[x][i]][1]);
		F[x][1] += F[son[x][i]][0];
	}
	
	return;
}

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i ++){
		cin >> happy[i];
	}
	
	int l, k;
	for (int i = 1; i < n; i ++){
		cin >> l >> k;
		son[k].push_back(l);
		visit[l] = 1;
	}
	
	for (int i = 1; i <= n; i ++){
		if (!visit[i]) {
			root = i;
			break;
		}
	}
	
	DFS(root);
	
	cout << max(F[root][0], F[root][1]) << endl;
	
	return 0;
}
```

##  Luogu   P1273   有线电视网

树形 DP。

$f_{u, i}$ 表示 $u$ 子树内 $i$ 个客户的最大收益。

$$f_{u, i} = \max_{v \in son_u} f_{u, i - j} + f_{v, j} - w$$

需要倒序枚举。

```cpp
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

struct node{
	int v, val;
};

vector<node> son[3010];
int f[3010][3010], line[3010], cnt[3010];
int n, m;

void dfs( int x ){
	
	if( x >= n - m + 1 ){
		cnt[x] = 1;
		f[x][1] = line[x];
		return ;
	}
	
	for( int i = 0; i <(int)son[x].size(); i ++ ){
		int v = son[x][i].v;
		dfs(v);
		cnt[x] += cnt[v];
		for( int j = cnt[x]; j >= 0; j -- )
			for( int k = 0; k <= min( j, cnt[v] ); k ++ )
				f[x][j] = max( f[x][j], f[x][j-k] + f[v][k] - son[x][i].val );
	}
	
	return ;
	
}

int main(){
	
	cin >> n >> m;
	
	int tmp, v, val;
	
	for( int i = 1; i <= n-m; i ++ ){
		cin >> tmp;
		for( int k = 1; k <= tmp; k ++ ){
			cin >> v >> val;
			son[i].push_back((node){v,val});
		}
	}
	
	for( int i = n - m + 1; i <= n; i ++ )
		cin >> line[i];
	
	memset( f, -0x7f7f, sizeof(f) );
	for( int i = 1; i <= n; i ++ )
		f[i][0] = 0;
	
	dfs(1);
	
	for( int i = m; i >= 0; i-- ){
		if( f[1][i] >= 0 ){
			cout << i;
			break;
		}
	}
	
	return 0;
}
```

##  Luogu   P3287   方伯伯的玉米田

显然每次拔高的区间都是一个后缀。

记 $f_{i, j}$ 表示前 $i$ 株玉米，拔高 $j$ 次，最长非降子序列长度。

$$f_{i, j} = \max_{k \lt i, l \le j, a_k + l \le a_i + j} f_{k, l} + 1$$

这个 $\mathcal O(n^2 k^2)$ 的转移可以说是只能过样例。

发现 $\max f_{k, l}$ 其实就是二维前缀最大值，可以用二维树状数组维护。

于是时间复杂度来到了 $\mathcal O(n k \log n \log k)$，能过。

打个表发现：
*   当 $i$ 一定时，$f_{i, j}$ 随 $j$ 增加不减。
*   当 $j$ 一定时，$f_{i, j}$ 随 $i$ 增加不减。

也就是说，我们要查 $(i, j)$ 的前缀最大值，只需要查 $k \in [1, i]$ 的 $f_{k, j}$ 和 $k \in [1, j]$ 的 $f_{i, k}$ 就可以了，于是对行和列分别维护树状数组。

时间复杂度 $\mathcal O(n k \log n)$。

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>

const int N = 1e4;

int n, K, m, a[N], c[2][5505][505];

void add(int x, int y, int d) {
    for (int i = x; i <= m; i += i & ~i + 1)
        c[0][i][y] = std::max(c[0][i][y], d);

    for (int i = y; i <= K + 1; i += i & ~i + 1)
        c[1][x][i] = std::max(c[1][x][i], d);
}

int ask(int x, int y) {
    int res = 0;

    for (int i = x; i; i &= i - 1)
        res = std::max(res, c[0][i][y]);

    for (int i = y; i; i &= i - 1)
        res = std::max(res, c[1][x][i]);

    return res;
}

int main() {
    scanf("%d%d", &n, &K);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), m = std::max(m, a[i]);

    m += K;

    for (int i = 1; i <= n; i++)
        for (int j = K; ~j; j--)
            add(a[i] + j, j + 1, ask(a[i] + j, j + 1) + 1);

    printf("%d", ask(m, K + 1));
    return 0;
}
```

##  Luogu   P2605   基站选址

首先写出状态转移方程再优化。

$f_{i, j}$ 表示第 $j$ 个基站建在 $i$ 的最小花费。

$$f_{i, j} = \min \\{ f_{k, j - 1} + pay(k, i) \\} + c_i$$

转移是 $\mathcal O(n^2 k)$ 的，只有 40 分。

可以用分层 DP 把 $j$ 压掉。

我们考虑如何快速计算 $pay(k, i)$。

首先对于每个村庄，用二分求出能够覆盖它的基站位置 $[st_i, ed_i]$。

对于 $i$ 位置的基站，在决策之后枚举所有 $ed_j = i$ 的村庄 $j$。

由于 $i$ 是最后一个建基站使得村庄 $j$ 的位置，那么对于 $i$ 后面的位置，再建基站就无法覆盖到村庄 $j$ 了。

再来考虑村庄 $j$ 无法被前面的基站覆盖的情况，就是上一个基站建到了 $st_j$ 前面到情况。

总结一下，在第 $i$ 个位置决策结束之后，枚举所有以 $i$ 为 $ed_j$ 的村庄 $j$，将 $w_j$ 作为 $pay$ 累加到 $[1, st_j - 1]$ 的上一层状态中。

这样我们就不用每次转移分别计算 $pay$ 了。

显然这是可以用线段树优化的。

时间复杂度 $\mathcal O(n k \log n)$。

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

#define N 2001001
#define inf 1e18
#define register

typedef long long lxl;

lxl n, m, d[N], c[N], s[N], w[N], st[N], ed[N], f[N], ans;
std::vector<lxl>v[N];

struct node {
    lxl l, r, mid, val;
    lxl tag;
} seg[N];

void pushup(lxl pos) {
    seg[pos].val = std::min(seg[pos << 1].val, seg[pos << 1 | 1].val);
    return;
}

void build(lxl pos, lxl l, lxl r) {
    seg[pos].l = l, seg[pos].r = r, seg[pos].mid = l + r >> 1, seg[pos].tag = 0;

    if (l == r)
        seg[pos].val = f[l];
    else {
        build(pos << 1, l, seg[pos].mid);
        build(pos << 1 | 1, seg[pos].mid + 1, r);
        pushup(pos);
    }

    return;
}

void add(lxl pos, lxl num) {
    seg[pos].val += num, seg[pos].tag += num;
    return;
}

void pushdown(lxl pos) {
    add(pos << 1, seg[pos].tag);
    add(pos << 1 | 1, seg[pos].tag);
    seg[pos].tag = 0;
    return;
}

void modify(lxl pos, lxl l, lxl r, lxl num) {
    if (seg[pos].l >= l && seg[pos].r <= r)
        return add(pos, num);
    else if (seg[pos].l > r || seg[pos].r < l)
        return;

    pushdown(pos);
    modify(pos << 1, l, r, num);
    modify(pos << 1 | 1, l, r, num);
    pushup(pos);
    return;
}

lxl query(lxl pos, lxl l, lxl r) {
    if (seg[pos].l >= l && seg[pos].r <= r)
        return seg[pos].val;
    else if (seg[pos].l > r || seg[pos].r < l)
        return inf;

    pushdown(pos);
    return std::min(query(pos << 1, l, r), query(pos << 1 | 1, l, r));
}

int main() {
    std::cin >> n >> m;

    for (int i = 2; i <= n; i++) std::cin >> d[i];
    for (int i = 1; i <= n; i++) std::cin >> c[i];
    for (int i = 1; i <= n; i++) std::cin >> s[i];
    for (int i = 1; i <= n; i++) std::cin >> w[i];

    n++, m++;
    d[n] = w[n] = inf;

    for (int i = 1; i <= n; i++) {
        st[i] = std::lower_bound(d + 1, d + n + 1, d[i] - s[i]) - d;
        ed[i] = std::upper_bound(d + 1, d + n + 1, d[i] + s[i]) - d - 1;
        v[ed[i]].push_back(i);
    }

    lxl now = 0;

    for (int i = 1; i <= n; i++) {
        f[i] = now + c[i];

        for (int j = 0; j < v[i].size(); j++) {
            lxl to = v[i][j];
            now += w[to];
        }
    }

    ans = f[n];

    for (int i = 2; i <= m; i++) {
        build(1, 1, n);

        for (int j = 1; j <= n; j++) {
            f[j] = query(1, 1, j - 1) + c[j];

            for (int k = 0; k < v[j].size(); k++) {
                lxl to = v[j][k];
                modify(1, 1, st[to] - 1, w[to]);
            }
        }

        ans = std::min(ans, f[n]);
    }

    std::cout << ans << '\n';
    return 0;
}
```

##  Luogu   P2627   Mowing the lawn

记 $f_{i, 0/1}$ 表示前 $i$ 头奶牛，第 $i$ 头选或不选的最高效率。

$$
\begin{aligned}
    f_{i, 0} & = \max(f_{i - 1, 0}, f_{i - 1, 1}) \\
    f_{i, 1} & = \max_{i - k \le j \lt i} f_{j, 0} + \sum_{k = j + 1}^i e_k
\end{aligned}
$$

使用前缀和优化。

$$
\begin{aligned}
    f_{i, 1} & = \max_{i - k \le j \lt i} f_{j, 0} + p_i - p_j \\
    & = \max_{i - k \le j \lt i} f_{j, 0} - p_j + p_i
\end{aligned}
$$

使用单调队列优化 $\max_{i - k \le j \lt i} f_{j, 0} - p_j$，时间复杂度 $\mathcal O(n)$。

```cpp
#include <iostream>

using namespace std;

int n, k;

int a[100010];
long long f[100010];
long long sum, ans;
int q[100010], head, tail;

int main(){
	cin >> n >> k;
	
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		sum += a[i];
	}
	
	q[tail++] = 0;
	
	for (int i = 1; i <= n; i ++){
		while (head < tail && q[head] < i - k - 1){
			head ++;
		}
		
		f[i] = f[q[head]] + a[i];
		
		while (head < tail && f[i] < f[q[tail-1]]){
			tail --;
		}
		
		q[tail++] = i;
	}
	
	for (int i = n - k; i <= n; i ++){
		ans = max(ans, sum - f[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
```

##  HDU     3507    Print article

记 $f_i$ 表示前 $i$ 个数的最小代价。

$$
\begin{aligned}
    f_i & = f_j + (p_i - p_j)^2 + m \\
    f_i & = f_j + p_i^2 + p_j^2 - 2 p_i p_j + m \\
    f_j + p_j^2 & = 2 p_i p_j + f_i - p_i^2 - m
\end{aligned}
$$

使用斜率优化。

```cpp
#include <cstdio>

const int maxN = 5e5 + 10;

int q[maxN], f[maxN];
int sum[maxN];
int n, m;

int up(int i, int j) {
    return f[i] + sum[i] * sum[i] - (f[j] + sum[j] * sum[j]);
}

int down(int i, int j) {
    return 2 * (sum[i] - sum[j]);
}

int calc(int i, int j) {
    return f[j] + (sum[i] - sum[j]) * (sum[i] - sum[j]) + m;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        sum[0] = f[0] = 0;

        for (int i = 1; i <= n; i++)
            scanf("%d", &sum[i]), sum[i] += sum[i - 1];

        int tail = 0, head = 0;
        q[tail++] = 0;

        for (int i = 1; i <= n; i++) {
            while (head + 1 < tail && up(q[head + 1], q[head]) <= sum[i]*down(q[head + 1], q[head]))
                head++;

            f[i] = calc(i, q[head]);

            while (head + 1 < tail && up(i, q[tail - 1])*down(q[tail - 1], q[tail - 2]) <= up(q[tail - 1], q[tail - 2])*down(i, q[tail - 1]))
                tail--;

            q[tail++] = i;

        }

        printf("%d\n", f[n]);
    }

    return 0;
}
```

##  UVA     10304   Optimal binary search tree

按点权排序。

记 $f_{i, j}$ 表示 $[i, j]$ 合并为一棵树的最小费用。

$$f_{i, j} = \min_{i \lt k \lt j} f_{i, k - 1} + sum_{i, j} - val_k + f_{k + 1, j}$$

直接转移是 $\mathcal O(n^3)$，可以使用四边形不等式优化到 $\mathcal O(n^2)$。

```cpp
#include <iostream>
#include <algorithm>

const int maxN = 300;
const int inf = 0x3f3f3f3f;

int n;
int f[maxN][maxN], s[maxN], c[maxN];

void init() {
    s[0] = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
        s[i] = s[i - 1] + c[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[i][j] = inf;

    for (int i = 1; i <= n; i++)
        f[i][i - 1] = f[i + 1][i] = 0;

    return;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        init();

        for (int k = 0; k < n; k++) {
            for (int i = 1; i + k <= n; i++) {
                for (int j = i; j <= i + k; j++) {
                    int res = f[i][j - 1] + f[j + 1][i + k] + s[i + k] - s[i - 1] - c[j];
                    f[i][i + k] = std::min(f[i][i + k], res);
                }
            }
        }

        printf("%d\n", f[1][n]);
    }

    return 0;
}
```