---
title: 杂项 - dianhsu.top
toc:
  depth_from: 1
  depth_to: 4
  ordered: false
---
@import "/mystyle.less"

# 杂项 {ignore=True}
> 返回[首页](../index.html)

---------------------------

[TOC]

## 需要学习的基本技能
- Markdown
- $\LaTeX$（只需要会数学公式即可，要求不高）
- 对文本格式的严格要求

### 文本基础
Markdown是一种非常流行的是一种轻量级标记语言。

等宽内容用反引号（\`）框起来，比如： `Hello World!`。

数学公式变量都需要用$\LaTeX$，比如：$A$，$B$，$f(n) = f(n-1)+f(n-2)$，源码：`$A$，$B$，$f(n) = f(n-1)+f(n-2)$`。

并列关系的介绍用列表：

**有序列表**
1. a
2. b
3. c
```
1. a
2. b
3. c
```
**无序列表**
- a
- b
- c
```
- a
- b
- c
```
### 原则要求

1. 中文题面中，除了公式需要以外不得出现半角符号。英文题面不得出现全角符号。
2. 英文名词的使用，原则上相同意义的名词的使用必须一致；专用名词使用约定俗称的写法。
   - 比如`ZJGG`已经在上文出现的情况下，`Zjgg`和`zjgg`都不允许使用，除非指代其他意义。
   - 比如`MySQL`、`C++`、`C`、`Java`，这些按照通常的写法，并且需要全文保持一致。`mysql`、`c++`、`c`、`java`尽量不要使用。
3. 在写题面的数据范围的时候，写清楚**数据范围**和**数据类型**。
   - 比如：第$n$行包含一个**字符串**$s$，$s$的**长度**在$[0,n)$内。
   - 比如：第一行包含一个**浮点数**$d_{AB}(0 < d_{AB} < 100)$，代表$A$点到$B$点的距离。
4. 题目中的图片，可以使用在线图片。例如：
   `![img](http://acm.hdu.edu.cn/data/images/1056-1.gif)`
   ![img](http://acm.hdu.edu.cn/data/images/1056-1.gif)
5. 需要打印的文本，用等宽字符表示。
## 题面的撰写

### 题目描述
通常来讲，题目的描述由以下部分构成：
- 背景介绍（讲故事）
- 问题介绍（这个题需要解决什么问题）
- 符号介绍（介绍输入中出现的各种符号的意义）
### 输入描述

#### 单组的输入描述
**Markdown内容**：
```text
每个测试输入包含xxx行。

- 第$1$行包含两个整数$n$、$m$，$n$代表了xxxxx，$m$代表了xxxx。
- 第$2$行包括$n$个整数，用空格隔开，分别是$a_1, a_2, \cdots, a_i, \cdots, a_n$，代表xxxxx。
- 第$n+1$行到第$n + m$行，每行一个整数$q$，代表了每次询问的xxxx。

数据范围：
 - $1 < n \leq 2 \cdot 10^5$
 - $1 \leq m \leq 1000$
 - $-10^9 \leq a_i \leq 10^9$
 - $1 \leq q \leq n$
```
**显示效果**：

每个测试输入包含xxx行。

- 第$1$行包含两个整数$n$、$m$，$n$代表了xxxxx，$m$代表了询问的次数。
- 第$2$行包括$n$个整数，用空格隔开，分别是$a_1, a_2, \cdots, a_i, \cdots, a_n$，代表xxxxx。
- 第$n+1$行到第$n + m$行，每行一个整数$q$，代表了每次询问的xxxx。

数据范围：
 - $1 < n \leq 2 \cdot 10^5$
 - $1 \leq m \leq 1000$
 - $-10^9 \leq a_i \leq 10^9$
 - $1 \leq q \leq n$

#### 多组的描述
**Markdown内容**：
```text
每个测试的第一行包含一个整数$T$，代表测试的组数。

每组包含$1$行。
- 第一行包含两个实数$p$和$q$，用空格隔开，分别代表了$A$和$B$的值。

数据范围：
- $1 \leq T \leq 100$
- $-10^{-2} \leq p,q \leq 10^{10}$
```
**显示效果**：

每个测试的第一行包含一个整数$T$，代表测试的组数。

每组包含$1$行。
- 第一行包含两个实数$p$和$q$，用空格隔开，分别代表了$A$和$B$的值。

数据范围：
- $1 \leq T \leq 100$
- $-10^{-2} \leq p,q \leq 10^{10}$


### 输出描述
#### 单组的输出描述
**Markdown内容**：
```
输出包括两行。
- 第一行一个整数，代表xxxx。
- 第二行$n$个整数，代表xxxx，每两个相邻的数据之间用一个空格隔开。
```
**显示效果**：
输出包括两行。
- 第一行一个整数，代表xxxx。
- 第二行$n$个整数，代表xxxx，每两个相邻的数据之间用一个空格隔开。
#### 多组的输出描述
**Markdown内容**：
```
对于输入中的每组数据，输出包括两行。
- 第一行一个整数，代表xxxx。
- 第二行$n$个整数，代表xxxx，每两个相邻的数据之间用一个空格隔开。
```
**显示效果**：
对于输入中的每组数据，输出包括两行。
- 第一行一个整数，代表xxxx。
- 第二行$n$个整数，代表xxxx，每两个相邻的数据之间用一个空格隔开。
## 样例数据相关
- 强烈不建议用**不告知输入组数**的多组数据。
- 输出浮点数，非文本的情况下必须使用`SPJ`。
- 每个题目的所有样例打包之后的大小不超过$100MB$。
## Special Judge

### dianhsu提供的版本

```cpp
#include <bits/stdc++.h>

using namespace std;

#define AC 0
#define WA 1
#define ERROR -1

/****************************************/
double solve(double a, double b){
    return a + b;
}

int spj(ifstream& ifs, ifstream& ufs) {
    int T;
    // 判断是否能读取到输入的文件
    if (!(ifs >> T)) {
        return ERROR;
    }
    while (T--) {
        double a, b;
        // 判断是否能读取到输入的文件
        if (!(ifs >> a >> b)) {
            return ERROR;
        }
        double std_ans = solve(a, b);
        double user_ans;
        // 判断用户的输出中是否能够读取到一个浮点数
        if (!(ufs >> user_ans)) {
            return WA;
        }
        // 判断用户的输出和标准的输出的差是否在eps之间
        if (fabs(user_ans - std_ans) > 1e-6) {
            return WA;
        }
    }
    return AC;
}


int main(int argc, char* argv[]) {
    FILE* input = NULL, * user_output = NULL;
    int result;
    if (argc != 3) {
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    ifstream ifs(argv[1]);
    ifstream ofs(argv[2]);
    result = spj(ifs, ofs);
    ifs.close();
    ofs.close();
    return result;
}
```

### QDUOJ提供的版本
```c
// 这个是官方的SPJ样例
#include <stdio.h>

#define AC 0
#define WA 1
#define ERROR -1

int spj(FILE *input, FILE *user_output);

void close_file(FILE *f){
    if(f != NULL){
        fclose(f);
    }
}

int main(int argc, char *args[]){
    FILE *input = NULL, *user_output = NULL;
    int result;
    if(argc != 3){
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if(input == NULL || user_output == NULL){
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);
    printf("result: %d\n", result);
    
    close_file(input);
    close_file(user_output);
    return result;
}

int spj(FILE *input, FILE *user_output){
    /*
      parameter: 
        - input，标程输入的文件指针
        - user_output，用户输出文件的指针
      return: 
        - 如果用户答案正确，返回AC
        - 如果用户答案错误返回WA
        - 如果主动捕获到自己的错误，如内存分配失败，返回ERROR
      请用户完成此函数.
      demo:
      int a, b;
      while(fscanf(f, "%d %d", &a, &b) != EOF){
          if(a -b != 3){
              return WA;
          }
      }
      return AC;
     */
}
```