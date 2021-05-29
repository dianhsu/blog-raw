#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int n;
  while (cin >> n) {
    int t = 3;
    double ans = 0;
    double tmp;
    while(t--){
      cin >> tmp;
      ans+=tmp;
    }
    char ans1[20];
    sprintf(ans1, "%.2f", ans/n);
    cout << ans1 << endl;
  }
  return 0;
}
