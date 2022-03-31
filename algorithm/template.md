---
title: 模板 - dianhsu.top
---
@import "/mystyle.less"

# 模板 {ignore=True}
> 返回:house:[首页](../index.html)，:rocket:[算法](../index.html)

[TOC]

## 字符串
### KMP字符串匹配
```cpp
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
```
### Manacher算法
```cpp
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

```
### 字符串Hash
```cpp
class StringHash{
public:
    static unsigned BKDR(const std::string& str){
        unsigned seed = 131; // 31 131 1313 13131 131313 etc..
        unsigned hash = 0;
        for(auto c: str){
            hash = hash * seed + c;
        }
        return (hash & 0x7FFFFFFF);
    }
    static unsigned AP(const std::string& str){
        unsigned hash = 0;
        for(int i = 0; i < str.length(); ++i){
            if(i & 1){
                hash ^= (~((hash << 11) ^ str[i] ^ (hash >> 5)));
            }else{
                hash ^= ((hash << 7) ^ str[i] ^ (hash >> 3));
            }
        }
        return (hash & 0x7FFFFFFF);
    }
    static unsigned DJB(const std::string& str){
        unsigned hash = 5381;
        for(auto c: str){
            hash += (hash << 5) + c;
        }
        return (hash & 0x7FFFFFFF);
    }
    static unsigned JS(const std::string& str){
        unsigned hash = 1315423911;
        for(auto c: str) hash ^= ((hash << 5) + c + (hash >> 2));
        return (hash & 0x7FFFFFFF);
    }
    static unsigned SDBM(const std::string& str){
        unsigned hash = 0;
        for(auto c: str) hash = c + (hash << 6) + (hash << 16) - hash;
        return (hash & 0x7FFFFFFF);
    }
    static unsigned PJW(const std::string& str){
        auto bits_in_unsigned_int = (unsigned)(sizeof(unsigned) * 8);
        auto three_quarters = (unsigned)(bits_in_unsigned_int * 3 / 4);
        auto one_eighth = (unsigned)(bits_in_unsigned_int / 8);
        unsigned high_bits = (unsigned)(0xFFFFFFFF) << (bits_in_unsigned_int - one_eighth);
        unsigned hash = 0;
        unsigned test = 0;
        for(auto c: str){
            hash = (hash << one_eighth) + c;
            if((test = hash & high_bits) != 0){
                hash = (hash ^ (test >> three_quarters)) & (~high_bits);
            }
        }
        return (hash & 0x7FFFFFFF);
    }
    static unsigned ELF(const std::string& str){
        unsigned hash = 0, x = 0;
        for(auto c: str){
            hash = (hash << 4) + c;
            if((x = hash & 0xF0000000ll) != 0){
                hash ^= (x >> 24);
                hash &= (~x);
            }
        }
        return (hash & 0x7FFFFFFF);
    }
};
```
### AC自动机(AC Automaton)

提供插入、构建、查询三个方法。

```cpp
namespace Automaton {
struct ACNode{
    vector<int> nex;
    int fail;
    int cnt;
    ACNode() : nex(26, 0), cnt(0), fail(0) { }
};
class AC{
public:
    AC(): nodes(1) { }
    void insert(const string& arg){
        int cur = 0;
        for(auto& c: arg){
            int to = c - 'a';
            if(!nodes[cur].nex[to]){
                nodes[cur].nex[to] = (int)nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].nex[to];
        }
        nodes[cur].cnt++;
    }
    void build(){
        queue<int> Q;
        for(int i = 0; i < 26; ++i) {
            if(nodes[0].nex[i]){
                Q.push(nodes[0].nex[i]);
            }
        }
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            for(int i = 0; i < 26; ++i){
                if(nodes[cur].nex[i]){
                    nodes[nodes[cur].nex[i]].fail = nodes[nodes[cur].fail].nex[i];
                    Q.push(nodes[cur].nex[i]);
                }else{
                    nodes[cur].nex[i] = nodes[nodes[cur].fail].nex[i];
                }
            }
        }
    }
    int query(const string& arg){
        int cur = 0, ans = 0;
        for(auto& c: arg){
            cur = nodes[cur].nex[c - 'a'];
            for(int j = cur; j and nodes[j].cnt != -1; j = nodes[j].fail){
                ans += nodes[j].cnt;
                nodes[j].cnt = -1;
            }
        }
        return ans;
    }
private:
    vector<ACNode> nodes;
};
}
```


