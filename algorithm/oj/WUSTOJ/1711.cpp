#include <cstdio>
#include <cstring>

int triple(int x){
    return x*x*x;
}
int main(){
    char str[10];
    while(scanf("%s", str)!=EOF){
        printf("%d\n",triple(str[0]-'0')+triple(str[1]-'0')+triple(str[2]-'0'));
    }
    return 0;
}
