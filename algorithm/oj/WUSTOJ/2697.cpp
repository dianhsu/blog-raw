#include <iostream>
#include <iomanip>
#include <cmath>
int val[1000020];
double Ex1[1000020];
double Ex2[1000020];
/*
  DX = E(x^2) - E(x)^2
*/
int main(){
  int kase,query;
  while(scanf("%d", &kase)!=EOF){
    Ex1[0] = Ex2[0] = 0;
    for(int i = 1; i <= kase; ++i){
      scanf("%d", &val[i]);
      Ex1[i] = Ex1[i-1]+val[i];
      Ex2[i] = Ex2[i-1]+val[i]*val[i];
    }
    scanf("%d", &query);
    int l, r;
    while(query--){
      scanf("%d%d", &l, &r);
      double ans = (Ex2[r]-Ex2[l-1])/(r-l+1)-pow((Ex1[r]-Ex1[l-1])/(r-l+1),2);
      printf("%.2f\n", ans);
    }
  }
  return 0;
}