### 后缀数组
```cpp
class SuffixArray {
private:
    void radixSort(int n, int m, int w, vector<int>& sa, vector<int>& rk, vector<int>& bucket, vector<int>& idx) {
        fill(all(bucket), 0);
        for (int i = 0; i < n; ++i) idx[i] = sa[i];
        for (int i = 0; i < n; ++i) ++bucket[rk[idx[i] + w]];
        for (int i = 1; i < m; ++i) bucket[i] += bucket[i - 1];

        for (int i = n - 1; i >= 0; --i) sa[--bucket[rk[idx[i] + w]]] = idx[i];
        fill(all(bucket), 0);
        for (int i = 0; i < n; ++i) idx[i] = sa[i];
        for (int i = 0; i < n; ++i) ++bucket[rk[idx[i]]];
        for (int i = 1; i < m; ++i) bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--bucket[rk[idx[i]]]] = idx[i];
    }
public:
    SuffixArray(const string& s) :
        n(s.length() + 1),
        m(max((int) s.length() + 1, 300)),
        rk(2, vector<int>((s.length() + 1) << 1)),
        bucket(max((int) s.length() + 1, 300)),
        idx(s.length() + 1),
        sa(s.length() + 1),
        ht(s.length()) {

        for (int i = 0; i < n; ++i) ++bucket[rk[0][i] = s[i]];
        for (int i = 1; i < m; ++i) bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--bucket[rk[0][i]]] = i;
        int pre = 1;
        int cur = 0;
        for (int w = 1; w < n; w <<= 1) {
            swap(cur, pre);
            radixSort(n, m, w, sa, rk[pre], bucket, idx);
            for (int i = 1; i < n; ++i) {
                if (rk[pre][sa[i]] == rk[pre][sa[i - 1]] and rk[pre][sa[i] + w] == rk[pre][sa[i - 1] + w]) {
                    rk[cur][sa[i]] = rk[cur][sa[i - 1]];
                } else {
                    rk[cur][sa[i]] = rk[cur][sa[i - 1]] + 1;
                }
            }
        }
        for (int i = 0, k = 0; i < n - 1; ++i) {
            if (k) --k;
            while (s[i + k] == s[sa[rk[cur][i] - 1] + k]) ++k;
            ht[rk[cur][i] - 1] = k;
        }
    }
    vector<int> sa;
    vector<int> ht;
private:
    int n, m;
    vector<vector<int>> rk;
    vector<int> bucket, idx;
};
```
## 图论

### 最短路
#### SPFA
```cpp
class SPFA {
private:
    const static int maxn = 1010;
    const static int maxm = 100100;
    const static int maxv = 0x3f3f3f3f;
    int head[maxn];
    int pre[maxm];
    int vis[maxn];
public:
    int u[maxm], v[maxm], cost[maxm];
    int edge_cnt;
    int ans[maxn];
    void init() {
        memset(head, -1, sizeof head);
        edge_cnt = 0;
    }
    void add_edge(int a, int b, int c) {
        u[edge_cnt] = a;
        v[edge_cnt] = b;
        cost[edge_cnt] = c;
        pre[edge_cnt] = head[a];
        head[a] = edge_cnt++;
    }
    int solve(int st, int ed) {
        memset(ans, 0x3f, sizeof ans);
        memset(vis, 0, sizeof vis);
        ans[st] = 0;
        queue<int> Q;
        Q.push(st);
        vis[st] = 1;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            vis[x] = 0;
            for (int i = head[x]; i != -1; i = pre[i]) {
                if (ans[v[i]] > ans[x] + cost[i]) {
                    ans[v[i]] = ans[x] + cost[i];
                    if (vis[v[i]] == 0) {
                        vis[v[i]] = 1;
                        Q.push(v[i]);
                    }
                }
            }
        }
        return ans[ed];
    }

}spfa;
```
### 网络流

