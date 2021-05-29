#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <climits>

using namespace std;

array<int, 100100> arr;
void show_arr(unsigned k){
    for(int i = 1; i <= k; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    unsigned T;
    cin >> T;
    while(T--){
        int n, x;
        string s;
        cin >> n >> x >> s;
        arr[0] = 0;
        int maxv = INT_MIN;
        int minv = INT_MAX;
        for(int i = 0; i < n; ++i){
            arr[i+1] = arr[i]+(s[i]=='1'?-1:1);
            maxv = max(maxv, arr[i+1]);
            minv = min(minv, arr[i+1]);
        }
        if(arr[n] == 0){
            if(x >= minv and x <= maxv)
                cout << -1 << endl;
            else{
                cout << 0 << endl;
            }
        }else{
            int path = arr[n];
            unsigned ans = 0;
            if(x==0) ++ans;
            for(int i = 1; i <= n; ++i){
                int tmp = x - arr[i];
                if(tmp >= 0 and path > 0 or tmp <= 0 and path < 0){
                    if(abs(tmp)%abs(path) == 0) ++ans;
                }
            }
            cout << ans << endl;
        }

    }
    return 0;
}

