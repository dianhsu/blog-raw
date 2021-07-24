---
toc:
    depth_from: 1
    depth_to: 4
title: 网络流 - 算法 - dianhsu.top
---
@import "/mystyle.less"

## 网络流 {ignore=True}


### Dinic 模板
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

### 参考例题

@import "../oj/HDU_3549.md"

@import "../oj/HDU_3146.md"