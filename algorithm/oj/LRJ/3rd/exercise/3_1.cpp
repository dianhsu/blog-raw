#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        int flag = 1;
        int ans = 0;
        for(auto item:s){
            if(item == 'X'){
                flag = 1;
            }else{
                ans += flag++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
