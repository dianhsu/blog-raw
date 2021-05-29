#include <bits/stdc++.h>

using namespace std;
int arr[30];
int vis[30];
void go(int& pos, int step, int range){
    while(step){
        if(step > 0){
            ++pos;
        }else{
            --pos;
        }
        if(pos < 0) pos = range-1;
        if(pos >= range) pos = 0;
        if(vis[pos] == 0){
            if(step>0) --step;
            else ++step;
        }
    }
}

int main(){
    int n, k, m;
    while(cin >> n >> k >> m and (n|k|m)){
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n; ++i) arr[i] = i+1;
        int pos_c = -1;
        int pos_r = n;
        int cnt = 0;
        bool first = true;
        while(cnt < n){
            go(pos_c, k, n);
            go(pos_r, -m, n);
            vis[pos_c] = vis[pos_r] = 1;
            if(first) first = false;
            else cout << ",";
            if(pos_c == pos_r) {
                ++cnt;
                cout << setw(3) << arr[pos_c];
            }else {
                cnt+=2;
                cout << setw(3) << arr[pos_c] << setw(3) << arr[pos_r];
            }
        }
        cout << endl;
    }
    return 0;
}
