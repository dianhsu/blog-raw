#include <bits/stdc++.h>

using namespace std;
map<char, char> mp;
void init(){
    mp.clear();
    string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    for(int i = 1; i < keyboard.length(); ++i){
        mp[keyboard[i]] = keyboard[i-1];
    }
}
int main(){
    init();
    string s;
    while(getline(cin, s)){
        for(auto item: s){
            if(mp.count(item))
                cout << mp[item];
            else cout << item;
        }
        cout << endl;
    }
    return 0;
}
