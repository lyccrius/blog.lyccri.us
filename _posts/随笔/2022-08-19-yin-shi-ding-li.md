---
layout: post
title: "因式定理及根的预备役"
date:   2022-08-19
categories: essay
---

> 本来想用 GoodNotes 5 作手写笔记，
> 
> 但是发现我写的字不是很好看？

## 因式定理

若 $$a$$ 是一元多项式 $$f(x)$$ 的根，

即 $$f(a)=0$$ 成立，

则多项式 $$f(x)$$ 有一个因式 $$x-a$$.

### 推论

$$a1a2x^2+a1b2x+a2b1x+b1b2$$

$$=(a1x+b1)(a2x+b2)$$

$$=a1(x+{b1\over a1})a2(x+{b2\over a2})$$

$$=a1a2(x+{b1\over a1})(x+{b2\over a2})$$

根据因式定理：

$$\because (x+{b1\over a1}),(x+{b2\over a2})$$ 是一元多项式 $$f(x)$$ 的因式

即 $$(x-(-{b1\over a1})),，(x-(-{b2\over a2}))$$ 是一元多项式 $$f(x)$$ 的因式

$$\therefore -{b1\over a1},-{b2\over a2}$$ 是一元多项式 $$f(x)$$ 的根

同理，对与一个 $$n$$ 次 $$n+1$$ 项式，$$-{b_i\over a_i}(1\le i\le n)$$ 是它的根。

## 根的预备役

把可能成为多项式的根的式子，叫做根的预备役。

已知一个 $$n$$ 次 $$n+1$$ 项式：

$$a_nx^n+a_{n-1}x^{n-1}+\cdots+a_1x^1+a_0$$

可因式分解为：

$$(a_{n1}x-x_1)(a_{n2}x-x_2)\cdots(a_{n3}x-x_n)$$

$$a_{xi}$$ 表示 $$a_x$$ 的第 $$i$$ 个因数。

那么每个 $$(a_{ni}x-x_i)$$ 都有可能是多项式的因式，

且每个 $${x_i\over a_{ni}}$$ 都用可能是多项式的根。

## 例题

$$9x^4-3x^3+7x^2-3x-2$$ 是一个四次五项式，$$n=4$$。

$$\therefore a_n=9,a_0=-2$$

记 $$p\in\{x\in Z|kx=a_n=9,k\in Z\}=\{\pm 1,\pm 3,\pm 9\},$$

$$q\in\{x\in Z|kx=a_0=-2,k\in Z\}=\{\pm 1,\pm 2\}$$

根据因式定理的推论得：

$$q_i\over p_j$$ 可能是原多项式的一个根，

$$(x-{q_i\over p_j})$$ 可能是原多项式的一个因式。

$${q_i\over p_j}\in\{\pm{1},\pm{2},\pm{1\over3},\pm{2\over3},\pm{1\over9},\pm{2\over9}\}(1\le i\le n,1\le j\le n)$$

根据预备役中每个根 $${q_i\over p_j}$$ 得出因式 $$(x-{q_i\over p_j})$$，

代入原多项式并用短除法检验。