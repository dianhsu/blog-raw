#include <cstdio>
#include <cmath>

int main(){
  double a, b, c;
  while(scanf("%lf%lf%lf", &a, &b, &c)!=EOF){
      if(!a && !b && !c) break;
      double tmp = b*b - 4*a*c;
      if(tmp<0){
        printf("-1\n");
      }else if(tmp == 0){
        printf("%.6f\n", -b/(2.0*a));
      }else{
        printf("%.6f %.6f\n", (-b+sqrt(tmp))/(2.0*a), (-b-sqrt(tmp))/(2.0*a));
      }
  }
  return 0;
}
