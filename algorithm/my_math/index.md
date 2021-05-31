---
title: 数学 - 算法 - dianhsu.top
---
@import "/mystyle.less"
## 数学 {ignore=True}
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)


-----------------------------------


[TOC]

### 乘法逆元
@import "./modular_multiplicative_inverse.cpp" {code_block=true class="line-numbers"}

### 二项式系数
> reference: [https://cp-algorithms.com/combinatorics/binomial-coefficients.html](https://cp-algorithms.com/combinatorics/binomial-coefficients.html)

二项式系数$C_n^k$是在不考虑顺序的情况下，在n个不同的物品中选择k个。

二项式系数是二项式$(a+b)^2$中的系数，又称为二项式定理
$$(a+b)^n=C_n^0a^n + C_n^1a^{n-1}b + C_n^2a^{n-2}b^2 + \dots + C_n^ka^{n-k}b^k + \dots + C_n^n b^n$$

#### 计算

计算公式如下：
$$C_n^k=\frac{n!}{k!(n-k)!}$$

递推公式（杨辉三角）：
$$C_n^k=C_{n-1}^{k-1} + C_{n-1}^{k}$$

若 $n < k$，$C_n^k$ 的值被设定为 $0$ 。

#### 属性

Symmetry rule: 
$$C_n^k = C_n^{n-k}$$

Factoring in:
$$C_n^k = \frac{n}{k} C_{n-1}^{k-1}$$

Sum over $k$:
$$\sum_{k=0}^n C_n^k = 2^n$$

Sum over $n$:
$$\sum_{m=0}^n C_m^k = C_{n+1}^{k+1}$$

Sum over $n$ and $k$:
$$\sum_{k=0}^mC_{n+k}^k=C_{n+m+1}^m$$

Sum of the squares:
$$C_n^0 + C_n^1 + \dots + C_n^n = C_{2n}^n$$

Weighted sum:
$$1C_n^1 + 2C_n^2 + \dots + nC_n^n = n2^{n-1}$$

Connection with the Fibonacci numbers:
$$C_n^0 + C_{n-1}^1+ \dots + C_{n-k}^k + \dots + C_0^n = F_{n+1}$$