---
layout: post
title:  乌鲁木齐市第一中学2025届2022-2023年度寒假作业
date:   2023-01-31
categories: whk fault
---

## 必修一第四章综合训练

### 一、选择题

#### 3.

> 已知定义在 $\R$ 上的函数 $y = f(x)$ 对任意的 $x$ 都满足 $f(x + 1) = - f(x),$ 当 $-1 \le x \lt 1$ 时$,$ $f(x) = x^3,$ 若函数 $g(x) = f(x) - \log_a \lvert x \rvert$ 至少 $6$ 个零点$,$ 则 $a$ 的取值范围是

关于 $f(x)$ 的条件有两个：

1. 对任意的 $x$ 都满足 $f(x + 1) = - f(x)$；
2. 当 $-1 \le x \lt 1$ 时$,$ $f(x) = x^3$

尝试从条件 $1$ 发掘 $f(x)$ 的性质$,$ 并从条件 $2$ 开始推广$.$

带负号很烦$,$ 考虑通过负负得正$,$ 即二次转换消去负号$.$

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

故 $f(x)$ 是周期为 $2$ 的周期函数$.$

由 $-1 \le x \lt 1$ 时$,$ $f(x) = x^3,$ 结合函数周期推导出函数图像$.$

考虑函数 $g(x)$ 的图像意义$.$函数 $g(x) = f(x) - \log_a \lvert x \rvert$ 的零点个数$,$ 即函数 $y = f(x)$ 与 $y = \log_a \lvert x \rvert$ 的交点的个数$.$

根据图像可知$,$ 若要函数 $g(x)$ 至少 $6$ 个零点$,$ 则 $\log_a 5 \lt 1$ 或 $\log_a 5 \ge -1.$

解得 $a \gt 5,$ 或 $0 \lt a \le \frac{1}{5}.$

当 $a = 5$ 时$,$ 恰好有 $6$ 个交点$,$ 左边 $4$ 个$,$ 右边 $2$ 个$.$

综上所述$,$ $a$ 当取值范围是 $(0, \frac{1}{5}] \cup (5, + \infty).$

#### 4.

> 若关于 $x$ 的方程 $x + \log_5 x = 4$ 与 $x + 5^x = 4$ 的根分别为 $m, n,$ 则 $m + n$ 的值为

观察到两个方程左侧均有 $x,$ 右侧均有 $4,$ 考虑移项$.$

通过移项得：

$$
\begin{aligned}
    \log_5 x & = 4 - x \\
    5^x & = 4 - x
\end{aligned}
$$

记 $f(x) = \log_5 x,$ 其反函数 $f^{-1}(x) = 5^x,$ 它们的图像关于直线 $y = x$ 对称$.$

根据题意$,$ $m, n$ 为 $f(x), f^{-1}(x)$ 的图像与直线 $y = 4 - x$ 交点 $M, N$ 的横坐标$.$

由于两焦点关于直线 $y = x$ 对称$,$ 则 $N$ 点的横坐标就是 $M$ 点的纵坐标$,$ $M$ 点的横坐标就是 $N$ 点的纵坐标$,$ 即 $M(m, n), N(n, m).$

将 $M(m, n)$ 代入 $y = 4 - x$ 得$,$ $m + n = 4.$

#### 10.

> 已知函数 $f(x) = \begin{cases} 2 - \lvert x \rvert, & x \le 2, \\ (x - 2)^2, & x \gt 2, \end{cases}$ 函数 $g(x) = b - f(2 - x),$ 若 $g(x)$ 存在两个零点$,$ 则 $a$ 的取值范围是

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

$y = f(x) - g(x) = f(x) + f(2 - x) - b,$ 所以 $y = f(x) - g(x)$ 恰有 $4$ 个零点等价于方程 $f(x) + f(2 - x) - b = 0$ 有 $4$ 个不同的解$,$ 即函数 $y = b$ 与函数 $y = f(x) + f(2 - x)$ 的图像的 $4$ 个公共点$.$

