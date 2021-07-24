---
toc:
    depth_from: 1
    depth_to: 4
title: SPFA - 算法 - dianhsu.top
---
@import "/mystyle.less"

## SPFA {ignore=True}

> 返回:house:[首页](../../index.html)，:rocket:[算法](../index.html)

---
[TOC]

### 简要介绍
暂略

### SPFA 模板
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

### 参考例题

@import "../oj/POJ_2387.md"

@import "../oj/POJ_3259.md"

@import "../oj/POJ_3169.md"

@import "../oj/HDU_3146.md"