@import "/mystyle.less"

## Manacher
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---


```cpp
/*
 * @brief Manacher算法，求最长回文字串
 */
#include <bits/stdc++.h>

class Manacher {
public:
    static std::string forward(const std::string& s) {
        std::string Ma = "^#";
        for (auto it: s) {
            Ma += it;
            Ma += '#';
        }
        Ma += '$';
        int len = Ma.length();
        std::vector<int> Mp(len, 0);
        int mx = 0, id = 0;
        int maxPos = 0;
        for (int i = 0; i < len - 1; ++i) {
            Mp[i] = mx > i ? std::min(Mp[(id << 1) - i], mx - i) : 1;
            while (i - Mp[i] >= 0 and i + Mp[i] < (int)Ma.size() and Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
            if (Mp[i] > Mp[maxPos]) {
                maxPos = i;
            }
            if (i + Mp[i] > mx) {
                mx = i + Mp[i];
                id = i;
            }
        }
        std::string ret;
        for (int i = maxPos - Mp[maxPos] + 1; i < maxPos + Mp[maxPos]; ++i) {
            if (isalnum(Ma[i])) {
                ret += Ma[i];
            }
        }
        return ret;
    }
};

int main(){
    std::string str("abababc");
    std::cout << Manacher::forward(str) << std::endl;
    return 0;
}
```