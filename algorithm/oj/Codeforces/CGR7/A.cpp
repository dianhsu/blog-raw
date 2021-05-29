#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n==1) cout << -1 << endl;
        else{
            if((n-1)%3){
                for(int i = 1; i < n; ++i){
                    cout << 2;
                }
                cout << 3 << endl;
            }else{
                for(int i = 2; i < n; ++i){
                    cout << 2;
                }
                cout << 33 << endl;
            }
        }
    }

    return 0;
}
