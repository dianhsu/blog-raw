---
title: VirtualJudge - dianhsu.top
---
@import "/mystyle.less"
# VirtualJudge
> reference: [https://github.com/VirtualJudge](https://github.com/VirtualJudge)

[TOC]
---

## Abstract

VirtualJudge是一个虚拟评测平台，它的主要功能是从其他多个平台上面爬取题面，进行一系列格式化之后，返回给用户。

## 总体结构

![structure](https://cdn.dianhsu.top/img/20210609162734.svg)

- 交互层：是用户直接看到的对象，主要是显示网页和未决定要开发的Android端。
- 接口层：操作API，是用户直接操作的对象，主要是后台提供的API接口。另外任务返回和消息处理主要是获取到爬虫爬取到的数据之后，进行数据库的更新。更进一步，后期可以考虑这里使用Websocket通知用户。
- 存储层：包括缓存非关系型数据库（Redis）、持久化关系型数据库（PostgreSQL）和任务队列（RabbitMQ）。
- 处理层：使用爬虫访问外部OnlineJudge平台。

## 处理层

处理层主要有两项任务
- 爬取并处理题面
- 提交代码并爬取执行结果

### 爬取并处理题面（以HDU为例）

#### 爬取题面
原则上，标题、时间限制和空间限制需要完全匹配出来。

题目内容尽量匹配对应的内容：
- 介绍
- 输入介绍
- 输出介绍
- 样例输入
- 样例输出
- 提示
- 作者
- 来源

以上方式称为Markdown获取方式。

如果实在是匹配不到或者是效果有限，可以用提取整块HTML的方式来显示出来。这样方式称为HTML获取方式。

#### 题面的处理方式

##### 链接和文件的处理

有些题面上会提供一些链接。如果是绝对链接，那么就保持原样。如果是相对链接，就需要补充访问域名或者是访问URL。
例如：当前访问的链接是`http://www.aabbcc.com/path/abc.html`。这个网页有个超链接是`http://www.baidu.com/img/xxx.jpg`，这种链接保持原状；另外有个链接是`/index/xxx.jpg`，那么它应该修改为`http://www.aabbcc.com/index/xxx.jpg`；第三个链接是`asd/xxx.jpg`，那么它修改之后的链接应该是`http://www.aabbcc.com/path/asd/xxx.jpg`。

对于文件的处理方式，如果该链接是相对链接，就按照上面方式补充成绝对链接。后面根据需求，判断是否需要将文件缓存到本地。

##### Markdown题面处理
Markdown题目的渲染，这个暂时还没确定。

##### HTML题面的处理

按照网页节点的类型，分别插入class，命名为`vj-text`, `vj-head1`, `vj-head2`, `vj-img`等。用来区分不同的节点类型，方便调用相同的样式文件。



## Redis 中爬虫帐号

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

## RabbitMQ 中的任务，爬虫API接口
### 数据库中没有的题目的请求过程

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

### 获取题目

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
{
    "type": "problem",
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

### 提交代码

> 后台向爬虫发送的任务

```json
{
    "type": "submission",
    "request": {
        "platform": "POJ",
        "key": "1234",
        "submission": "",
        "language": "",
        "code": ""
    }
}
```

> 爬虫向后台发送的任务

```json
{
    "type": "submission",
    "error": false,
    "error_message": "Network Error.",
    "result": {
        "run_id": "",
        "verdict": "",
        "verdict_info": "",
        "memory": "",
        "time": ""
    }
}
```


## 后台API接口

### 用户帐号类

### 题目类

### 提交类
