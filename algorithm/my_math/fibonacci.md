---
toc:
    depth_from: 1
    depth_to: 4
title: Fibonacci数列 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## Fibonacci数列
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

[TOC]
---

### 定义
斐波那契数列的公式如下所示：
$$
F_0=0 \\ 
F_1=1 \\
F_n=F_{n-1}+F_{n-2}  (n > 1)
$$

### 性质

设定 $ S_n = F_1^2 + F_2^2 + \cdots + F_n^2$
则 $S_n = F_n \cdot F_{n + 1} -1$。

图形证明如下图：
方块中的数字是代表方块的边长。
![pic1](https://cdn.dianhsu.top/img/20210611194644.png)