#### Dinic
```cpp
template<typename cap_t>
class Dinic{
public:
    explicit Dinic(int n): node_cnt(n), g(n){}
    int add_edge(int from, int to, cap_t cap){
        int m = int(pos.size());
        pos.emplace_back(from, int(g[from].size()));
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if(from == to) to_id++;
        g[from].push_back(PrivateEdge{to, to_id, cap});
        g[to].push_back(PrivateEdge{from, from_id, 0});
        return m;
    }
    struct Edge{
        int from, to;
        cap_t cap, flow;
    };
    Edge getEdge(int idx){
        auto _e = g[pos[idx].first][pos[idx].second];
        auto _re = g[_e.to][_e.rev];
        return Edge{pos[idx].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<Edge> getEdges(){
        std::vector<Edge> result;
        for(int i = 0; i < pos.size(); ++i){
            result.push_back(getEdge(i));
        }
        return result;
    }
    cap_t flow(int st, int ed){
        return flow(st, ed, std::numeric_limits<cap_t>::max());
    }
    cap_t flow(int st, int ed, cap_t flow_limit){
        std::vector<int> level(node_cnt);
        std::queue<int> que;
        auto&& bfs = [&](){
            std::fill(level.begin(), level.end(), -1);
            level[st] = 0;
            while(!que.empty()){
                que.pop();
            }
            que.push(st);
            while(!que.empty()){
                int v = que.front();
                que.pop();
                for(PrivateEdge& e: g[v]){
                    if(e.cap == 0 or level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if(e.to == ed) continue;
                    que.push(e.to);
                }
            }
        };
        auto&& dfs = [&](auto&& self, int v, cap_t up){
            if(v == st) return up;
            cap_t res = 0;
            int level_v = level[v];
            for(int idx = 0; idx < int(g[v].size()); ++idx){
                PrivateEdge& edge = g[v][idx];
                if(level_v <= level[edge.to] or g[edge.to][edge.rev].cap == 0) continue;
                cap_t delta = self(self, edge.to, std::min(up - res, g[edge.to][edge.rev].cap));
                if(delta <= 0) continue;
                g[v][idx].cap += delta;
                g[edge.to][edge.rev].cap -= delta;
                res += delta;
                if(res == up) return res;
            }
            level[v] = node_cnt;
            return res;
        };
        cap_t ans = 0;
        while (ans < flow_limit){
            bfs();
            if(level[ed] == -1) break;
            cap_t delta = dfs(dfs, ed, flow_limit - ans);
            if(!delta) break;
            ans += delta;
        }
        return ans;
    }
private:
    struct PrivateEdge{
        int to, rev;
        cap_t cap;
    };
    int node_cnt;
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<PrivateEdge>> g;
};
```

### Tarjan
> 解决关键边和关键点很好用

```cpp
const int maxn = 100100;
int dfn[maxn], low[maxn];
int tim;
int vis[maxn];
int sd[maxn];
std::stack<int> st;
vector<vector<int>> g;
void tarjan(int cur){
    dfn[cur] = low[cur] = ++tim; 
    vis[cur] = 1;
    st.push(cur);
    for(auto& nex: g[cur]){
        if(!dfn[nex]){
            tarjan(nex);
            low[cur] = min(low[cur], low[nex]);
        }else if(vis[nex]){
            low[cur] = min(low[cur], dfn[nex]);
        }
    }
    if(dfn[cur] == low[cur]){
        while(!st.empty()){
            auto pos = st.top();
            st.pop();
            vis[pos] = 0;
            sd[pos] = cur;
            if(pos == cur) break;
        }
    }
}

```
## 数学

### 拓展欧几里得

```cpp
template<typename T>
T exgcd(T a, T b, T& x, T& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    T d = exgcd(b, a % b, x, y);
    T tmp = x;
    x = y;
    y = tmp - a / b * y;
    return d;
}
```
### 欧拉函数
#### 单个欧拉函数
```cpp
int euler_phi(int n) {
  int ans = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}
```
#### 批量求欧拉函数（线性筛）
```cpp
vector<int> eularFunction(int n){
    vector<int> isPrime(n + 1, 1), phi(n + 1, 0);
    vector<int> prime;
    int cnt = 0;
    isPrime[1] = 0;
    phi[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(isPrime[i]){
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for(auto it: prime){
            if(i * it > n) break;
            isPrime[i * it] = 0;
            if(i % it){
                phi[i * it] = phi[i] * phi[it];
            }else{
                phi[i * it] = phi[i] * it;
                break;
            }
        }
    }
    return phi;
}
```

