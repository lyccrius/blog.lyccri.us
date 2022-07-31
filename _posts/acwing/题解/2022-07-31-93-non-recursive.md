---
layout: post
title: "AcWing 93. 非递归实现组合型枚举"
date:   2022-07-31
categories: solution acwing
---

> 题目链接：<a href="https://www.acwing.com/problem/content/95/" target="_blank">93. 递归实现组合型枚举 - AcWing题库</a>

```
vector<int> chosen;

int stack[100010], top = 0, address = 0, n, m;

void call(int x, int ret_addr) {
    int old_top = top;

    stack[++ top] = x;
    stack[++ top] = ret_addr;
    stack[++ top] = old_top;

    return;
}

int ret() {
    int ret_addr = stack[top - 1];

    top = stack[top];

    return ret_addr;
}

int main() {
    cin >> n >> m;

    call(1, 0);

    while (top) {
        int x = stack[top - 2];

        switch(address) {
            case 0:
                if (chosen.size() > m || chosen.size() + (n - x + 1) < m) {
                    address = ret();
                    continue;
                }

                if (x == n + 1) {
                    for (int i = 0; i < chosen.size(); i ++) cout << chosen[i] << " ";
                    cout << endl;

                    address = ret();

                    continue;
                }

                call(x + 1, 1);

                address = 0;

                continue;

            case 1:
                chosen.push_back(x);

                call(x + 1, 2);
                
                address = 0;

                continue;

            case 2:
                chosen.pop_back();
                address = ret();
        }
    }
}
```

> 完整代码：<a href="https://gitee.com/lyccrius/oi/blob/master/www.acwing.com/problem/content/95/非递归实现组合型枚举.cpp" target="_blank">非递归实现组合型枚举</a>