---
title: VirtualJudge - dianhsu.top
---
@import "/mystyle.less"
# VirtualJudge
> reference: [https://github.com/VirtualJudge](https://github.com/VirtualJudge)

## Abstract

VirtualJudge是一个虚拟评测平台，它的主要功能是从其他多个平台上面爬取题面，进行一系列格式化之后，返回给用户。

## 总体结构

![structure](https://cdn.dianhsu.top/img/20210609162734.svg)

- 交互层：是用户直接看到的对象，主要是显示网页和未决定要开发的Android端。
- 接口层：操作API，是用户直接操作的对象，主要是后台提供的API接口。另外任务返回和消息处理主要是获取到爬虫爬取到的数据之后，进行数据库的更新。更进一步，后期可以考虑这里使用Websocket通知用户。
- 存储层：包括缓存非关系型数据库（Redis）、持久化关系型数据库（PostgreSQL）和任务队列（RabbitMQ）。
- 处理层：使用爬虫访问外部OnlineJudge平台。


## 数据库相关

### Redis 中爬虫帐号


```json
{
    "POJ": {
        "running":[0, 1, 5],
        "idle": [2, 3],
        "disabled": [4],
        "accounts":[
            {
                "username": "dianhsu00",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu01",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu02",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu03",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu04",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu05",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            }
        ],
       
    },
    "HDU": {
        "running":[0, 5],
        "idle": [2, 3],
        "disabled": [1, 4],
        "accounts":[
            {
                "username": "dianhsu00",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu01",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu02",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu03",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu04",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            },{
                "username": "dianhsu05",
                "password": "????????",
                "cookies": "SESSIONID=\"AHJKDHAJKDHAJKHKDJSHKDJS\";SADJH=\"ahdkjahkdjhajd\""
            }
        ],
    }
}
```

### RabbitMQ 中的任务
#### 数据库中没有的题目的请求过程

```sequence {title="数据库中没有的题目的请求过程"}
participant Frontend 
Frontend -> Backend: ""这个题有没有""
Backend -> RabbitMQ: ""有没有这个题""
RabbitMQ -> Spider: ""去吧，皮卡丘""
Spider -> RabbitMQ: ""这个题目找到了""
RabbitMQ -> Handler: ""请保存一下，顺便喊下用户""
Handler -> PostgreSQL: ""腾块地儿，谢谢""
Handler -> Frontend: ""亲，你要的题目已经到货了，请注意查收""
```

#### 获取题目

> 后台向爬虫发送的任务

```json
{
    "type": "problem",
    "user": 123,
    "local_id": 1239,
    "remote": {
        "platform": "POJ",
        "key": "1234",
        "login_required": false
    },
    "redirect_files": false
}
```

> 爬虫向后台发送的任务

```json

```

#### 提交代码

> 后台向爬虫发送的任务

```json
{
    "type": "submission"
}
```

> 爬虫向后台发送的任务

```json
{
    "type": "result"
}
```

## 后台API接口

### 用户帐号类

### 题目类

### 提交类

## 爬虫API接口

### 题目类

#### 获取题目

##### 请求格式说明

| 键           |                | 值类型  | 是否可为空 | 描述                                                             |
| ------------ | -------------- | ------- | ---------- | ---------------------------------------------------------------- |
| local_id     |                | int     | 是         | 本地数据库中的题目编号，为空的话代表当前题目还没有加入到题库当中 |
| remote       | platform       | string  | 否         | 平台名称                                                         |
| ^            | key            | string  | 否         | 平台题目标志符                                                   |
| ^            | login_required | boolean | 否         | 是否需要登录                                                     |
| redirect_files |                | boolean | 否         | 是否需要缓存文件                                                 |
##### 请求参考格式
```json
{
    "local_id": 1239,
    "remote": {
        "platform": "POJ",
        "key": "1234",
        "login_required": false
    },
    "redirect_files": false
}
```
##### 返回格式说明

##### 返回参考格式
```json
{
    "error": false,
    "error_message": "Network Error.",
    "result": {
        "platform": "POJ",
        "key": "1234",
        "time_limit": 1000,
        "memory_limit": 65535,
        "content": "<div><p>HelloWorld.</p></div>",
        "title": "A+B"
    }
}
```
### 提交类

### 结果类