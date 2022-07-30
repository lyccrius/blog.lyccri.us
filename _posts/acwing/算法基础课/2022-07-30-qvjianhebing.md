---
layout: post
title: "AcWing 算法基础课 区间合并"
date:   2022-07-30
categories: course acwing sfjck
---

## 合并步骤
1. 按区间左端点排序
2. 扫描整个区间，扫描中把所有可能有交集的区间合并

> 若排序后相邻两个区间可以合并则合并，并记录合并后右端点值；  
> 否则计数器加一。

## 模版
```
void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}
```

## 习题及代码
> <a href="https://www.acwing.com/problem/content/805/" target="_blank">803. 区间合并 - AcWing题库</a>  
> <a href="https://gitee.com/lyccrius/oi/blob/master/www.acwing.com/problem/content/805/区间合并.cpp" target="_blank">区间合并.cpp</a>