### 矩阵
>  矩阵模板，搭配模数可以当成矩阵快速幂。
```cpp
template<typename T>
struct Matrix{
    std::vector<T> data;
    int sz;
    // 构造全0矩阵，或者斜对角填上自定义数字
    Matrix(int sz, T v = 0): sz(sz), data(sz * sz, 0){
        int cur = 0;
        do{
            data[cur] = v;
            cur += sz + 1;
        }while(cur < sz * sz);
    }
    //从vector中构造矩阵
    Matrix(int sz, std::vector<T>& arg): sz(sz), data(sz * sz, 0){
        assert(arg.size() >= sz * sz);
        for(int i = 0; i < sz * sz; ++i) data[i] = arg[i];
    }
    //从vector中构造矩阵，右值
    Matrix(int sz, std::vector<T>&& arg): sz(sz), data(sz * sz, 0){
        assert(arg.size() >= sz * sz);
        for(int i = 0; i < sz * sz; ++i) data[i] = arg[i];
    }
    Matrix operator + (const Matrix& arg){
        assert(sz == arg.sz);
        Matrix ret(sz);
        for(int i = 0; i < sz * sz; ++i){
            ret.data[i] = arg.data[i] + data[i];
        }
        return ret;
    }
    Matrix operator * (const Matrix& arg){
        assert(sz == arg.sz);
        Matrix ret(sz);
        for(int i = 0; i < sz; ++i){
            for(int j = 0; j < sz; ++j){
                for(int k = 0; k < sz; ++k){
                    ret.data[i * sz + j] += data[i * sz + k] * arg.data[k * sz + j];
                }
            }
        }
        return ret;
    }
    Matrix operator - (const Matrix& arg){
        assert(sz == arg.sz);
        Matrix ret(sz);
        for(int i = 0; i < sz * sz; ++i) ret.data[i] = data[i] - arg.data[i];
        return ret;
    }
    friend std::ostream & operator << (std::ostream& ots, const Matrix& arg){
        for(int i = 0; i < arg.sz; ++i){
            for(int j = 0; j < arg.sz; ++j){
                if(j) ots << " ";
                ots << arg.data[i * arg.sz + j];
            }
            if(i + 1 != arg.sz) ots << "\n";
        }
        return ots;
    }
};
```
### 素数筛
#### 单个正整数判断是不是质数
```cpp
bool isPrime(int x){
    if(x <= 1) return false;
    int cur = 2;
    while(cur * cur <= x){
        if(x % cur != 0){
            return false;
        }
        ++cur;
    }
    return true;
}
```
#### 埃拉托斯特尼筛法
```cpp
template<int N>
vector<int> SieveOfEratosthenes() {
    vector<int> prime;
    bitset<N + 1> notPrime;
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!notPrime[i]) {
            prime.push_back(i);
            if ((long long) i * i <= N) {
                for (int j = i * i; j <= N; j += i) {
                    notPrime[j] = 1;
                }
            }
        }
    }
    return prime;
}

```
#### 线性筛（欧式筛）
```cpp
template<int N>
vector<int> SieveOfEuler() {
    vector<int> prime;
    bitset<N + 1> notPrime;
    for (int i = 2; i <= N; ++i) {
        if (!notPrime[i]) {
            prime.push_back(i);
        }
        for (auto it : prime) {
            if ((long long) it * i <= N) {
                notPrime[it * i] = 1;
                if (i % it == 0) {
                    break;
                }
            }else{
                break;
            }
        }
    }
    return prime;
}
```

#### 奇数筛
```cpp
template<int N>
vector<int> OddFilter() {
    if (N < 2) return {};
    vector<int> prime{2};
    bitset<N + 1> notPrime;
    notPrime[0] = notPrime[1] = 1;
    for (int i = 3; i * i <= N; i += 2) {
        if (!notPrime[i]) {
            for (int j = i; j * i <= N; j += 2) {
                notPrime[j * i] = 1;
            }
        }
    }
    for (int i = 3; i <= N; i += 2) {
        if (!notPrime[i]) {
            prime.push_back(i);
        }
    }
    return prime;
}
```
### 乘法逆元
#### 扩展欧几里得算法
```cpp

template<typename T>
class ExGcd {
public:
    /*
     * @brief 拓展欧几里得算法
     * @note 要求a和p的最大公约数是1
     */
    static T inv(T a, T p) {
        T x, y;
        if (step(a, p, x, y) != 1) // 无解的情形
            return -1;
        return (x % p + p) % p;
    }

private:
    static T step(T a, T b, T &x, T &y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        T d = step(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
};

```
#### 快速幂算法

