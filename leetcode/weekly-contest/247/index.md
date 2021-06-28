---
title: 第247场周赛 - dianhsu.top
---
@import "/mystyle.less"

## 第 247 场周赛 {ignore=True}
> 返回[:house:首页](../../../index.html)，[:rocket:LeetCode目录](../../index.html)

---

[TOC]

### 两个数对之间的最大乘积差

#### 简要思路

排序整个数列之后，用最大两个数之乘积减去最小两个数之乘积。

#### 参考代码

```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];
    }
};
```

### 循环轮转矩阵

#### 简要思路

从外圈往内圈依次考虑每个圈中各个元素最终的位置。

#### 参考代码
```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 0));
        vector<vector<int>> pos(n, vector<int>(m, 0));
        // 圈的数目
        int circle = min(n, m) / 2;

        for(int i = 0; i < circle; ++i){
            // 圈的大小
            int cur = (n - i * 2) * 2 + (m - i * 2) * 2 - 4;
            // 实际上需要循环的次数
            int real = k % cur;
            // 将圈中的数字保存到列表中
            vector<int> tmp;
            int x = 0;
            for(int j = i; j < m - i - 1; ++j){
                pos[i][j] = x++;
                tmp.push_back(grid[i][j]);
            }
            for(int j = i; j < n - i - 1; ++j){
                pos[j][m - 1 - i] = x++;
                tmp.push_back(grid[j][m - 1 - i]);
            }
            for(int j = m - i - 1; j > i; --j){
                pos[n - i - 1][j] = x++;
                tmp.push_back(grid[n - i - 1][j]);
            }
            for(int j = n - i - 1; j > i; --j){
                pos[j][i] = x++;
                tmp.push_back(grid[j][i]);
            }

            // 从列表中获得新的位置
            for(int j = i; j < m - i - 1; ++j){
                ret[i][j] = tmp[(pos[i][j] + real)%x];
                tmp.push_back(grid[i][j]);
            }
            for(int j = i; j < n - i - 1; ++j){
                ret[j][m - 1 - i] = tmp[(pos[j][m - 1 - i] + real)%x];
                tmp.push_back(grid[j][m - 1 - i]);
            }
            for(int j = m - i - 1; j > i; --j){
                ret[n - i - 1][j] = tmp[(pos[n - i - 1][j] + real)%x];
                tmp.push_back(grid[n - i - 1][j]);
            }
            for(int j = n - i - 1; j > i; --j){
                ret[j][i] = tmp[(pos[j][i] + real)% x];
                tmp.push_back(grid[j][i]);
            }
        }
        return ret;
    }
};
```
### 最美子字符串的数目

#### 简要思路

计算前缀异或和出现的次数和前缀异或和相差1bit的次数。

#### 参考代码

```cpp
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> arr(1024, 0);
        arr[0] = 1;
        int mask = 0;
        long long ans = 0;
        for(int i = 0; i < word.length(); ++i){
            int val = 1 << (word[i] - 'a');
            mask ^= val;
            ans += arr[mask];
            for(int j = 0; j < 10; ++j){
                int cur = (1 << j) ^ mask;
                ans += arr[cur];
            }

            arr[mask] ++;
        }
        return ans;
    }
};
```

### 统计为蚁群构筑房间的不同顺序

#### 简要思路

用vector的邻接表法将图保存成一个多叉树，每个点保存它的所有孩子的路径。

使用带回溯的深度优先搜索递归获得子树的排列数和子树的结点个数。

多个子树的合并方法：

假设当前结点拥有的子树的个数是 $n$ ，子树的元素个数分别是 $a_1, a_2, a_3, \cdots, a_n$，子树的排列数分别是 $b_1, b_2, b_3, \cdots, b_n$。

那么可以得到以当前结点为根的子树的元素个数是 $1 + \sum_{i=1}^n a_i$ 。
以当前结点为根的子树的排列，需要保证每个元素在新的序列中，仍要保证原有的顺序。

#### 参考代码

```cpp
const int inf = 1000000007;

template<typename T>
class LinearInverse {
public:
    /*
     * @brief 批量求乘法逆元
     */
    static std::vector<T> build(int n, int p) {
        std::vector<T> inv(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            inv[i] = (long long) (p - p / i) * inv[p % i] % p;
        }
        return inv;
    }
};

class Solution {
private:
    vector<long long> vec;
    
public:
    Solution() : vec(LinearInverse<long long>::build(100100, inf)){
    }
    
    int cal(int x, int y){
        if(x > y){
            swap(x, y);
        }
        long long ret = 1;
        for(int i = 1; i <= x; ++i){
            ret = ret * (x + y + 1 - i) % inf * vec[i] % inf;
        }
        return ret;
    }
    pair<long long, int> dfs(int pos, vector<vector<int>>& path){
        // 保存的是当前子树的排列数和当前子树的元素总数。
        pair<long long, int> ret = {1, 0};
        // 合并所有子树的情况
        for(auto it: path[pos]){
            auto x = dfs(it, path);
            long long nex = ret.first * x.first % inf * cal(ret.second, x.second) % inf;
            ret = {nex, ret.second + x.second};
        }
        ret.second += 1;
        return ret;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        
        vector<vector<int>> vec(100100);
        for(int i = 1; i < prevRoom.size(); ++i){
            vec[prevRoom[i]].push_back(i);
        }
        return dfs(0, vec).first % inf;
    }
};
```