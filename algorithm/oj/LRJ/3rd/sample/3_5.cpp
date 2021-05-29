#include <iostream>
#include <algorithm>

using namespace std;

int cal(int num){
    int ans = num;
    while(num){
        ans+=num%10;
        num/=10;
    }
    return ans;
}

int main(){
    int T;
    while(cin >> T){
        while(T--){
            int N;
            cin >> N;
            int ans = 0;
            for(int i = N; i >= N-50 and i >= 1; --i){
                ans = (cal(i)==N?i:ans);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
