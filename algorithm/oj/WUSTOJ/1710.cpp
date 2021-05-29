#include <cstdio>

int main(){
    double price;
    while(scanf("%lf", &price)!=EOF){
        double ans;
        if(price < 1000) {
            ans = 0;
        }else if(price < 5000){
            ans = price * 0.02;
        }else if(price < 10000){
            ans = price * 0.03;
        }else{
            ans = price * 0.05;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
