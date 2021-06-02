@import "/mystyle.less"

## 康拓展开
> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---

参考：[康拓展开_维基百科](https://zh.wikipedia.org/wiki/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80)

康拓展开是一个全排列到一个自然数的双射，常用于构建hash表时的空间压缩。
康拓展开的实质是计算**当前排列在所有由小到大全排列中的顺序**，因此是可逆的。

### 公式

$$X=a_0(n-1)! + a_{1}(n-2)! + \dots + a_{n-1} \cdot 0!$$
其中，$a_i$为整数，并且$0 \leq a_i < i, 1 \leq i \leq n$
$a_i$的意义参见举例中的解释部分

### 举例
例如，`3 5 7 4 1 2 9 6 8` 展开为 `98884`。因为`X=2*8!+3*7!+4*6!+2*5!+0*4!+0*3!+2*2!+0*1!+0*0!=98884`。

解释：
排列的第一位是3，比3小的数有两个，以这样的数开始的排列有8!个，因此第一项为2\*8!
排列的第二位是5，比5小的数有1、2、3、4，由于3已经出现，因此共有3个比5小的数，这样的排列有7!个，因此第二项为3\*7!
以此类推，直至0\*0!

### 例题
#### HDU 1043
> [http://acm.hdu.edu.cn/showproblem.php?pid=1043](http://acm.hdu.edu.cn/showproblem.php?pid=1043)

**关键词**：广度优先搜索，康拓展开，预处理

```cpp
/**
 * @brief 康拓展开
 * @param t 排列，这里设定排列的长度是9
 * @return Contar值
 * @author dianhsu
 **/
int radix[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
template<int LEN=9>
int Contar(int* t){
    int ret = 0;
    for(int i = 0; i < LEN; ++i){
        int tmp = 0;
        for(int j = i + 1; j < LEN; ++j){
            if(t[i] > t[j]){
                ++tmp;
            }
        }
        ret += radix[LEN - 1 - i] * tmp;
    }
    return ret;
}
```

既然康托展开是一个双射，那么一定可以通过康托展开值求出原排列，即可以求出 $n$ 的全排列中第 $x$ 大排列。

```cpp
/**
 * @brief 康拓展开的逆运算
 * @param contar_val Contar 值
 * @param t 返回的Contar序列
 * @author dianhsu
 * */
int radix[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
template<int LEN=9>
void ReverseContar(int contar_val, int* t){
    int vis[LEN];
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < LEN; ++i){
        int idx = contar_val / radix[LEN - 1 - i];
        contar_val = contar_val % radix[LEN - 1 - i];
        for(int j = 0; j < LEN; ++j){
            if(vis[j] == 0){
                if(idx == 0){
                    vis[j] = 1;
                    t[i] = j;
                    break;
                }else{
                    --idx;
                }
            }
        }
    }
}
```

### 题目思路

考虑从结果反推得到所有情况，需要用康拓展开保存压缩所有的情况，从结果反推的这个过程可以预处理。

```cpp
#include <bits/stdc++.h>
using namespace std;
int radix[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int Cantor(int *t){ // Contar Function
    int ret = 0;
    int counted;
    for(int i = 0; i < 9; ++i){
        counted = 0;
        for(int j = i + 1; j < 9; ++j){
            if(t[i] > t[j]) counted++;
        }
        ret += counted * radix[8-i];
    }
    return ret;
}
int dx[] = {0, 0, 1, -1};   // direction x
int dy[] = {1, -1, 0, 0};   // direction y
char dr[] = "lrud";         // direction char
struct Node{
    int t[9], x, y, dir;
    int cantor, prev;
}node[370000];
int vis[370000];
queue<int> Q;
bool check(int x, int y){
    return x >= 0 and x < 3 and y >= 0 and y < 3;
}
void solve(){   // pre-solve function
    while(!Q.empty()) Q.pop();
    int t[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int st_can = Cantor(t);
    node[st_can].prev = -1;
    node[st_can].dir = -1;
    for(int i = 0; i < 9; ++i){
        node[st_can].t[i] = t[i];
    }
    node[st_can].x = node[st_can].y = 2;
    memset(vis, 0, sizeof vis);
    vis[st_can] = 1;
    Q.push(st_can);
    int Sum = 0;
    while(!Q.empty()){
        ++Sum;
        int tmp = Q.front();
        Q.pop();
        for(int i = 0; i < 4; ++i){
            Node e = node[tmp];
            int nx = e.x + dx[i];
            int ny = e.y + dy[i];
            if(check(nx, ny)){
                int c = e.t[nx * 3 + ny];
                e.t[nx * 3 + ny] = e.t[e.x * 3 + e.y];
                e.t[e.x * 3 + e.y] = c;
                e.x = nx;
                e.y = ny;
                e.prev = tmp;
                e.cantor = Cantor(e.t);
                e.dir = i;
                if(!vis[e.cantor]){
                    vis[e.cantor] = 1;
                    node[e.cantor] = e;
                    Q.push(e.cantor);
                }
            }
        }
    }
}
int main(){
    solve();
    char tmp[4];
    int t[9];
    while(scanf("%s", tmp) != EOF){
        if(isdigit(tmp[0])){
            t[0] = tmp[0] - '0';
        }else{
            t[0] = 0;
        }
        for(int i = 1; i < 9; ++i){
            scanf("%s", tmp);
            if(isdigit(tmp[0])){
                t[i] = tmp[0] - '0';
            }else{
                t[i] = 0;
            }
        }
        int tmp = Cantor(t);
        // if we found the cantor value not in pre-solve visit array, it means we will not reach this situation.
        if(vis[tmp]){
            while(node[tmp].prev >= 0){
                
                printf("%c", dr[node[tmp].dir]);
                tmp = node[tmp].prev;
            }
            puts("");
        }else{
            puts("unsolvable");
        }
    }
    return 0;
}
```