#include <bits/stdc++.h>

using namespace std;
list<char> arr;
int main(){
    string ins;
    while(cin >> ins){
        arr.clear();
        auto ptr = arr.end();
        for(auto item: ins){
            if(item == ']'){
                ptr = arr.end();
            }else if(item == '['){
                ptr = arr.begin();
            }else{
                arr.insert(ptr, item);
            }
        }
        for(auto item: arr){
            cout << item;
        }
        cout << endl;
    }
    return 0;
}
