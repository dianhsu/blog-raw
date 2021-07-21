---
title: 模板 - dianhsu.top
---
@import "/mystyle.less"

# 模板 {ignore=True}
> 返回:house:[首页](../index.html)

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
#### BKDRHash算法
```cpp
// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### APHash算法
```cpp
// AP Hash Function
unsigned int APHash(char *str)
{
    unsigned int hash = 0;
    int i;
 
    for (i=0; *str; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### DJBHash算法
```cpp
// DJB Hash Function
unsigned int DJBHash(char *str)
{
    unsigned int hash = 5381;
 
    while (*str)
    {
        hash += (hash << 5) + (*str++);
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### JSHash算法

```cpp
// JS Hash Function
unsigned int JSHash(char *str)
{
    unsigned int hash = 1315423911;
 
    while (*str)
    {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### RSHash算法

```cpp
// RS Hash Function
unsigned int RSHash(char *str)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
 
    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### SDBMHash算法

```cpp
unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0;
 
    while (*str)
    {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### PJWHash算法

```cpp
// P. J. Weinberger Hash Function
unsigned int PJWHash(char *str)
{
    unsigned int BitsInUnignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    unsigned int ThreeQuarters    = (unsigned int)((BitsInUnignedInt  * 3) / 4);
    unsigned int OneEighth        = (unsigned int)(BitsInUnignedInt / 8);
    unsigned int HighBits         = (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);
    unsigned int hash             = 0;
    unsigned int test             = 0;
 
    while (*str)
    {
        hash = (hash << OneEighth) + (*str++);
        if ((test = hash & HighBits) != 0)
        {
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }
 
    return (hash & 0x7FFFFFFF);
}
```

#### ELFHash算法

```cpp
// ELF Hash Function
unsigned int ELFHash(char *str)
{
    unsigned int hash = 0;
    unsigned int x    = 0;
 
    while (*str)
    {
        hash = (hash << 4) + (*str++);
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
 
    return (hash & 0x7FFFFFFF);
}
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
class Dinic {
private:
    const static int maxn = 1010;   // 节点数量
    const static int maxm = 200100; // 二倍边的数量
    const static int maxv = 0x3f3f3f3f; // 传说中的inf
    int head[maxn];
    int u[maxm], v[maxm], pre[maxm], cap[maxm], flow[maxm];
    int edge_cnt;
    int vis[maxn];
    int dis[maxn];
    bool _bfs(int st, int ed) {
        memset(vis, 0, sizeof vis);
        dis[st] = 0;
        vis[st] = 1;
        queue<int> Q;
        Q.push(st);
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = head[x]; i != -1; i = pre[i]) {
                if (vis[v[i]] == 0 and cap[i] > flow[i]) {
                    vis[v[i]] = 1;
                    dis[v[i]] = dis[x] + 1;
                    Q.push(v[i]);
                }
            }
        }
        return vis[ed];
    }
    int _dfs(int cur, int val, int ed) {
        if (cur == ed or val == 0) return val;
        int ret = 0;
        int tmp;
        for (int i = head[cur]; i != -1; i = pre[i]) {
            if (dis[v[i]] == dis[u[i]] + 1 and (tmp = _dfs(v[i], min(val, cap[i] - flow[i]), ed)) > 0) {
                flow[i] += tmp;
                flow[i ^ 1] -= tmp;
                ret += tmp;
                val -= tmp;
                if (val == 0) break;
            }
        }
        return ret;
    }
public:
    /**
     * @brief 初始化
     *
     * */
    void init() {
        edge_cnt = 0;
        memset(head, -1, sizeof head);
    }
    /**
     * @brief 添加边
     * @param a 起点
     * @param b 终点
     * @param c 最大容量
     * @note 链式前向星
     * */
    void add_edge(int a, int b, int c) {
        u[edge_cnt] = a;
        v[edge_cnt] = b;
        cap[edge_cnt] = c;
        flow[edge_cnt] = 0;
        pre[edge_cnt] = head[a];
        head[a] = edge_cnt++;

        u[edge_cnt] = b;
        v[edge_cnt] = a;
        cap[edge_cnt] = 0;
        flow[edge_cnt] = 0;
        pre[edge_cnt] = head[b];
        head[b] = edge_cnt++;
    }
    /**
     * @brief 求最大流
     * @param st 起点
     * @param ed 终点
     * */
    int solve(int st, int ed) {
        int ret = 0;
        while (_bfs(st, ed)) {
            ret += _dfs(st, maxv, ed);
        }
        return ret;
    }
}dinic;

```

## 数论

### 素数筛

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

```cpp
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
int main() {
    int a = 2, p = 1000000007;
    std::cout << ExGcd<long long>::inv(a, p) << std::endl;
    std::cout << QPow<long long>::inv(a, p) << std::endl;
    auto vec = LinearInverse<long long>::build(10, p);
    for(auto it: vec){
        std::cout << it << std::endl;
    }
    return 0;
}
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
### AVL树
```cpp

template<class T>
struct AVLNode {
    T data;
    AVLNode<T> *leftChild;
    AVLNode<T> *rightChild;
    int height;
    AVLNode(T data): data(data), height(1), leftChild(nullptr), rightChild(nullptr) { }
    ~AVLNode() {
        delete leftChild;
        delete rightChild;
    }
};

template<class T>
class AVL {
public:
    AVL() {
        root = nullptr;
    }

    ~AVL() {
        delete root;
    }

    /**
     * @brief 将结点插入到AVL树中
     * @param val 需要插入的值
     * @note 如果发现这个树中已经有这个值存在了，就不会进行任何操作
     * */
    void insert(T val) {
        _insert(&root, val);
    }

    /**
     * @brief 检查结点是否在AVL树中
     * @param val 需要检查的值
     * */
    bool exist(T val) {
        auto ptr = &root;
        while (*ptr != nullptr) {
            if (val == (*ptr)->data) {
                return true;
            } else if (val < (*ptr)->data) {
                *ptr = (*ptr)->leftChild;
            } else {
                *ptr = (*ptr)->rightChild;
            }
        }
        return false;
    }

    /**
     * @brief 找到值为val的结点
     * @param val 目标值
     * @return 返回值为指向该结点的指针的地址
     */
    AVLNode<T> **find(T val) {
        auto ptr = &root;
        while ((*ptr) != nullptr) {
            if (val == (*ptr)->data) {
                break;
            } else if (val < (*ptr)->data) {
                *ptr = (*ptr)->leftChild;
            } else {
                *ptr = (*ptr)->rightChild;
            }
        }
        return ptr;
    }

    /**
     * @brief 删除结点
     * @note 首先找到结点，然后将结点旋转到叶子结点，然后回溯检查树的平衡性
     * @param val 需要删除的结点的值
     * @note 这个地方需要递归寻找该值的结点，因为需要回溯更新平衡树
     * */
    void remove(T val) {
        _remove(&root, val);
    }

    /**
     * @brief 生成Mermaid图形
     * @note 只是为了debug用的，可以将图形放到Mermaid中，方便观察二叉树的形状
     * @ref https://mermaid-js.github.io/mermaid-live-editor
     * */
    friend std::ostream &operator<<(std::ostream &os, AVL &avl) {
        os << "graph LR" << std::endl;
        std::string name = "Node1";
        if (avl.root != nullptr) {
            avl._generate(os, avl.root, name);
        } else {
            os << "  " << name << "[ nullptr ]" << std::endl;
        }
        return os;
    }
private:
    void _remove(AVLNode<T> **ptr, T val) {
        if (*ptr == nullptr) {
            return;
        }
        if ((*ptr)->data == val) {
            _rotateNodeToLeaf(ptr);
        } else if ((*ptr)->data < val) {
            _remove(&((*ptr)->rightChild), val);
        } else {
            _remove(&((*ptr)->leftChild), val);
        }
        // 完了之后回溯，重新平衡二叉树
        _balance(ptr);
        _updateHeight(*ptr);
    }

    /**
     * @brief 将一个结点旋转到叶子结点
     * @param ptr 将要被旋转至叶子的结点的指针的地址
     * @note 旋转的时候，将当前结点旋转到高度比较小的一边。
     */
    void _rotateNodeToLeaf(AVLNode<T> **ptr) {
        // 当前结点已经是叶子结点了
        if ((*ptr)->leftChild == nullptr and (*ptr)->rightChild == nullptr) {
            *ptr = nullptr;
            return;
        }
        int leftHeight = (*ptr)->leftChild != nullptr ? (*ptr)->leftChild->height : 0;
        int rightHeight = (*ptr)->rightChild != nullptr ? (*ptr)->rightChild->height : 0;
        // 左边高度比较小，左旋
        if (leftHeight <= rightHeight) {
            _leftRotate(ptr);
            _rotateNodeToLeaf(&((*ptr)->leftChild));
        } else {
            // 右旋
            _rightRotate(ptr);
            _rotateNodeToLeaf(&((*ptr)->rightChild));
        }
        _balance(ptr);
        _updateHeight(*ptr);
    }

    /**
     * @brief 生成Mermaid图形的步骤
     *
     * */
    void _generate(std::ostream &os, AVLNode<T> *ptr, std::string &name) {
        if (ptr->leftChild != nullptr) {
            os << "  " << name << "[ " << ptr->data << " ] -- Left --> ";
            name += '0';
            os << name << "[ " << ptr->leftChild->data << " ]" << std::endl;
            _generate(os, ptr->leftChild, name);
            name.pop_back();
        }
        if (ptr->rightChild != nullptr) {
            os << "  " << name << "[ " << ptr->data << " ] -- Right --> ";
            name += '1';
            os << name << "[ " << ptr->rightChild->data << " ]" << std::endl;
            _generate(os, ptr->rightChild, name);
            name.pop_back();
        }
    }

    /**
     * @brief 插入结点
     *
     * */
    void _insert(AVLNode<T> **ptr, T val) {
        if (*ptr == nullptr) {
            *ptr = new AVLNode<T>(val);
            return;
        }
        if (val < (*ptr)->data) {
            _insert(&((*ptr)->leftChild), val);
        } else if (val > (*ptr)->data) {
            _insert(&((*ptr)->rightChild), val);
        } else {
            // 如果当前平衡二叉树中已经存在这个结点了，不做任何处理
            return;
        }
        _balance(ptr);
        _updateHeight(*ptr);
    }

    /**
     * @brief 平衡结点
     *
     * */
    void _balance(AVLNode<T> **ptr) {
        if (*ptr == nullptr) return;
        int leftHeight = (*ptr)->leftChild != nullptr ? (*ptr)->leftChild->height : 0;
        int rightHeight = (*ptr)->rightChild != nullptr ? (*ptr)->rightChild->height : 0;
        if (abs(leftHeight - rightHeight) <= 1) return;

        if (leftHeight < rightHeight) {
            auto rightElement = (*ptr)->rightChild;
            int rightElementLeftHeight = rightElement->leftChild != nullptr ? rightElement->leftChild->height : 0;
            int rightElementRightHeight = rightElement->rightChild != nullptr ? rightElement->rightChild->height : 0;
            if (rightElementLeftHeight < rightElementRightHeight) {
                // RR
                _leftRotate(ptr);
            } else {
                // RL
                _rightRotate(&((*ptr)->rightChild));
                _leftRotate(ptr);
            }
        } else {
            auto leftElement = (*ptr)->leftChild;
            int leftElementLeftHeight = leftElement->leftChild != nullptr ? leftElement->leftChild->height : 0;
            int leftElementRightHeight = leftElement->rightChild != nullptr ? leftElement->rightChild->height : 0;
            if (leftElementLeftHeight > leftElementRightHeight) {
                // LL
                _rightRotate(ptr);
            } else {
                // LR
                _leftRotate(&((*ptr)->leftChild));
                _rightRotate(ptr);
            }
        }
    }

    /**
     * @brief 右旋
     *
     * */
    void _rightRotate(AVLNode<T> **ptr) {
        auto tmp = (*ptr)->leftChild;
        (*ptr)->leftChild = tmp->rightChild;
        tmp->rightChild = *ptr;
        _updateHeight(tmp);
        _updateHeight(*ptr);
        *ptr = tmp;
    }

    /**
     * @brief 左旋
     * */
    void _leftRotate(AVLNode<T> **ptr) {
        auto tmp = (*ptr)->rightChild;
        (*ptr)->rightChild = tmp->leftChild;
        tmp->leftChild = *ptr;
        _updateHeight(tmp);
        _updateHeight(*ptr);
        *ptr = tmp;
    }

    void _updateHeight(AVLNode<T> *ptr) {
        if (ptr == nullptr) return;
        int leftHeight = ptr->leftChild != nullptr ? ptr->leftChild->height : 0;
        int rightHeight = ptr->rightChild != nullptr ? ptr->rightChild->height : 0;
        ptr->height = std::max(leftHeight, rightHeight) + 1;
    }

    AVLNode<T> *root;
};

```
### 线段树
```cpp
template<typename T>
class SegmentTree {
public:
    explicit SegmentTree(int n) : lPos(1), rPos(n), node(4 * n + 10), lazy(4 * n + 10) {}

    /**
     * @brief 建立一棵线段树
     * @param data 输入数据
     * @param shift 调整偏移量使得数据和树匹配，因为树中的结点是从1开始计数
     * */
    void build(std::vector<T> &data, int shift) {
        buildStep(lPos, rPos, data, shift, 1);
    }

    /**
     * @brief 区间更新线段树
     * @param diff 被修改的区间元素的变化量
     * @param lPosQ 被修改的区间的左端点
     * @param rPosQ 被修改的区间的右端点
     * 
     * */
    void update(int diff, int lPosQ, int rPosQ) {
        updateStep(lPosQ, rPosQ, diff, lPos, rPos, 1);
    }

    /**
     * @brief 区间求和
     * @param lPosQ 当前结点包含的区间的左端点
     * @param rPosQ 当前结点包含的区间的右端点
     * @param pos 当前结点的编号
     **/
    T query(int lPosQ, int rPosQ) {
        return queryStep(lPosQ, rPosQ, lPos, rPos, 1);
    }

private:
    /**
     * @brief 建立一棵线段树的步骤
     * @param lPosQ 建树区间的左端点
     * @param rPosQ 建树区间的右端点
     * @param pos 当前根的编号
     * @param data 输入数据
     * @param shift 输入数据和建树的序号匹配
     * */
    void buildStep(int lPosQ, int rPosQ, std::vector<T> &data, int shift, int pos) {
        if (lPosQ == rPosQ) {
            node[pos] = data[lPosQ + shift];
            return;
        }
        int mPosP = lPosQ + ((rPosQ - lPosQ) >> 1);
        buildStep(lPosQ, mPosP, data, shift, pos << 1);
        buildStep(mPosP + 1, rPosQ, data, shift, (pos << 1) | 1);
        node[pos] = node[pos << 1] + node[(pos << 1) | 1];
    }

    /**
     * @brief 区间更新线段树
     * @param lPosQ 被修改的区间的左端点
     * @param rPosQ 被修改的区间的右端点
     * @param diff 被修改的区间元素的变化量
     * @param sPos 当前结点包含的区间的左端点
     * @param ePos 当前结点包含的区间的右端点
     * @param pos 当前结点的编号
     * */
    void updateStep(int lPosQ, int rPosQ, int diff, int sPos, int ePos, int pos) {
        if (lPosQ <= sPos and ePos <= rPosQ) {
            node[pos] += (ePos - sPos + 1) * diff;
            lazy[pos] += diff;
            return;
        }
        int mPos = sPos + ((ePos - sPos) >> 1);
        if (lazy[pos] and sPos != ePos) {
            node[pos << 1] += lazy[pos] * (mPos - sPos + 1);
            node[(pos << 1) | 1] += lazy[pos] * (ePos - mPos);
            lazy[pos << 1] += lazy[pos];
            lazy[(pos << 1) | 1] += lazy[pos];
            lazy[pos] = 0;
        }
        if (lPosQ <= mPos) {
            updateStep(lPosQ, rPosQ, diff, sPos, mPos, pos << 1);
        }
        if (rPosQ > mPos) {
            updateStep(lPosQ, rPosQ, diff, mPos + 1, ePos, (pos << 1) | 1);
        }
        node[pos] = node[pos << 1] + node[(pos << 1) | 1];
    }

    /**
     * @brief 区间求和的步骤
     * @param lPosQ 查询区间左端点
     * @param rPosQ 查询区间右端点
     * @param sPos 当前结点包含的区间的左端点
     * @param ePos 当前结点包含的区间的右端点
     * @param pos 当前结点的编号
     **/
    T queryStep(int lPosQ, int rPosQ, int sPos, int ePos, int pos = 1) {
        if (lPosQ <= sPos and ePos <= rPosQ) return node[pos];
        int mPos = sPos + ((ePos - sPos) >> 1);
        if (lazy[pos]) {
            node[pos << 1] += lazy[pos] * (mPos - sPos + 1);
            node[(pos << 1) | 1] += lazy[pos] * (ePos - mPos);
            lazy[pos << 1] = lazy[pos];
            lazy[(pos << 1) | 1] = lazy[pos];
            lazy[pos] = 0;
        }
        T sum = 0;
        if (lPosQ <= mPos) {
            sum = queryStep(lPosQ, rPosQ, sPos, mPos, pos << 1);
        }
        if (rPosQ > mPos) {
            sum += queryStep(lPosQ, rPosQ, mPos + 1, ePos, (pos << 1) | 1);
        }
        return sum;
    }

    int lPos, rPos;
    std::vector<T> node, lazy;
};

```