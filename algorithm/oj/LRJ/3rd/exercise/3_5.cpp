#include <bits/stdc++.h>

using namespace std;
array<string, 5> matrix;
int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

bool func(int &x, int &y, int fx){
    int nx = dir[fx][0] + x;
    int ny = dir[fx][1] + y;
    if(nx < 0 or nx > 4 or ny < 0 or ny > 4) return false;
    swap(matrix[nx][ny], matrix[x][y]);
    x = nx;
    y = ny;
    return true;
}

int main(){
    int num = 1;
    while(getline(cin, matrix[0]) and matrix[0]!="Z"){
        for(int i = 1; i < 5; ++i) getline(cin, matrix[i]);
        
        string op;
        int x,y;
        for(int i = 0; i < 25; ++i){
            if(!isalpha(matrix[i/5][i%5])){
                x=i/5;
                y=i%5;
                break;
            }
        }
        bool valid = true;
        while(getline(cin, op)){
            for(auto item:op){
                if(item == 'A') if(!func(x,y,0)) valid = false;
                if(item == 'B') if(!func(x,y,1)) valid = false;
                if(item == 'L') if(!func(x,y,2)) valid = false;
                if(item == 'R') if(!func(x,y,3)) valid = false;
                if(valid == false) break;
            }
            if(*(op.rbegin()) == '0') break;
        }
        if(num!=1) cout << endl;
        cout << "Puzzle #" << (num++) << ":\n";
        if(valid){
            for(int i = 0; i < 25; ++i){
                if(i%5) cout << " ";
                cout << (isalpha(matrix[i/5][i%5])?matrix[i/5][i%5]:' ');
                if((i+1)%5==0) cout << endl;
            }
        }else{
            cout << "This puzzle has no final configuration." << endl;
        }
    }    
    return 0;
}
