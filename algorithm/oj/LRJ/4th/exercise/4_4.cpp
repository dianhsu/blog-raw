#include <bits/stdc++.h>

using namespace std;
struct Cube{
    char c_up, c_down, c_left, c_right, c_front, c_back;
    Cube(string s){
        c_up = s[0];
        c_front = s[1];
        c_left = s[2];
        c_right = s[3];
        c_back = s[4];
        c_down = s[5];
    }
    Cube(){
        c_up = c_down = c_left = c_right = c_front = c_back = ' ';
    }
    string toString(){
        string ret = "";
        return ret + c_up + c_front + c_left + c_right + c_back + c_down;
    }
    
};
Cube f_up(Cube c_origin){
    Cube ret;
    ret.c_left  = c_origin.c_left;
    ret.c_right = c_origin.c_right;
    ret.c_front = c_origin.c_down;
    ret.c_back  = c_origin.c_up;
    ret.c_up    = c_origin.c_front;
    ret.c_down  = c_origin.c_back;
    return ret;
}
Cube f_left(Cube c_origin){
    Cube ret;
    ret.c_left  = c_origin.c_front;
    ret.c_right = c_origin.c_back;
    ret.c_front = c_origin.c_right;
    ret.c_back  = c_origin.c_left;
    ret.c_up    = c_origin.c_up;
    ret.c_down  = c_origin.c_down;
    return ret;
}
Cube f_front(Cube c_origin){
    Cube ret;
    ret.c_left  = c_origin.c_up;
    ret.c_right = c_origin.c_down;
    ret.c_front = c_origin.c_front;
    ret.c_back  = c_origin.c_back;
    ret.c_up    = c_origin.c_right;
    ret.c_down  = c_origin.c_left;
    return ret;
}
string f_operate(int c_code, Cube c_cube){
    int c_up = c_code%4;
    c_code/=4;
    int c_left = c_code%4;
    c_code/=4;
    int c_front = c_code%4;
    while(c_up--){
        c_cube = f_up(c_cube);
    }
    while(c_left--){
        c_cube = f_left(c_cube);
    }
    while(c_front--){
        c_cube = f_front(c_cube);
    }
    return c_cube.toString();
}
int main(){
    string s;
    while(cin >> s){
        string c_first = s.substr(0,6);
        string c_second = s.substr(6);
        Cube c1(c_first);
        bool exist = false;
        for(int i = 0; i < 64; ++i){
            if(f_operate(i, c_first) == c_second){
                exist = true;
                cout << "TRUE" << endl;
                break;
            }
        }
        if(!exist) cout << "FALSE" << endl;
    }
    return 0;
}
