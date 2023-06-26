---
layout: post
title:  经验主义
date:   2023-06-24
categories: oi
---

*   [UR #5](http://blog.lyccrius.site/solution/uoj/ur-4)
    *   打表猜结论
    *   样例可能是构造的提示
    *   图上边有限制可以往补图上想
    *   复杂度形如 $\mathcal O(q n^a)$ 的算法尝试拆成 $\mathcal O(n^a + qn^b)$，其中 $a \gt b$ 以处理 $q$ 变大的情况
    *   利用部分分中的变量间关系的特殊条件化简式子
    *   化简式子时尽可能将不相关的信息拆开