---
layout: post
title:  乌鲁木齐市第一中学2025届2022-2023年度寒假作业
date:   2023-02-01
categories: whk fault
---

## 乌鲁木齐市第一中学2025届必修一第四章综合训练 试卷编号：41 出卷人：李国华

### 一、选择题

#### 3.

> 已知定义在 $\R$ 上的函数 $y = f(x)$ 对任意的 $x$ 都满足 $f(x + 1) = - f(x)$，当 $-1 \le x \lt 1$ 时，$f(x) = x^3$，若函数 $g(x) = f(x) - \log_a \lvert x \rvert$ 至少 $6$ 个零点，则 $a$ 的取值范围是

关于 $f(x)$ 的条件有两个：

1. 对任意的 $x$ 都满足 $f(x + 1) = - f(x)$；
2. 当 $-1 \le x \lt 1$ 时，$f(x) = x^3$

尝试从条件 $1$ 发掘 $f(x)$ 的性质，并从条件 $2$ 开始推广。

带负号很烦，考虑通过负负得正，即二次转换消去负号。

由

$$f(x + 1) = -f(x)$$

可得

$$
\begin{aligned}
    f(x + 2) & = f(x + 1 + 1) \\
    & = - f(x + 1) \\
    & = f(x)
\end{aligned}
$$

故 $f(x)$ 是周期为 $2$ 的周期函数。

由 $-1 \le x \lt 1$ 时，$f(x) = x^3$，结合函数周期推导出函数图像。

考虑函数 $g(x)$ 的图像意义。函数 $g(x) = f(x) - \log_a \lvert x \rvert$ 的零点个数，即函数 $y = f(x)$ 与 $y = \log_a \lvert x \rvert$ 的交点的个数。

根据图像可知，若要函数 $g(x)$ 至少 $6$ 个零点，则 $\log_a 5 \lt 1$ 或 $\log_a 5 \ge -1$。

解得 $a \gt 5$，或 $0 \lt a \le \frac{1}{5}$。

当 $a = 5$ 时，恰好有 $6$ 个交点，左边 $4$ 个，右边 $2$ 个。

综上所述，$a$ 当取值范围是 $(0, \frac{1}{5}] \cup (5, + \infty)$。

#### 4.

> 若关于 $x$ 的方程 $x + \log_5 x = 4$ 与 $x + 5^x = 4$ 的根分别为 $m, n$，则 $m + n$ 的值为

观察到两个方程左侧均有 $x$，右侧均有 $4$，考虑移项。

通过移项得：

$$
\begin{aligned}
    \log_5 x & = 4 - x \\
    5^x & = 4 - x
\end{aligned}
$$

记 $f(x) = \log_5 x$，其反函数 $f^{-1}(x) = 5^x$，它们的图像关于直线 $y = x$ 对称。

根据题意，$m, n$ 为 $f(x), f^{-1}(x)$ 的图像与直线 $y = 4 - x$ 交点 $M, N$ 的横坐标。

由于两焦点关于直线 $y = x$ 对称，则 $N$ 点的横坐标就是 $M$ 点的纵坐标，$M$ 点的横坐标就是 $N$ 点的纵坐标，即 $M(m, n), N(n, m)$。

将 $M(m, n)$ 代入 $y = 4 - x$ 得，$m + n = 4$。

#### 10.

> 已知函数 $f(x) = \begin{cases} 2 - \lvert x \rvert, & x \le 2, \\ (x - 2)^2, & x \gt 2, \end{cases}$ 函数 $g(x) = b - f(2 - x)$，若 $g(x)$ 存在两个零点，则 $a$ 的取值范围是

由

$$
f(x) = 
\begin{cases} 
    2 - \lvert x \rvert, & x \le 2, \\
    (x - 2)^2, & x \gt 2,
\end{cases}
$$

得

$$
f(2 - x) = 
\begin{cases}
    2 - \lvert 2 - x \rvert, & x \ge 0, \\
    x^2, & x \lt 0,
\end{cases}
$$

所以

$$
\begin{aligned}
    y & = f(x) + f(2 - x) \\
    & = 
    \begin{cases}
        2 - \lvert x \rvert + x^2, & x \lt 0, \\
        4 - \lvert x \rvert - \lvert 2 - x \rvert, & 0 \le x \le 2, \\
        2 - \lvert 2 - x \rvert + (x - 2)^2, & x \gt 2,
    \end{cases}
\end{aligned}
$$

即

$$
\begin{aligned}
    y & = f(x) + f(2 - x) \\
    & = 
    \begin{cases}
        x^2 + x + 2, & x \lt 0, \\
        2, & 0 \le x \le 2, \\
        x^2 - 5x + 8, & x \gt 2,
    \end{cases}
\end{aligned}
$$

$y = f(x) - g(x) = f(x) + f(2 - x) - b$，所以 $y = f(x) - g(x)$ 恰有 $4$ 个零点等价于方程 $f(x) + f(2 - x) - b = 0$ 有 $4$ 个不同的解，即函数 $y = b$ 与函数 $y = f(x) + f(2 - x)$ 的图像的 $4$ 个公共点。

由图可知 $\frac{7}{4} \lt b \lt 2$。