由图可知 $\frac{7}{4} \lt b \lt 2.$

#### 11.

> 已知函数 $f(x) = \begin{cases} e^x, & x \le 0 \\ \ln x, & x \gt 0 \end{cases}, g(x) = f(x) + x + a,$ 若 $g(x)$ 存在两个零点$,$ 则 $a$ 的取值范围是

令 $h(x) = - x - a,$ 则 $g(x) = f(x) - h(x).$

若 $g(x)$ 存在 $2$ 个零点$,$ 则 $y = f(x)$ 的图像与 $y = h(x)$ 的图像有 $2$ 个交点$.$

综上$,$ $a$ 的取值范围为 $[1, + \infty).$

#### 12.

> 已知函数 $f(x) = \begin{cases} e^{\lvert x - 1 \rvert}, & x \gt 0 \\ - x^2 - 2x + 1, & x \le 0 \end{cases},$ 若关于 $x$ 的方程 $f^2(x) - 3f(x) + a = 0 (a \in \R)$ 有 $8$ 个不等的实数根$,$ 则 $a$ 的取值范围是

令 $f(x) = t,$ 由题意可知$,$ $t = f(x)$ 必须有 $4$ 个不相等的实数根$,$ 方程 $t^2 - 3t + a = 0$ 在区间 $(1, 2)$ 上有两个不同的实数根$.$

令 $g(t) = t^2 - 3t + a (1 \lt t \lt 2),$ 由题意可知：

$$
\begin{cases}
    g(1) = 1 - 3 + a \gt 0, \\
    g(2) = 4 - 6 + a \gt 0, \\
    g(\frac{3}{2}) = \frac{9}{4} - \frac{9}{2} + a \lt 0,
\end{cases}
$$

据此可的：$2 \lt a \lt \frac{9}{4},$ 即 $a$ 的取值范围是 $(2, \frac{9}{4}).$

### 二、填空题

### 三、解答题

#### 19.

> 已知 $\log_{14} 7 = a, \log_{14} 5 = b,$ 则用 $a, b$ 表示 $\log_{35} 28$

$$
\begin{aligned}
    & \log_{35} 28 \\
    = & \frac{\log_{14} 28}{\log_{14} 35} \\
    = & \frac{\log_{14} 14 + \log_{14} 2}{\log_{14} 7 + \log_{14} 5} \\
    = & \frac{\log_{14} 14 + \log_{14} \frac{14}{7}}{\log_{14} 7 + \log_{14} 5} \\
    = & \frac{\log_{14} 14 + \log_{14} 14 - \log_{14} 7}{\log_{14} 7 + \log_{14} 5} \\
    = & \frac{2 - a}{a + b}
\end{aligned}
$$

> 比较大小：$a = (\frac{1}{2})^{\frac{2}{3}}, b = (\frac{1}{5})^{\frac{2}{3}}, c = (\frac{1}{2})^{\frac{1}{3}}$

$\because y = x^{\frac{2}{3}}$ 在 $[0, + \infty)$ 上单调递增

$\therefore (\frac{1}{2})^{\frac{2}{3}} \gt (\frac{1}{5})^{\frac{2}{3}}, a \gt b$

又 $y = x^{\frac{1}{3}}$ 在 $[0, + \infty)$ 上单调递增

$\therefore (\frac{1}{2})^{\frac{1}{3}} \gt (\frac{1}{4})^{\frac{1}{3}} = (\frac{1}{2})^{\frac{2}{3}}, c \gt a$

$\therefore b \lt a \lt c$

> 比较大小：$a = 5^{\log_2 3.4}, b = 5^{\log_4 3.6}, c = (\frac{1}{5})^{\log_3 0.3}$

$c = (\frac{1}{5})^{\log_3 0.3} = 5^{\log_3 \frac{10}{3}}$

$\because \log_4 3.6 \lt \log_4 4 = 1, 1 \lt \log_3 \frac{10}{3} \lt \log_2 \frac{10}{3} \lt \log_2 3.4$

