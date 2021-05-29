#include <cstdio>

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        int sum = 0;
        int tmp;
        for(int i = 0; i < n; ++i){
            scanf("%d", &tmp);
            sum += tmp;
        }
        printf("%.3f\n", sum*1.0/n);
    }
    return 0;
}
