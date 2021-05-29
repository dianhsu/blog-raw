#include <bits/stdc++.h>

using namespace std;

array<int, 10> arr;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        arr.fill(0);
        for(int i = 1; i <= n; ++i){
            int tmp = i;
            while(tmp){
                arr[tmp%10]++;
                tmp/=10;
            }
        }
        bool first = true;
        for(auto item: arr){
            if(!first) cout << " ";
            else first = false;
            cout << item;
        }
        cout << endl;
    }
    return 0;
}
