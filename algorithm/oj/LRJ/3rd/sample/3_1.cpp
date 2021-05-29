#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int in_quote = 0;
    while(getline(cin, str)){
        for(auto item: str){
            if(item == '\"'){
                if(!in_quote) cout << "``";
                else cout << "\'\'";
                in_quote ^= 1;
            }else{
                cout << item;
            }
        }
        cout << endl;
    }
    return 0;
}
