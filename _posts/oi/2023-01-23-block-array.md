---
layout: post
title:  数列分块入门
date:   2023-01-23
categories: oi
---

* **区间**：数列中连续一段的元素
* **区间操作**：将某个区间 $[l, r]$ 的所有元素进行某种改动的操作
* **块**：我们将数列划分成若干个不相交的区间，每个区间称为一个块
* **整块**：在一个区间操作时，完整包含于区间的块
* **不完整的块**：在一个区间操作时，只有部分包含于区间的块，即区间左右端点所在的两个块

## [#6277. 数列分块入门 1](https://loj.ac/p/6277)

> 给出一个长为 $n$ 的数列，以及 $n$ 个操作，操作涉及区间加法，单点查值。

数列分块就是把数列中每m个元素打包起来，达到优化算法的目的。

如果我们把每 $m$ 个元素分为一块，共有 $\frac{n}{m}$ 块，每次区间加的操作会涉及 $\mathcal O(\frac{n}{m})$ 个整块，以及区间两侧两个不完整的块中至多 $2m$ 个元素。

我们给每个块设置一个加法标记，每次操作对每个整块直接 $\mathcal O(1)$ 标记，而不完整的块由于元素比较少，暴力修改元素的值。

```cpp
void Modify(int l, int r, int c) {
    if (array[l].bel == array[r].bel) {
        for (int i = l; i <= r; i++) array[i].val += c;
        return;
    }
    for (int a = l; a <= block[array[l].bel].r; a++) array[a].val += c;
    for (int a = block[array[r].bel].l; a <= r; a++) array[a].val += c;
    for (int b = array[l].bel + 1; b < array[r].bel; b++) block[b].tag += c;
    return;
}
```

每次询问时返回元素的值加上其所在块的加法标记。

```cpp
int Query(int r) {
    return array[r].val + block[array[r].bel].tag;
}
```

这样每次操作的复杂度是 $\mathcal O(\frac{n}{m} + m)$，根据均值不等式，当 $m$ 取 $\sqrt n$ 时总复杂度最低，为 $\mathcal O(n \sqrt n)$。

## [#6278. 数列分块入门 2](https://loj.ac/p/6278)

> 给出一个长为 $n$ 的数列，以及 $n$ 个操作，操作涉及区间加法，询问区间内小于某个值 $x$ 的元素个数。

数列简单分块问题实际上有三项东西要我们思考：
1. 不完整的块的 $\mathcal O(\sqrt n)$ 个元素怎么处理？
2. $\mathcal O(\sqrt n)$ 个整块怎么处理？
3. 要预处理什么信息（复杂度不能超过后面的操作）？

要在每个整块内寻找小于一个值的元素数，于是我们不得不要求块内元素是有序的，这样就能使用二分法对块内查询，需要预处理时每块做一遍排序，复杂度 $\mathcal O(n \log n)$，每次查询在 $\sqrt n$ 个块内二分，以及暴力 $2 \sqrt n$ 个元素，总复杂度 $\mathcal O(n \log n + n \sqrt n \log \sqrtn)$。

维护一个加法标记，略有区别的地方在于，不完整的块修改后可能会使得该块内数字乱序，所以头尾两个不完整块需要重新排序。

在加法标记下的询问操作，块外还是暴力，查询小于 $x – 加法标记$ 的元素个数，块内用 $x – 加法标记$ 作为二分的值即可。