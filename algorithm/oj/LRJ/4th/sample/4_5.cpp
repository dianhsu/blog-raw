#include <bits/stdc++.h>

using namespace std;
int table[60][60];
int r,c;

void handle_DR(){
    int A;
    cin >> A;
    vector<int> vec;
    while(A--){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for(auto row: vec){
        for(int i = row+1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                table[i-1][j] = table[i][j];
            }
        }
        for(int j = 1; j <= c; ++j)
            table[r][j] = 0;
        --r;
    }
}
void handle_DC(){
    int A;
    cin >> A;
    vector<int> vec;
    while(A--){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for(auto col: vec){
        for(int i = 1; i <= r; ++i){
            for(int j = col+1; j <= c; ++j){
                table[i][j-1] = table[i][j];
            }
        }
        for(int i = 1; i <= r; ++i)
            table[i][c] = 0;
        --c;
    }
}

void handle_IR(){
    int A;
    cin >> A;
    vector<int> vec;
    while(A--){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for(auto row: vec){
        for(int i = r; i >= row; --i){
            for(int j = c; j >= 1; --j){
                table[i+1][j] = table[i][j];
            }
        }
        for(int j = c; j >= 1; --j)
            table[row][j] = 0;
        ++r;
    }
}
void handle_IC(){
    int A;
    cin >> A;
    vector<int> vec;
    while(A--){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for(auto col: vec){
        for(int i = r; i >= 1; --i){
            for(int j = c; j >= col; --j){
                table[i][j+1] = table[i][j];
            }
        }
        for(int i = r; i >= 1; --i){
            table[i][col] = 0;
        }
        ++c;
    }

}

void show(){
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            cout << setw(5) << table[i][j];
        }
        cout << endl;
    }
}
int get_pos(int x, int y){
    for(int i = 1; i <= r; ++i)
        for(int j = 1; j <= c; ++j){
            if(table[i][j] == x*100+y)
                return i*100+j;
        }
    return 0;
}
int main(){
    int kase = 0;
    while(cin >> r >> c and (r&c)){
        memset(table, 0, sizeof table);
        for(int i = 1; i <= r; ++i)
            for(int j = 1; j <= c; ++j)
                table[i][j] = i*100+j;
        int op1;
        cin >> op1;
        while(op1--){
            string command;
            cin >> command;
            if(command == "EX"){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                swap(table[x1][y1], table[x2][y2]);
            }else if(command == "DR"){
                handle_DR();
            }else if(command == "DC"){
                handle_DC();
            }else if(command == "IC"){
                handle_IC();
            }else if(command == "IR"){
                handle_IR();
            }
            //show();
        }
        int op2;
        cin >> op2;
        int x, y;
        cout << "Spreadsheet #" << ++kase << endl;
        while(op2--){
            cin >> x >> y;
            int val = get_pos(x,y);
            if(val){
                cout << "Cell data in (" 
                    << x << "," << y 
                    << ") moved to ("
                    << val/100 << "," << val%100 
                    << ")" << endl;
            }else{
                cout << "Cell data in ("
                    << x << "," << y 
                    << ") GONE" << endl;
            }
        }
    }
    return 0;
}
