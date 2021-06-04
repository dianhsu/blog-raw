---

title: KMP - 算法 - dianhsu.top
---
@import "/mystyle.less"

## KMP
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---


```cpp
/**
 * @brief KMP字符串匹配
 * @author dianhsu
 * @date 2021/05/25
 * */
#include <bits/stdc++.h>

using namespace std;

class KMP {
public:
    /**
     * @brief 统计目标串中有多少个模式串
     * @param target 目标字符串
     * @param pattern 模式字符串
     * */
    static int solve(string& target, string& pattern) {
        int ans = 0;
        int idxTarget = 0, idxPattern = 0;
        vector<int> next(std::move(_prefix(pattern)));
        while (idxTarget < target.length()) {
            while (idxPattern != -1 and pattern[idxPattern] != target[idxTarget]) {
                idxPattern = next[idxPattern];
            }
            ++idxTarget; ++idxPattern;
            if (idxPattern >= pattern.length()) {
                ++ans;
                idxPattern = next[idxPattern];
            }
        }
        return ans;
    }
private:
    static vector<int> _prefix(const string& pattern) {
        int i = 0, j = -1;
        vector<int> ret(pattern.length() + 1, -1);
        while (i < pattern.length()) {
            while (j != -1 and pattern[i] != pattern[j]) j = ret[j];
            if (pattern[++i] == pattern[++j]) {
                ret[i] = ret[j];
            } else {
                ret[i] = j;
            }
        }
        return ret;
    }
};

int main() {
    string target = "aaaaaa";
    string pattern = "aa";
    std::cout << KMP::solve(target, pattern) << std::endl;
    return 0;
}
```