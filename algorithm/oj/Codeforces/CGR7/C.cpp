#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
int main(){
    int n, k;
    cin >> n >> k;
    int tmp;
    long long ans1 = (long long)(n + n - k + 1) * k / 2;
    long long ans2 = 1;
    int save = -1;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        if(tmp > n - k){
            if(save >= 0){
                ans2 = (ans2 * (i - save)) % mod;
            }
            save = i;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
