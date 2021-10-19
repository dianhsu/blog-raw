---
title: 数据库 - dianhsu.top
toc:
  depth_from: 1
  depth_to: 4
  ordered: false
---
@import "/mystyle.less"

# 数据库 {ignore=True}
> 返回:house:[首页](../index.html)

---------------------------
> 参考资料：
> 《PostgreSQL修炼之道（从小工到专家）》 第2版；唐成 著；
> 《数据库系统概论》第5版；王珊 萨师煊 著；
## 数据库基础

### 关系数据理论

### 数据库完整性

### ACID
- 原子性（Atomicity）
- 一致性（Consistency）
- 隔离性（Isolation）
- 持久性（Durability）


### E-R模型

### 并发控制

## PostgreSQL 特点

### 表继承


### PG支持的索引

#### BTree索引
最常用的索引，BTree索引适合用于处理等值查询和范围查询。

#### Hash索引
只能处理简单的等值查询。

#### GiST索引
不是一种单独的索引类型，而是一种架构，可以在这种架构上面实现很多不同的索引策略。

#### SP-GiST索引
`SP-GiST`是`Space-Partitioned GiST`的缩写，即空间分区GiST索引。它是从PostgreSQL9.2版本开始提供的一种新索引类型，主要是通过一些新的索引算法来提高GiST索引在某种情况下的性能。

#### GIN索引
反转索引，可以处理包含多个键的值，如数组等。

### 表级锁和行级锁

#### 表级锁

## 问题