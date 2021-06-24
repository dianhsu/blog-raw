---
toc:
    depth_from: 1
    depth_to: 4
title: 双向搜索 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## 双向搜索
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

[TOC]

---

### 简介

双向搜索算法是一种图的遍历算法，用于在有向图中搜索从一个顶点到另一个顶点的最短路径。算法同时运行两个搜索：一个从初始状态正向搜索，另一个从目标状态反向搜索，当两者在中间汇合时搜索停止。在很多情况下该算法更快，假设搜索一棵分支因子$b$的树，初始节点到目标节点的距离为$d$，该算法的正向和反向搜索复杂度都是$ O(b^{d/2}) $，两者相加后远远小于普通的单项搜索算法（复杂度为$O(b^d)$）。

> 参考：[http://theoryofprogramming.com/2018/01/21/bidirectional-search/](http://theoryofprogramming.com/2018/01/21/bidirectional-search/)

下面是广度优先搜索的示意图
![](https://cdn.dianhsu.top/linux/20210604145843.jpeg)
下面是深度优先搜索的示意图
![](https://cdn.dianhsu.top/linux/20210604145921.jpeg)