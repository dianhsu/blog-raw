---
title: 第55场双周赛 - dianhsu.top
---
@import "/mystyle.less"

## 第55场双周赛 {ignore=True}
> 返回[:house:首页](../../../index.html)，[:rocket:LeetCode目录](../../index.html)

---

[TOC]

### 删除一个元素使数组严格递增

#### 简要思路

题目数据较小，依次检查删除某个元素之后，数组中数据是不是有序就可以了。

#### 参考代码

```cpp
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            bool ok = true;
            for(int j = 1; j < nums.size(); ++j){
                if(j == i){
                    continue;
                }else if(j - 1 == i){
                    if(j >= 2){
                        if(nums[j] <= nums[j-2]){
                                ok = false;
                            break;
                            }
                    }
                }else if(nums[j] <= nums[j-1]){
                        ok = false;
                        break;
                    }
            }
            if(ok) return true;
        }
        return false;
    }
};
```


### 删除一个字符串中所有出现的给定子字符串

#### 简要思路

递归删除所有满足条件的子字符串，直到无法删除为止。

#### 参考代码

```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(s.length() < part.length()) return s;
        for(int i = 0; i <= s.length() - part.length(); ++i){
            if(s.substr(i, part.length()) == part){
                return removeOccurrences(s.substr(0, i) + s.substr(i + part.length()), part);
            }
        }
        return s;
    }
};
```


### 最大子序列交替和

#### 简要思路

从峰顶开始，每次找到一个峰谷，然后一个峰顶。依次进行下去。

#### 参考代码

```cpp

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int cur = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] >= nums[cur]){
                cur = i;
            }else{
                break;
            }
        }
        long long ret = nums[cur];
        long long tmp1 = 0, tmp2 = 0;
        long long pre = nums[cur];
        for(int i = cur + 1; i < nums.size(); ++i){
            if(nums[i] == pre) continue;
            if((nums[i] > pre) and (i == nums.size() - 1 or nums[i] > nums[i + 1])){
                ret += nums[i] - tmp1;
                tmp1 = 0;
            }
            if((nums[i] < pre) and (i == nums.size() - 1 or nums[i] < nums[i + 1])){
                tmp1 = nums[i];
            }
            if(i != nums.size() -1 and nums[i] != nums[i + 1])
                pre = nums[i];
        }
        return ret;
    }
};
```

### 设计电影租借系统

#### 简要思路

#### 参考代码