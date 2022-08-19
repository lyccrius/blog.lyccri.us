---
layout: post
title: "因式定理及根的预备役"
date:   2022-08-19
categories: essay
---

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

$$(x-x_1)(x-x_2)\cdots(x-x_n)$$

那么每个 $$(x-x_i)$$ 都有可能是