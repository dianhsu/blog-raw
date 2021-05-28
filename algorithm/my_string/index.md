---
title: 字符串 - 算法 - dianhsu.top
---
@import "/mystyle.less"
## 字符串 {ignore=True}
> 返回:house:[首页](../../index.html)
> 返回:rocket:[算法](../index.html)


-----------------------------------


[TOC]

### KMP字符串匹配

@import "./KMP.cpp" {code_block=true class="line-numbers"}

### Manacher

@import "./manacher.cpp" {code_block=true class="line-numbers"}

### AC自动机(AC Automaton)

```mermaid
graph TD
  0 -- h --> 2
  0 -- i --> 1
  0 -- s --> 4
  1 -- h --> 2
  1 -- i --> 1
  1 -- s --> 4
  2 -- e --> 3
  2 -- h --> 2
  2 -- i --> 9
  2 -- s --> 4
  3 -- h --> 2
  3 -- i --> 1
  3 -- r --> 7
  3 -- s --> 4
  4 -- h --> 5
  4 -- i --> 1
  4 -- s --> 4
  5 -- e --> 6
  5 -- h --> 2
  5 -- i --> 9
  5 -- s --> 4
  6 -- h --> 2
  6 -- i --> 1
  6 -- r --> 7
  6 -- s --> 4
  7 -- h --> 2
  7 -- i --> 1
  7 -- s --> 8
  8 -- h --> 5
  8 -- i --> 1
  8 -- s --> 4
  9 -- h --> 2
  9 -- i --> 1
  9 -- s --> 10
  10 -- h --> 5
  10 -- i --> 1
  10 -- s --> 4
  0 == fail ==> 0
  1 == fail ==> 0
  2 == fail ==> 0
  3 == fail ==> 0
  4 == fail ==> 0
  5 == fail ==> 2
  6 == fail ==> 3
  7 == fail ==> 0
  8 == fail ==> 4
  9 == fail ==> 1
  10 == fail ==> 4
```
@import "./ac_automaton.cpp" {code_block=true class="line-numbers"}
