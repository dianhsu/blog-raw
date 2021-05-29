#include <iostream>
#include <cstdio>

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        double top = 1;
        double buttom = 1;
        double ans = 0;
        int i = 0;
        while(i < n && i < 10){
            ans += top/buttom;
            top += buttom;
            buttom += top;
            ++i;
        }
        if(n > 10){
            ans += (n-10)*top/buttom;
        }
        printf("%.5f\n", ans);
    }
    return 0;
}
