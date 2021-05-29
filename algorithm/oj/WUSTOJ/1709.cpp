#include <cstdio>

int main(){
    int a, b;
    char op[5];
    while(scanf("%d%d%s", &a, &b, op)!=EOF){
        if(op[0]=='+'){
            printf("%d\n", a+b);
        }
        else if(op[0]=='-'){
            printf("%d\n", a-b);
        }
        else if(op[0]=='*'){
            printf("%d\n", a*b);
        }
        else if(op[0]=='/'){
            printf("%.3f\n", a*1.0/b);
        }else{
            puts("WRONG!");
        }
    }
    return 0;
}
