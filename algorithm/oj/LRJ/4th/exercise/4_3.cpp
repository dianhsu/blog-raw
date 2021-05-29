#include <bits/stdc++.h>

using namespace std;
char mp[15][15];
string cur;
vector<pair<int, int>> vec;
void show_mp(){
    for(int i = 1; i < 9; ++i){
        cout << (mp[i]+1) << endl;
    }
}
bool inside(int x, int y){
    return x > 0 and y > 0 and x < 9 and y < 9;
}
bool check(int x, int y){
    for(int i = 0; i < 9; ++i){
        int dx = i/3-1;
        int dy = i%3-1;
        if(dx or dy){
            int cnt = 0;
            int tx = x + dx;
            int ty = y + dy;
            while(inside(tx ,ty)){
                if(isalpha(mp[tx][ty])){
                    if(mp[tx][ty] != cur[0]){
                        ++cnt;
                    }else if(cnt){
                        return true;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
                tx += dx;
                ty += dy;
            }
        }
    }
    return false;
}
void get_valid(){
    vec.clear();
    for(int i = 1; i < 9; ++i){
        for(int j = 1; j < 9; ++j){
            if(!isalpha(mp[i][j]) and check(i, j)){
                vec.emplace_back(i,j);
            }
        }
    }
}
void show_valid(){
    bool first = true;
    if(vec.empty()){
        cout << "No legal move." << endl;
        return;
    }
    for(auto item: vec){
        if(first) first = false;
        else cout << " ";
        cout << "(" << item.first << "," << item.second << ")";
    }
    cout << endl;
}
void reverse_val(int x, int y){
    for(int i = 0; i < 9; ++i){
        int dx = i/3-1;
        int dy = i%3-1;
        if(dx or dy){
            int cnt = 0;
            int step = 1;
            int tx = step * dx + x;
            int ty = step * dy + y;
            while(inside(tx, ty)){
                if(isalpha(mp[tx][ty])){
                    if(mp[tx][ty] != cur[0]){
                        ++cnt;
                    }else if(cnt){
                        for(int i = 1; i < step; ++i){
                            mp[x + dx * i][y + dy * i] = cur[0];
                        }
                        break;
                    }else{
                        break;
                    }
                }else{
                    break;
                }

                ++step;
                tx = step * dx + x;
                ty = step * dy + y;
            }
        }
    }
}
void perform(int x, int y){
    get_valid();
    if(vec.empty()){
        if(cur[0] == 'W') cur[0] = 'B';
        else cur[0] = 'W';
        get_valid();
    }
    reverse_val(x, y);
    mp[x][y] = cur[0];
    if(cur[0] == 'W') cur[0] = 'B';
    else cur[0] = 'W';
}
pair<int, int> count_mp(){
    pair<int, int> ret;
    ret.first = 0;
    ret.second = 0;
    for(int i = 1; i < 9; ++i){
        for(int j = 1; j < 9; ++j){
            if(mp[i][j] == 'B') ret.first++;
            if(mp[i][j] == 'W') ret.second++;
        }
    }
    return ret;
}
int main(){
    int T;
    cin >> T;
    bool first = true;
    while(T--){
        for(int i = 1; i < 9; ++i){
            cin >> (&mp[i][1]);
        }
        cin >> cur;
        string cmd;
        if(first) first = false;
        else cout << endl;
        while(cin >> cmd and cmd != "Q"){
            if(cmd[0] == 'L'){
                get_valid();
                show_valid();
            }else if(cmd[0] == 'M'){
                perform(cmd[1] - '0', cmd[2] - '0');
                pair<int, int> ct = count_mp();
                cout <<  "Black - " << setw(2) << ct.first << " White - " << setw(2) << ct.second << endl;
            }
        }
        show_mp();
    }
    return 0;
}
