#include <bits/stdc++.h>

using namespace std;
int H[15][15];
int V[15][15];
int n;
void show(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << "*";
            if(H[i][j]) cout << "-";
            else cout << " ";
        }
        cout << endl;
        for(int j = 1; j <= n; ++j){
            if(V[i][j]) cout << "|";
            else cout << " ";
            cout << " ";
        }
        cout << endl;
    }
}
array<int, 10> arr;
bool check_key(char type, int x, int y, int sz){
    if(type == 'H'){
        for(int i = 0; i < sz; ++i)
            if(!H[x][y+i]) {
                return false;
            }
    }else{ 
        for(int i = 0; i < sz; ++i)
            if(!V[x+i][y]) {
                return false;
            }
    }
    return true;
}
bool check(int x, int y, int sz){
    return check_key('H', x, y, sz)
        and check_key('V', x, y, sz)
        and check_key('H', x+sz, y, sz)
        and check_key('V', x, y+sz, sz);
}
void solve(){
    arr.fill(0);
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < n; ++j){
            int max_size = min(n-i, n-j);
            for(int sz = 1; sz <= max_size; ++sz){
                if(check(i, j, sz)){
                    arr[sz]++;
                }
            }
        }
    }
}
void print(int kase){
    cout << "Problem #" << kase << endl << endl;
    bool exist = false;
    for(int i = 1; i < 10; ++i){
        if(arr[i]){
            exist = true;
            cout << arr[i] << " square (s) of size " << i << endl;
        }
    }
    if(!exist) cout << "No completed squares can be found." << endl;
}
int main(){
    int kase = 0;
    while(cin >> n){
        memset(H, 0, sizeof H);
        memset(V, 0, sizeof V);
        int T;
        cin >> T;
        string s;
        int x, y;
        while(T--){
            cin >> s >> x >> y;
            if(s[0] == 'H') H[x][y] = 1;
            else V[y][x] = 1;
        }
        //show();
        solve();
        if(kase) cout << endl << "**********************************" << endl << endl;
        print(++kase);
    }
    return 0;
}
