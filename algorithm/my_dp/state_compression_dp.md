---
toc:
    depth_from: 1
    depth_to: 4
title: 状态压缩动态规划 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## 状态压缩动态规划
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

[TOC]

---

### 介绍

状压 dp 是动态规划的一种，通过将状态压缩为整数来达到优化转移的目的。

状态压缩动态规划通常有个特点，初看数据范围很小，又要考虑状态转移，实则状态的存储很占用空间，这样多半可以考虑用 $2^n$ 的形式进行状态存储。

#### Tips
> 参考：[https://cp-algorithms.com/algebra/all-submasks.html#toc-tgt-0](https://cp-algorithms.com/algebra/all-submasks.html#toc-tgt-0)

如何遍历当前状态的所有子状态呢？

```cpp
for (int cur = status; cur; cur = (cur - 1) & state){
    // do something...
}
```
如果遍历所有状态的子状态：
```cpp
for(int state = 0; state < (1 << n); ++state){
    for(int cur = state; cur; cur = (cur - 1) & state){
        // do something...
    }
}
```
下面证明这个遍历的时间复杂度是$O(3^n)$。
**证明一**：考虑第 $i$ 位，有三种情况：
- 它在不在状态 $state$ 中（所以它也不在子状态 $substate$ 中）
- 它在状态 $state$ 中，但是它不在子状态 $substate$ 中。
- 它同时在状态 $state$ 和子状态 $substate$ 中。

因为一共有 $n$ 位，所以所有的情况的数目是 $3^n$ 。

**证明二**：如果某个状态 $state$ 有 $k$ 位是 $1$，那么它就会有 $2^k$ 个子状态。同时我们知道拥有 $k$ 位 $1$ 的状态的数目是 ${\binom{n}{k}}$（二项式定理），那么对于所有的状态的组合式的和是：
$$\sum_{k=0}^n {n \choose k} \cdot 2^k$$

可以发现这个式子是 $(1+2)^2$ 的二项展开式，所以结果就是 $3^n$ 。

### 例题

@import "../oj/HDU_3001.md"