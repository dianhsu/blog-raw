#include <cstdio>

int main(){
    double dis;
    while(scanf("%lf", &dis)!=EOF){
        double ans = 0;
        if(dis <=3){
            ans = 8;
        }else if(dis <= 15){
            ans += 8+(dis-3)*1.4;
        }else{
            ans += 8+12*1.4+(dis-15)*2.1;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