$\therefore 5^{\log_4 3.6} \lt 5^{\log_3 \frac{10}{3}} \lt 5^{\log_2 3.4}$

即 $b \lt c \lt a$

#### 22

## 高一上学期数学第五章：三角函数

### 一、选择题

#### 4.

> 将函数 $f(x) = \sin (2x + \frac{\pi}{4})$ 的图像向右平移 $\varphi$ 个单位与函数 $g(x) = \cos 2x$ 的图像重合$,$ 则 $\varphi$ 可以是

由题可知$,$ 

$$
\begin{aligned}
    f(x - \varphi) & = \sin (2(x - \varphi) + \frac{\pi}{4}) \\
    & = \sin (2x + \frac{\pi}{2} - 2\varphi)
\end{aligned}
$$

$\because g(x) = \cos 2x = \sin (2x + \frac{\pi}{2}),$

$\therefore 2x + \frac{\pi}{4} - 2\varphi = 2x + \frac{\pi}{2} + 2k\pi,$

$\therefore \varphi = - k\pi - \frac{1}{8}\pi,$ 当 $k = - 1$ 时$,$ $\varphi = \frac{7\pi}{8}$

#### 7.

> 已知函数 $f(x) = A \sin (\omega x + \varphi) (A \gt 0, \omega \gt 0)$ 在区间 $[\frac{\pi}{6}, \frac{\pi}{2}]$ 上单调$,$ 且 $f(\frac{\pi}{2}) = f(\frac{2\pi}{3}) = - f(\frac{\pi}{6}),$ 则 $f(x)$ 的最小正周期为

$\because$ 函数 $f(x) = \sin (\omega x + \varphi), A \gt 0, \omega \gt 0,$ 若 $f(x)$ 在区间 $[\frac{\pi}{6}, \frac{\pi}{2}]$ 上单调$,$ 

$\therefore \frac{\pi}{2} - \frac{\pi}{6} \le \frac{T}{2} = \frac{1}{2} \cdot \frac{2\pi}{\omega} = \frac{\pi}{\omega},$ 即 $\frac{\pi}{3} \le \frac{\pi}{\omega},$ 

$\therefore 0 \lt \omega \le 3, T \ge \frac{2\pi}{3}$

$\because f(\frac{\pi}{2}) = f(\frac{2\pi}{3}) = - f(\frac{\pi}{6}), \frac{2\pi}{3} - \frac{\pi}{2} \lt T$

$\therefore x = \frac{\frac{\pi}{6} + \frac{2\pi}{3}}{2} = \frac{7\pi}{12},$ 为 $f(x) = \sin (\omega x + \varphi)$ 的一条对称轴$,$ 

且 $(\frac{\frac{\pi}{6} + \frac{\pi}{2}}{2}, 0)$ 即 $(\frac{\pi}{3}, 0)$ 为 $f(x) = \sin (\omega x + \varphi)$ 的一个对称中心

$\because 0 \lt \omega \le 3$

$\therefore x = \frac{7\pi}{12}$ 与 $(\frac{\pi}{3}, 0)$ 为同一周期里相邻的对称轴和对称中心

$\therefore \frac{T}{4} = \frac{1}{4} \cdot \frac{2\pi}{\omega} = \frac{7\pi}{12} - \frac{\pi}{3} = \frac{\pi}{4},$ 解得 $\omega = 2 \in (0, 3]$

$\therefore T = \frac{2\pi}{2} = \pi$

#### 8.

> 将函数 $f(x) = \sin \omega x (\omega \gt 0)$ 的图像向右平移 $\frac{\pi}{12}$ 个单位长度得到函数 $y = g(x)$ 的图像$,$ 若函数 $g(x)$ 在区间 $[0, \frac{\pi}{2}]$ 上时单调增函数$,$ 则实数 $\omega$ 可能的取值为

$g(x) = \sin (\omega x - \frac{\omega \pi}{23})$

若函数 $g(x)$ 在区间 $[0, \frac{\pi}{2}]$ 上时单调增函数$,$ 则满足

