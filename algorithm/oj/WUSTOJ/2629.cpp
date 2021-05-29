#include <iostream>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    if(n<=0) cout << "False" << endl;
    else{
      while(n%2==0) n/=2;
      while(n%3==0) n/=3;
      while(n%5==0) n/=5;
      if(n == 1){
        cout << "True" << endl;
      }else{
        cout << "False" << endl;
      }
    }
  }
  return 0;
}
