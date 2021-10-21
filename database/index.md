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
- 原子性（Atomicity）：事务必须以一个整体单元的形式进行工作，对于其数据的修改，要么全都执行，要么全都不知执行。如果只执行事务中多个操作的前半部分就出现错误，那么必须回滚所有的操作，让数据在逻辑上回滚到原先的状态。
- 一致性（Consistency）：在事务完成时，比如是所有的数据都保持在一致状态。
- 隔离性（Isolation）：事务查看数据时数据所处的状态，要么是另一并发事务修改它之前的状态，要么是另一事务修改它之后的状态，事务是不会查看中间状态的数据的。
- 持久性（Durability）：事务完成之后，它对于系统的影响是永久性的。即使今后出现致命的系统故障（如机器重启，断电），数据也将一直保持。

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

| 锁模式                 | 解释                                                                                                                                                                                               |
| :--------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ACCESS SHARE           | 只与 ACCESS ELUSIVE 模式冲突。<br/> SELECT 命令将在所引用的表上加此类型的锁。通常情况下，任何只读取表而不修改表的查询都会请求这种锁模式。                                                          |
| ROW SHARE              | 与 EXCLUSIVE 和 ACCESS EXCLUSIVE 锁模式冲突。<br/> SELECT FOR UPDATE 和 SELECT FOR SHARE命令会在目标表上加此类型的锁。                                                                             |
| ROW EXCLUSIVE          | 与 SHARE、SHARE ROW EXCLUSIVE、EXCLUSIVE、ACCESS EXCLUSIVE 锁模式冲突。<br/>UPDATE、DELETE、INSERT命令会自动在锁修改的表上请求此类型的锁。通常情况下，修改表中数据的命令都是在在表上加此类型的锁。 |
| SHARE UPDATE EXCLUSIVE | 与 SHARE UPDATE EXCLUSIVE                                                                                                                                                                          |
| SHARE                  |                                                                                                                                                                                                    |
| SHARE ROW EXCLUSIVE    |                                                                                                                                                                                                    |
| EXCLUSIVE              |                                                                                                                                                                                                    |
| ACCESS EXCLUSIVE       |                                                                                                                                                                                                    |

#### 行级锁


## 问题