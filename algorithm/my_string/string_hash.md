---
toc:
    depth_from: 1
    depth_to: 4
title: 字符串哈希 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## 字符串哈希
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---

[TOC]
### Hash 的思想
Hash 的核心思想在于，将输入映射到一个值域较小、可以方便比较的范围。

### 哈希函数

> 参考：[https://blog.csdn.net/MyLinChi/article/details/79508112](https://blog.csdn.net/MyLinChi/article/details/79508112)

| Hash函数 | 数据1 | 数据2 | 数据3 | 数据4 | 数据1得分 | 数据2得分 | 数据3得分 | 数据4得分 | 平均分 |
| -------- | ----- | ----- | ----- | ----- | --------- | --------- | --------- | --------- | ------ |
| BKDRHash | 2     | 0     | 4774  | 481   | 96.55     | 100       | 90.95     | 82.05     | 92.64  |
| APHash   | 2     | 3     | 4754  | 493   | 96.55     | 88.46     | 100       | 51.28     | 86.28  |
| DJBHash  | 2     | 2     | 4975  | 474   | 96.55     | 92.31     | 0         | 100       | 83.43  |
| JSHash   | 1     | 4     | 4761  | 506   | 100       | 84.62     | 96.83     | 17.95     | 81.94  |
| RSHash   | 1     | 0     | 4861  | 505   | 100       | 100       | 51.58     | 20.51     | 75.96  |
| SDBMHash | 3     | 2     | 4849  | 504   | 93.1      | 92.31     | 57.01     | 23.08     | 72.41  |
| PJWHash  | 30    | 26    | 4878  | 513   | 0         | 0         | 43.89     | 0         | 21.95  |
| ELFHash  | 30    | 26    | 4878  | 513   | 0         | 0         | 43.89     | 0         | 21.95  |

> 数据1为100000个字母和数字组成的随机串哈希冲突个数。
> 数据2为100000个有意义的英文句子哈希冲突个数。
> 数据3为数据1的哈希值与 1000003(大素数)求模后存储到线性表中冲突的个数。
> 数据4为数据1的哈希值与10000019(更大素数)求模后存储到线性表中冲突的个数。

经过比较，得出以上平均得分。平均数为平方平均数。可以发现，BKDRHash无论是在实际效果还是编码实现中，效果都是最突出的。APHash也是较为优秀的算法。DJBHash，JSHash，RSHash与SDBMHash各有千秋。PJWHash与ELFHash效果最差，但得分相似，其算法本质是相似的。

### 实现原理和常用算法
所有的字符串哈希算法都是基于对字符编码的迭代运算，只是运算规则不同而已。

#### BKDRHash算法
```cpp
// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### APHash算法

```cpp
// AP Hash Function
unsigned int APHash(char *str)
{
    unsigned int hash = 0;
    int i;
 
    for (i=0; *str; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### DJBHash算法
```cpp
// DJB Hash Function
unsigned int DJBHash(char *str)
{
    unsigned int hash = 5381;
 
    while (*str)
    {
        hash += (hash << 5) + (*str++);
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### JSHash算法

```cpp
// JS Hash Function
unsigned int JSHash(char *str)
{
    unsigned int hash = 1315423911;
 
    while (*str)
    {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### RSHash算法

```cpp
// RS Hash Function
unsigned int RSHash(char *str)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### SDBMHash算法

```cpp
unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0;
 
    while (*str)
    {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### PJWHash算法

```cpp
// P. J. Weinberger Hash Function
unsigned int PJWHash(char *str)
{
    unsigned int BitsInUnignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    unsigned int ThreeQuarters    = (unsigned int)((BitsInUnignedInt  * 3) / 4);
    unsigned int OneEighth        = (unsigned int)(BitsInUnignedInt / 8);
    unsigned int HighBits         = (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);
    unsigned int hash             = 0;
    unsigned int test             = 0;
 
    while (*str)
    {
        hash = (hash << OneEighth) + (*str++);
        if ((test = hash & HighBits) != 0)
        {
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### ELFHash算法

```cpp
// ELF Hash Function
unsigned int ELFHash(char *str)
{
    unsigned int hash = 0;
    unsigned int x    = 0;
 
    while (*str)
    {
        hash = (hash << 4) + (*str++);
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
 
    return (hash & 0x7FFFFFFF);
}
```

### 例题

@import "../oj/HDU_1067.md"