$$
\begin{cases}
    - \frac{\omega \pi}{12} & \ge - \frac{\pi}{2} \\
    \frac{\omega \pi}{2} - \frac{\omega \pi}{12} & \le \frac{\pi}{2}
\end{cases}
$$

解得 $0 \lt \omega \le \frac{6}{5}$

### 二、多选题

#### 11.

$h(x) = \frac{1}{2} \sin 2x$ 的振幅为 $\frac{1}{2},$ $f(\frac{\pi}{2}) = 1 + 0 - \frac{1}{3} + 0 = \frac{2}{3},$ 则 $f(x)_{\max} \ge \frac{2}{3},$ 所以 $f(x)$ 的振幅大于 $h(x)$ 的振幅$,$ 故声音的响度一定比纯音 $h(x)$ 的响度大$.$

$g(x) = \sin x + \frac{1}{2} \sin 2x$ 的周期为 $2\pi,$ 则其频率为 $\frac{1}{2\pi},$ $m(x) = \frac{1}{3} = \frac{1}{3} \sin 3x$ 的周期为 $\frac{2\pi}{3},$ 其频率为 $\frac{3}{2\pi},$ 由 $\frac{1}{2\pi} \lt \frac{3}{2\pi},$ 得声音比纯音 $m(x)$ 低沉$.$

### 三、填空题

#### 13.

> 一直 $\alpha \in (0, \frac{\pi}{2}), \sin (\alpha - \frac{\pi}{6}) = \frac{1}{3},$ 则 $\sin \alpha$ 的值为

$\because \alpha \in (0, \frac{\pi}{2}),$

$\therefore \alpha 0 \frac{\pi}{6} \in (- \frac{\pi}{6}, \frac{\pi}{3}),$

又 $\because \sin (\alpha - \frac{\pi}{6}) = \frac{1}{3},$

$\therefore \cos (\alpha - \frac{\pi}{6}) = \sqrt {1 - (\frac{1}{3})^2} = \frac{2 \sqrt 2}{3},$

$
\begin{aligned}
    \therefore \sin \alpha & = \sin [(\alpha - \frac{\pi}{6}) + \frac{\pi}{6}] \\
    & = \sin (\alpha - \frac{\pi}{6}) \cos \frac{\pi}{6} + \cos (\alpha - \frac{\pi}{6}) \sin \frac{\pi}{6} \\
    & = \frac{\sqrt 3 + 2 \sqrt 2}{6}.
\end{aligned}
$

### 四、解答题

#### 17.

> 已知 $\tan \alpha = 2,$ 求 $\sin \alpha \cdot \alpha$ 的值

$\because \tan \alpha = 2$

$\therefore \frac{\sin \alpha}{\cos \alpha} = 2$

又 $\because \sin^2 \alpha + \cos^2 \alpha = 1$

$\therefore \sin \alpha = 2\cos \alpha$

$\therefore 4\cos^2 \alpha + \cos^2 \alpha = 1$

$\therefore \cos^2 \alpha = \frac{1}{5}$

$\because \tan \alpha = 2 \gt 0$

$\therefore \sin \alpha, \cos \alpha$ 同号

即 $\sin \alpha \cdot \cos \alpha \gt 0$

$
\begin{aligned}
    (\sin \alpha \cdot \cos \alpha)^2 & = \sin^2 \alpha \cdot \cos^2 \alpha \\
    & = 4\cos^2 \alpha \cdot \cos^2 \alpha \\
    & = \frac{4}{25}
\end{aligned}
$

$\therefore \sin \alpha \cdot \cos \alpha = \frac{2}{5}$

#### 19.

> 已知函数 $f(x) = a - b \cos (2x + \frac{\pi}{6}) (b \gt 0)$ 的最大值为 $\frac{3}{2},$ 最小值为 $- \frac{1}{2}.$ 求 $a, b$ 的值$.$


$\because b \gt 0,$

$\therefore - b \lt 0.$

又 $\cos (2x + \frac{\pi}{6}) \in [-1, 1],$

