/**
 * @ref http://poj.org/problem?id=1321
 * @brief 棋盘问题
 * @date 2021/05/30
 * @author dianhsu
 * */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
char str[10][10];
int n, m;
int ans;
int vis[10];
void dfs(int dep, int cnt){
    if(cnt >= m){
        ++ans;
        return;
    }
    if(dep >= n){
        return;        
    }
    for(int i = 0; i < n; ++i){
        if(str[dep][i] == '#' and vis[i] == 0){
            vis[i] = 1;
            dfs(dep + 1, cnt + 1);
            vis[i] = 0;
        }
    }
    dfs(dep + 1, cnt);
}

int solve(){
    ans = 0;
    memset(vis, 0, sizeof vis);
    dfs(0, 0);
    
    return ans;
}
int main() {

    while (scanf("%d%d", &n, &m) != EOF) {
        if(n == -1){
            break;
        }
        for(int i = 0; i < n; ++i){
            scanf("%s", str[i]);
        }
        printf("%d\n", solve());
    }

    return 0;
}