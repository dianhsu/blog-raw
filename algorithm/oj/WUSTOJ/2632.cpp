#include <iostream>
#include <algorithm>

using namespace std;
long long cal(long long base, long long exp){
  if(exp == 0) return 1;
  long long tmp = 1;
  if(exp&1){
    tmp *= base;
  }
  tmp *= cal(base, exp>>1)*cal(base, exp>>1);
  return tmp;
}
int main(){
  int n;
  while (cin >> n) {
    if(n < 1) cout << 0 << endl;
    else{
      int ans = 0;
      long long tmp = 1;
      for(int i = 0; i < 32; ++i) {
        long long x_1 = cal(5,i);
        if(x_1 > n) break;
        for(int j = 0; j < 32; ++j){
          long long x_2 = x_1 * cal(3,j);
          if(x_2 > n) break;
          for(int k = 0; k < 32; ++k){
            if(x_2*cal(2,k) <= n){
              ++ans;
            }else{
              break;
            }
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
