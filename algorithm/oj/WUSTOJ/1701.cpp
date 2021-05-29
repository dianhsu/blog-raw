#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    double a, b, c;
    while (scanf("%lf%lf%lf", &a, &b, &c)!=EOF) {
        double tmp = b*b - 4*a*c;
        if(tmp == 0){
            printf("x1=x2=%.2f\n", -b/2/a);
        }else if(tmp > 0){
            double x1 = (-b-sqrt(tmp))/(a*2);
            double x2 = (-b+sqrt(tmp))/(a*2);
            printf("x1=%.2f,x2=%.2f\n", min(x1, x2), max(x1, x2));
        }else{
            printf("real=%.2f,imag=%.2f\n", -b/(a*2), sqrt(-tmp)/(a*2));
        }
    }
    return 0;
}