```cpp
template<typename T>
class QPow {
public:
    /*
     * @brief 快速幂算法，根据费马小定理
     * @note 要求p是质数
     */
    static T inv(T a, T p) {
        return step(a, p - 2, p);
    }

private:
    static T step(T a, T n, T p) {
        T ans = 1;
        while (n) {
            if (n & 1)
                ans = ans % p * a % p;
            a = a % p * a % p;
            n >>= 1;
        }
        return ans;
    }
};
```

#### 批量乘法逆元
> MOD需要是质数
```cpp
vector<int> LinearReverse(int n, int MOD){
    std::vector<int> inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        inv[i] = (long long) (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    return inv;
}
```

### 阶乘逆元（求组合数）

```cpp
const int maxn = 200200;
const int MOD = 1e9 + 7;
long long divInv[maxn + 1], mulInv[maxn + 1];

ll qPow(ll b, ll k) {
    if (k == 0) return 1;
    long long ans = 1;
    while (k) {
        if (k & 1) ans = ans * b % MOD;
        k >>= 1;
        b = b * b % MOD;
    }
    return ans;
}

void init() {
    divInv[0] = 1;
    mulInv[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        mulInv[i] = (mulInv[i - 1] * i) % MOD;
    }
    divInv[maxn] = qPow(mulInv[maxn], MOD - 2) % MOD;
    for(int i = maxn - 1; i > 0; --i){
        divInv[i] = divInv[i + 1] * (i + 1) % MOD;
    }
}
ll C(int n, int m) {
    if (m < 0) return 0;
    if (m > n) return 0;
    return  mulInv[n] * divInv[m] % MOD * divInv[n - m] % MOD;
}

```

### 莫比乌斯函数（线性筛）
```cpp
template<int N, typename T = int>
class Mu {
public:
    Mu() : muArr(N + 1), pref(N + 1) {
        bitset<N + 1> notPrime;
        muArr[1] = 1;
        for (int i = 2; i <= N; ++i) {
            if (!notPrime[i]) {
                prime.push_back(i);
                muArr[i] = -1;
            }
            for (auto it : prime) {
                if (N / i >= it) {
                    notPrime[it * i] = 1;
                    if (i % it == 0) {
                        break;
                    } else {
                        muArr[i * it] = -muArr[i];
                    }
                } else {
                    break;
                }
            }
        }
        pref[0] = 0;
        for (int i = 1; i <= N; ++i) {
            pref[i] = pref[i - 1] + muArr[i];
        }
    }

    T& operator[](int i) {
        return muArr[i];
    }

    vector<T> pref;
    vector<T> prime;
private:
    vector<T> muArr;
};

```

### 康拓展开
#### 正向

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
#### 反向
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

## 数据结构

### 线段树