$\therefore
\begin{cases}
    f(x)_{\max} = b + a = \frac{3}{2}, \\
    f(x)_{\min} = - b + a = - \frac{1}{2},
\end{cases}
$

$\therefore
\begin{cases}
    a = \frac{1}{2}, \\
    b = 1.
\end{cases}
$

#### 20.

> 已知函数 $f(x) = A\sin (\omega x + \varphi) (A \gt 0, \omega \gt 0, \lvert \varphi \rvert \lt \frac{\pi}{2})$ 的部分图像如图$.$ 求函数 $f(x)$ 的解析式$.$

由图像可知$,$ $A = 2,$

周期 $T = \frac{4}{3} [\frac{5\pi}{12} - (- \frac{\pi}{3})] = \pi,$

$\therefore \frac{2\pi}{\lvert \omega \rvert} = \pi, \omega \gt 0,$ 则 $\omega = 2,$

从而 $f(x) = 2\sin (2x + \varphi),$

代入点 $(\frac{5\pi}{12}, 2),$ 得 $\sin (\frac{5\pi}{6} + \varphi) = 1,$

则 $\frac{5\pi}{6} + \varphi = \frac{\pi}{2} + 2k\pi, k \in \Z,$

即 $\varphi = - \frac{\pi}{3} + 2k\pi, k \in \Z,$

又 $\lvert \varphi \rvert \lt \frac{\pi}{2},$

则 $\varphi = - \frac{\pi}{3},$

$\therefore f(x) = 2\sin (2x - \frac{\pi}{3}).$

#### 21.

> 已知函数 $f(x) = - \cos^2 x + \cos x + a.$ 若方程 $f(x) = 0$ 有解$,$ 求实数 $a$ 的取值范围$.$

令 $t = \cos x, t \in [-1, 1], a = t^2 - t.$

令 $g(t) = t^2 - t = (t - \frac{1}{2})^2 - \frac{1}{4},$

$\because t \in [-1, 1],$

当 $t \in [-1, \frac{1}{2}]$ 时$,$ $g(t)$ 单调递减$,$

当 $t \in [\frac{1}{2}, 1]$ 时$,$ $g(t)$ 单调递增$,$

且 $\frac{1}{2} - (- 1) \gt 1 - \frac{1}{2},$

$\therefore g(t)_{\min} = g(\frac{1}{2}) = - \frac{1}{4},$

$g(t)_{\max} = g(-1) = 2,$

即 $g(t) \in [- \frac{1}{4}, 2],$

所以实数 $a$ 的取值范围为 $[- \frac{1}{4}, 2].$

## 高一上学期数学综合练习（一）

### 一、单项选择题

#### 4.

> 已知 $f(x)$ 是定义在 $(0, + \infty)$ 上的单调函数$,$ 满足 $f(f(x) - e^x - 2\ln x + 2) = e - 1,$ 则函数 $f(x)$ 的零点所在区间为

根据题意$,$ $f(x) - e^x - 2\ln x + 2$ 为定值$,$

设 $t = f(x) - e^x - 2\ln x + 2,$

则 $f(x) = e^x + 2\ln x + t - 2,$

又由 $f(t) = e - 1,$

解得 $t = 1,$

则 $f(x) = - 1 + 2\ln x + e^x, f'(x) = \frac{2}{x} + d^x \gt 0,$

可得 $f(x)$ 在 $x \gt 0$ 递增$,$

$f(\frac{1}{e}) = e^{\frac{1}{e}} - 2 + 1 - 1 \lt 0,$

$f(1) = e - 1 \gt 0,$

则 $f(x)$ 在 $(\frac{1}{e}, 1)$ 有零点$.$

#### 5.

> 已知正数 $x, y, z,$ 满足 $3^x = 4^y = 6^z,$ 则下列说法不正确的是

设 $3^x = 4^y = 6^z = t (t \gt 1),$ 则 $x = \frac{1}{\log_t 3}, y = \frac{1}{\log_t 4}, z = \frac{1}{\log_t 6}.$

