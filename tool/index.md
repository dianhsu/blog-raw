---
title: 工具 - dianhsu.top
toc:
  depth_from: 1
  depth_to: 4
  ordered: false
---
@import "/mystyle.less"

# 工具 {ignore=True}
> 返回[首页](../index.html)

---------------------------

[TOC]
## 拒绝QQ拦截外部链接

```javascript
// ==UserScript==
// @name        拒绝拦截外部链接 - qq.com
// @namespace   Violentmonkey Scripts
// @match       https://c.pc.qq.com/middlem.html
// @grant       none
// @version     1.0
// @author      dianhsu
// @description 2021/8/29 下午6:46:14
// ==/UserScript==

(function(){
  'use strict';
  
  //console.log(window.location.href)
  let searchParams = new URLSearchParams(window.location.search);
  let reqUrl = searchParams.get("pfurl");
  if(!!reqUrl){
      window.location.href = reqUrl;
  }
})();
```

## Linux

### HP Printer
配置打印机的时候，出现这个错误

```bash
CUPS server error

client-error-not-possible
```

安装`smbclient`即可解决。

## CUPS 打印机双页打印
首先安装需要的Python包
```bash
pip3 install pycups
pip3 install PyPDF2
```
执行下面的代码
```python
# !/usr/bin/env python3
import os
import tempfile
import uuid

import PyPDF2
import cups
from PyPDF2 import PdfFileReader

# 连接打印机
conn = cups.Connection()
printers = conn.getPrinters()
printer = None
for key in printers:
    printer = key
if printer is None:
    print('亲，你的打印机呢')
    exit(-1)
# 上传文件
tmp_dir = tempfile.TemporaryDirectory().name
os.makedirs(tmp_dir, exist_ok=True)
tmp_path = os.path.join(tmp_dir, f'{uuid.uuid4()}.pdf')
pdf_path = input("请输入PDF路径: ")

# 如果是奇数页文件情况，需要补充一个空白页到末尾
fin = open(pdf_path, 'rb')
pdf = PdfFileReader(fin)
page_num = pdf.getNumPages()
outputPdf = PyPDF2.PdfFileWriter()
outputPdf.appendPagesFromReader(pdf)
if page_num % 2 != 0:
    outputPdf.addBlankPage()
with open(tmp_path, 'wb') as fout:
    outputPdf.write(fout)
fin.close()
tmp_pdf = PdfFileReader(tmp_path)
page_num = tmp_pdf.getNumPages()

double_page = True
if double_page:
    # 获取奇数页码和偶数页码
    all_pages = [str(it + 1) for it in range(page_num)]
    odd_str = ','.join(all_pages[0::2])
    even_str = ','.join(all_pages[1::2])
    # 打印奇数页
    conn.printFile(printer, tmp_path, pdf_path, {'page-ranges': odd_str})
    # 去打印机把纸拿下来换一下
    test = input("请输入\"next\"打印背面: ")
    while test != "next":
        test = input("请输入\"next\"打印背面: ")
    # 从后往前打印偶数页
    conn.printFile(printer, tmp_path, pdf_path, {'outputorder': 'reverse', 'page-ranges': even_str})
else:
    # 按顺序打印全部的页码
    conn.printFile(printer, tmp_path, pdf_path, {})

```

