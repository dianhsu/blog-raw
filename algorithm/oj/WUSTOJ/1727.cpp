#include <cstdio>

int main(){
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        printf("%.3f\n", (a+b+c)*1.0/3);
    }
    return 0;
}
