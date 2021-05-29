#include <iostream>
#include <algorithm>

using namespace std;
char str[1500];

int main(){
  int n;
  while(cin >> n){
    int sum = (n - 1) * 4;
    int pos = 0;
    int key = 1;
    while(pos < sum){
      if(key >= 100){
        str[pos++] = key/100 + '0';
        str[pos++] = key/10%10 + '0';
        str[pos++] = key%10 +'0';
      }else if(key >= 10){
        str[pos++] = key/10 + '0';
        str[pos++] = key%10 + '0';
      }else{
        str[pos++] = key + '0';
      }
      ++key;
    }
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n+i; ++j){
        if(i == n-1){
          cout << str[n+j-1];
        }else if(j == n-1-i){
          cout << str[i];
        }else if(j == n-1+i){
          cout << str[sum-i];
        }else{
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
  return 0;
}