$\frac{1}{x} + \frac{1}{2y} = \log_t 3 + \frac{1}{2} \log_t 4 = \log_t 6 = \frac{1}{z};$

$\frac{4}{x} = 4\log_t 3 = \log_t 81, \frac{3}{y} = 3\log_t 4 = \log_t 64, \log_t 81 - \log_t 64 = \log_t \frac{81}{64} \gt 0,$ 所以 $\frac{4}{x} \gt \frac{3}{y},$ 即 $3x \lt 4y;$

$\frac{x + y}{z} = \frac{x}{z} + \frac{y}{z} = \frac{\lg 6}{\lg 3} + \frac{\lg 6}{\lg 4} = \frac{3}{2} + (\frac{\lg 2}{\lg 3} + \frac{\lg 3}{2\lg 2}) \gt \frac{3}{2} + \sqrt 2;$

$\frac{xy}{z^2} = \frac{x}{z} \times \frac{y}{z} = \frac{\lg 6}{\lg 3} \times \frac{\lg 6}{\lg 4} = \frac{(\lg 6)^2}{\lg 3 \times 2\lg 2} = \frac{(\lg 2)^2 + 2\lg 2 \times \lg 3 + (\lg e)^2}{2\lg 2 \times \lg 3} = 1 + \frac{1}{2} (\frac{\lg 2}{\lg 3} + \frac{\lg 3}{\lg 2}) \gt 2.$

### 二、多项选择题

#### 10.

> 已知函数 $f(x), g(x)$ 的定义域均为 $\R,$ $f(x)$ 为偶函数，且 $f(x) + g(2 - x) = 1, g(x) - f(x - 4) = 3,$ 下列说法正确的是

用 $2 - x$ 代换 $g(x) - f(x - 4) = 3$ 中的 $x,$ 得 $g(2 - x) - f(- 2 - x) = 3,$

$\because f(x) + g(2 - x) = 1,$

$\therefore f(x) + f(- 2 - x) = - 2,$

$\therefore f(x)$ 的图像关于点 $(- 1, - 1)$ 对称$;$

$\because f(x)$ 是偶函数$,$

$\therefore f(x) + f(2 + x) = -2,$

即 $f(2 + x) = - f(x) - 2,$

$\therefore f(x + 4) = - f(x + 2) - 2 = - [- f(x) - 2] - 2 = f(x),$

$\therefore$ 函数 $f(x)$ 是以 $4$ 为周期的周期函数$;$

$\because g(x) - f(x - 4) = 3,$ $f(x)$ 是以 $4$ 为周期的周期函数$,$

$\therefore g(x) - f(x) = 3,$

又 $f(x) + g(2 - x) = 1,$

$\therefore g(x) + g(2 - x) = 4,$

$\therefore$ 函数 $g(x)$ 的图像关于点 $(1, 2)$ 对称$;$

由 $f(x) + g(2 - x) = 1,$

得 $f(x) = 1 - g(2 - x),$

$\because f(x)$ 是以 $4$ 为周期的周期函数$,$

即 $f(x) = f(x + 4),%

$\therefore 1 - g(2 - x) = 1 - g(2 - x - 4),$

即 $g(2 - x) = g(- 2 - x),$

用 $- 2 - x$ 代换 $x,$

得 $g(x) = g(x + 4),$

$\therefore$ 函数 $g(x)$ 是以 $4$ 为周期的周期函数$.$

### 三、填空题

#### 13.

> 已知函数 $y = \lg (\sqrt {x^2 - x + 1} + ax)$ 的定义域是 $\R,$ 则实数 $a$ 的取值范围是

$\because$ 函数 $y = \lg (\sqrt {x^2 - x + 1} + ax)$ 的定义域是 $\R,$

$\therefore \sqrt {x^2 - x + 1} + ax \gt 0$ 对于任意实数 $x$ 恒成立$,$

即 $ax \gt - \sqrt {x^2 - x + 1}$ 对于任意实数 $x$ 恒成立$,$

当 $x = 0$ 时$,$ 上式