```cpp
// Luogu P3373
template<typename T = int>
inline T read() {
    T ret;
    cin >> ret;
    return ret;
}

template<class Fun>
class Y_combinator {
private:
    Fun fun_;
public:
    template<class F>
    Y_combinator(F&& fun) : fun_(static_cast<F&&>(fun)) {}
    template<class... Args>
    decltype(auto) operator () (Args&&...args) const {
        return fun_(*this, static_cast<Args&&>(args)...);
    }
};
template<class T> Y_combinator(T)->Y_combinator<T>;

#define MID ((l + r) >> 1)
#define LEFT (cur << 1)
#define RIGHT ((cur << 1) | 1)

int main(int argc, char* argv[]) {
    fastIO();
    int n, m;
    cin >> n >> m;
    vector<ll> arr{0};
    for (int i = 0; i < n; ++i) {
        arr.push_back(read<ll>());
    }
    vector<ll> lazy((n << 2) + 10);
    vector<ll> node((n << 2) + 10);
    Y_combinator(
        [&](auto&& build, int cur, int l, int r) -> void {
            if (l == r) {
                node[cur] = arr[l];
            } else {
                build(LEFT, l, MID);
                build(RIGHT, MID + 1, r);
                node[cur] = node[LEFT] + node[RIGHT];
            }
        }
    )(1, 1, n);
    auto&& lazyUpdate = [&](int cur, int l, int r) -> void {
        if (lazy[cur] != 0) {
            node[LEFT] += lazy[cur] * (MID - l + 1);
            node[RIGHT] += lazy[cur] * (r - MID);
            lazy[LEFT] += lazy[cur];
            lazy[RIGHT] += lazy[cur];
            lazy[cur] = 0;
        }
    };
    auto&& update = Y_combinator(
        [&](auto&& update, int cur, int l, int r, int s, int e, ll v) {
            if (s > r or e < l) return;
            if (s <= l and r <= e) {
                node[cur] += (r - l + 1) * v;
                lazy[cur] += v;
            } else {
                lazyUpdate(cur, l, r);
                update(LEFT, l, MID, s, e, v);
                update(RIGHT, MID + 1, r, s, e, v);
                node[cur] = node[LEFT] + node[RIGHT];
            }
        }
    );
    auto&& query = Y_combinator(
        [&](auto&& query, int cur, int l, int r, int s, int e)->ll {
            if (s > r or e < l) return 0;
            if (s <= l and e >= r) {
                return node[cur];
            }
            lazyUpdate(cur, l, r);
            ll ret = query(LEFT, l, MID, s, e);
            ret += query(RIGHT, MID + 1, r, s, e);
            return ret;
        }
    );
    while (m--) {
        int q, x, y, k;
        cin >> q >> x >> y;
        if (q == 1) {
            cin >> k;
            update(1, 1, n, x, y, k);
        } else {
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
```
### ST表（稀疏表）(C++17)

```cpp
template<typename iter, typename BinOp>
class SparseTable {
    using T = typename remove_reference<decltype(*declval<iter>())>::type;
    vector<vector<T>> arr;
    BinOp binOp;
public:
    SparseTable(iter begin, iter end, BinOp binOp) : arr(1), binOp(binOp) {
        int n = distance(begin, end);
        arr.assign(32 - __builtin_clz(n), vector<T>(n));
        arr[0].assign(begin, end);
        for (int i = 1; i < arr.size(); ++i) {
            for (int j = 0; j < n - (1 << i) + 1; ++j) {
                arr[i][j] = binOp(arr[i - 1][j], arr[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T query(int lPos, int rPos) {
        int h = floor(log2(rPos - lPos + 1));
        return binOp(arr[h][lPos], arr[h][rPos - (1 << h) + 1]);
    }
};
```

### 树状数组

```cpp
template<typename T>
struct FenWick {
    int N;
    vector<T> arr;
    FenWick(int sz): N(sz), arr(sz + 1, 0) {}
    void update(int pos, T val) {
        for (; pos <= N;pos |= (pos + 1)) {
            arr[pos] += val;
        }
    }
    // 获取 [1, pos] 的和
    T get(int pos) {
        T ret = 0;
        for (; pos > 0; --pos) {
            ret += arr[pos];
            pos &= (pos + 1);
        }
        return ret;
    }
    // 获取 [l, r] 的和
    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};
```
### 珂朵莉树
```cpp
namespace Chtholly{
struct Node{
    int l, r;
    mutable int v;
    Node(int il, int ir, int iv): l(il), r(ir), v(iv){}
    bool operator < (const Node& arg) const{
        return l < arg.l;
    }
};
class Tree{
protected:
    auto split(int pos){
        if(pos > _sz) return odt.end();
        auto it = --odt.upper_bound(Node{pos, 0, 0});
        if(it->l == pos) return it;
        auto tmp = *it;
        odt.erase(it);
        odt.insert({tmp.l, pos - 1, tmp.v});
        return odt.insert({pos, tmp.r, tmp.v}).first;
    }  
public:
    Tree(int sz, int ini = 1): _sz(sz), odt({Node{1, sz, ini}}) {}
    virtual void assign(int l, int r, int v){
        auto itr = split(r + 1), itl = split(l);
        // operations here
        odt.erase(itl, itr);
        odt.insert({l, r, v});
    }
protected:
    int _sz;
    set<Node> odt;
};
}

```

