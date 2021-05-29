#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int val[10]={6,2,5,5,4,5,6,3,7,6};
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n&1){
            cout << 7;
            n-=3;
        }
        n/=2;
        while(n--){
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}
