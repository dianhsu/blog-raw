#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>

using namespace std;

array<int, 70> arr;

long long n;

int main(){
    int T;
    while(cin >> T){
        int m;
        while(T--){
            arr.fill(0);
            cin >> n >> m;
            for(int i = 0; i < 62; ++i){
                if(n&(1LL << i)){
                    arr[i]--;
                }
            }
            int tmp;
            long long sum = 0;
            while(m--){
                cin >> tmp;
                sum += tmp;
                arr[log2(tmp)]++;
            }
            if(sum < n){
                cout << -1 << endl;
            }else{
                int ans = 0;
                int cnt = 0;
                for(int i = 0; i < 70; ++i){
                    if(arr[i]< 0){
                        if(cnt > 0){
                            cnt--;
                        }else{
                            for(int j = i+1; j <70; ++j){
                                if(arr[j]>0){
                                    arr[j]--;
                                    ans += j-i;
                                    break;
                                }else if(arr[j] < 0){
                                    arr[j] = 0;
                                }
                            }
                        }
                    }else{
                        cnt += arr[i];
                    }
                    cnt /= 2;
                }
                cout << ans << endl;
            }

        }
    }
    return 0;
}
