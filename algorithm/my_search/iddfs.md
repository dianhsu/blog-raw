---
toc:
    depth_from: 1
    depth_to: 4
title: 迭代深化深度优先搜索 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## 迭代深化深度优先搜索 {ignore=True}
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

[TOC]

---

### 简介
迭代深化深度优先搜索 （iterative deepening depth-first search (IDS or IDDFS))）是对状态空间的搜索策略。它重复地运行一个有深度限制的深度优先搜索，每次运行结束后，它增加深度并迭代，直到找到目标状态。

IDDFS 与广度优先搜索有同样的时间复杂度，而空间复杂度远优。

IDDFS 第一次访问节点的累积顺序是广度优先的。

### 例题

@import "../oj/HDU_3567.md"