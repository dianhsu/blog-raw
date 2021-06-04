---

title: AC自动机 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## AC 自动机
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---

### 示意图

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
### 参考模板
```cpp
/**
 * @brief AC自动机
 * @author dianhsu
 * @date 2021/05/26
 * @ref http://oi-wiki.com/string/ac-automaton/
 * */

#include <bits/stdc++.h>

template<int N = 1000010>
class ACAutomaton {
public:
    ACAutomaton() : tot(0) {

    }

    void insert(const std::string &str) {
        int u = 0;
        for (auto it: str) {
            if (!nex[u][it - 'a']) {
                nex[u][it - 'a'] = ++tot;
            }
            u = nex[u][it - 'a'];
        }
        e[u]++;
    }

    void build() {
        std::queue<int> Q;
        for (int i = 0; i < 26; i++)
            if (nex[0][i]) Q.push(nex[0][i]);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++) {
                if (nex[u][i]) {
                    fail[nex[u][i]] = nex[fail[u]][i];
                    Q.push(nex[u][i]);
                } else {
                    nex[u][i] = nex[fail[u]][i];
                }
            }
        }
    }

    int query(const std::string &str) {
        int u = 0, res = 0;
        for (auto it: str) {
            u = nex[u][it - 'a'];
            for (int j = u; j and e[j] != -1; j = fail[j]) {
                res += e[j];
                e[j] = -1;
            }
        }
        return res;
    }

    friend std::ostream &operator<<(std::ostream &out, ACAutomaton<N>& ac) {
        out << "graph LR" << std::endl;
        for (int i = 0; i <= ac.tot; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (ac.nex[i][j] != 0) {
                    out << "  " << i << " -- " << (char) (j + 'a') << " --> " << ac.nex[i][j] << std::endl;
                }
            }
        }
        for(int i = 0; i <= ac.tot; ++i){
            out << "  " << i << " == fail ==> " << ac.fail[i] << std::endl;
        }
        return out;
    }

private:


    int nex[N][26]{}, tot;
    int e[N]{}, fail[N]{};
};

int main() {
    auto ac = new ACAutomaton();
    ac->insert("i");
    ac->insert("he");
    ac->insert("she");
    ac->insert("hers");
    ac->insert("his");
    ac->build();
    std::cout << *ac << std::endl;
    //std::cout << ac->query("ushersheishis") << std::endl;
    return 0;
}
```