#include <iostream>

using namespace std;
double val[][3]={
  {0.8, 1.0, 1.2},
  {1.0, 1.2, 1.4},
  {1.2, 1.4, 1.6}
};
int main() {
  int a, b;
  while (scanf("%d%d", &a, &b)!=EOF) {
    a--;
    b = b/1000+((b%1000)?1:0);
    if(b<=5){
      printf("20.00\n");
    }else if(b<=10){
      printf("%.2f\n",(b-5)*val[a][0]+20);

    }else if(b<=13){
      printf("%.2f\n",(b-10)*val[a][1]+5*val[a][0]+20);
    }else{
      printf("%.2f\n",(b-13)*val[a][2]+3*val[a][1]+5*val[a][0]+20);
    }
  }
  return 0;
}