## 其他
### 读入
```cpp
template<typename T = int>
inline T fastRead() {
    T x = 0, w = 1; char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') w = -1; c = getchar(); }
    while (c <= '9' && c >= '0') { x = (x << 1) + (x << 3) + c - '0'; c = getchar(); }
    return w == 1 ? x : -x;
}
template<typename T = int>
inline T read() {
    T ret;
    cin >> ret;
    return ret;
}
```
### Y combinator (C++17)

```cpp
template<class Fun>
class Y_combinator {
private:
    Fun fun_;
public:
    template<class F>
    Y_combinator(F&& fun) : fun_(static_cast<F&&>(fun)) {}
    template<class... Args>
    decltype(auto) operator () (Args&&...args) const {
        return fun_(*this, static_cast<Args&&>(args)...);
    }
};
template<class T> Y_combinator(T)->Y_combinator<T>;
```

### 模数(int)

```cpp
class ModNum{
public:
    static int selfPow(int base, int p){
        int ret = 1;
        while(p){
            if(p & 1) ret = (ret * 1ll * base) % MOD;
            p >>= 1;
            base = (ret * 1ll * base) % MOD;
        }
        return ret;
    }
    ModNum(): val(0) {}
    ModNum(int tv): val(tv) {}
    ModNum operator + (const ModNum& arg){ return ModNum((val * 1ll + arg.val) % MOD); }
    ModNum operator - (const ModNum& arg){ return ModNum((val * 1ll + MOD - arg.val) % MOD); }
    ModNum operator * (const ModNum& arg){ return ModNum((val * 1ll * arg.val) % MOD); }
    ModNum operator / (const ModNum& arg){ return ModNum((val * 1ll * selfPow(arg.val, MOD - 2)) % MOD); }
    ModNum operator + (const int argv){ return ModNum((val * 1ll + argv) % MOD); }
    ModNum operator - (const int argv){ return ModNum((val * 1ll + MOD - argv) % MOD); }
    ModNum operator * (const int argv){ return ModNum((val * 1ll * argv) % MOD); }
    ModNum operator / (const int argv){ return ModNum((val * 1ll * selfPow(argv, MOD - 2)) % MOD); }
    ModNum& operator += (const ModNum& arg){
        this->val = (this->val * 1ll + arg.val) % MOD;
        return *this;
    }
    ModNum& operator -= (const ModNum& arg){
        this->val = (this->val * 1ll + MOD - arg.val) % MOD;
        return *this;
    }
    ModNum& operator *= (const ModNum& arg){
        this->val = (this->val * 1ll * arg.val) % MOD;
        return *this;
    }
    ModNum& operator /= (const ModNum& arg){
        this->val = (this->val * 1ll * selfPow(arg.val, MOD - 2)) % MOD;
        return *this;
    }
    ModNum& operator += (const int argv){
        this->val = (this->val * 1ll + argv) % MOD;
        return *this;
    }
    ModNum& operator -= (const int argv){
        this->val = (this->val * 1ll + MOD - argv) % MOD;
        return *this;
    }
    ModNum& operator *= (const int argv){
        this->val = (this->val * 1ll * argv) % MOD;
        return *this;
    }
    ModNum& operator /= (const int argv){
        this->val = (this->val * 1ll * selfPow(argv, MOD - 2)) % MOD;
        return *this;
    }
    ModNum& operator = (const ModNum& arg){
        this->val = arg.val % MOD;
        return *this;
    }
    ModNum& operator = (const int argv){
        this->val = argv % MOD;
        return *this;
    }
    int get(){
        return this->val;
    }
    friend ModNum operator + (const int argv, const ModNum& arg){
        return ModNum((arg.val * 1ll + argv) % MOD);
    }
    friend ModNum operator - (const int argv, const ModNum& arg){
        return ModNum((argv * 1ll + MOD - arg.val) % MOD);
    }
    friend ModNum operator * (const int argv, const ModNum& arg){
        return ModNum((arg.val * 1ll * argv) % MOD);
    }
    friend ModNum operator / (const int argv, const ModNum& arg){
        return ModNum((argv * 1ll * ModNum::selfPow(arg.val, MOD - 2))% MOD);
    }
    friend istream& operator >> (istream& its, ModNum& arg){
        its >> arg.val;
        return its;
    }
    friend ostream& operator << (ostream& ots, const ModNum& arg){
        ots << arg.val;
        return ots;
    }
private:
    int val;
};
```