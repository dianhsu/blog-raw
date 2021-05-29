#include <bits/stdc++.h>

using namespace std;
char mp[15][15];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int hx[8] = {-2,-2,-1,-1,1,1,2,2};
int hy[8] = {-1,1,-2,2,-2,2,-1,1};
bool valid(int x, int y){
    return x >= 1 and x <= 3 and y >= 4 and y <= 6;
}
bool inKeyBorad(int x, int y){
    return x > 0 and y > 0 and x <= 10 and y <= 9;
}
bool check(int x, int y){
    for(int i = 0; i < 4; ++i){
        int tx = x + dx[i];
        int ty = y + dy[i];
        int cnt = 0;
        while(inKeyBorad(tx,ty)){
            if(!isblank(mp[tx][ty])){
                ++cnt;
                if(cnt == 1 and (mp[tx][ty] == 'R' or mp[tx][ty] == 'G')){
                    return true;
                }else if(cnt == 2 and mp[tx][ty] == 'C'){
                    return true;
                }
            }
            tx += dx[i];
            ty += dy[i];
        }
    }
    for(int i = 0; i < 8; ++i){
        int tx = x + hx[i];
        int ty = y + hy[i];
        if(inKeyBorad(tx,ty) and mp[tx][ty] == 'H' and isblank(mp[x + hx[i]/abs(hx[i])][y + hy[i]/abs(hy[i])])){
            return true;
        }
    }
    return false;
}
bool flying_general(int x, int y){
    int tx = x + 1;
    while(inKeyBorad(tx, y)){
        if(isblank(mp[tx][y])){
            tx++;
        }else if(mp[tx][y]=='G'){
            return true;
        }else break;
    }
    return false;
}
int main(){
    int n, x, y;
    while(cin >> n >> x >> y and n){
        memset(mp, ' ', sizeof mp);
        string key;
        int k_x, k_y;
        for(int i = 0; i < n; ++i){
            cin >> key >> k_x >> k_y;
            mp[k_x][k_y] = key[0];
        }
        bool checkmate = true;
        if(flying_general(x, y)){
            checkmate = false;
        }else{
            for(int i = 0; i < 4; ++i){
                if(valid(x+dx[i], y+dy[i]) and !check(x+dx[i],y+dy[i])){
                    checkmate = false;
                    break;
                }
            }
        }
        if(checkmate) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
