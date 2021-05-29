#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

int main(){
    double x, y, z;
    while(scanf("%lf%lf%lf",&x,&y,&z)!=EOF){
        if(x > 0 and y > 0 and z > 0){
            if(std::max(x, std::max(y, z))*2 < x+y+z){
                double p = (x+y+z)/2;
                printf("area=%.2f\n", sqrt(p*(p-x)*(p-y)*(p-z)));
            }else{
                std::cout << "ERROR" << std::endl;
            }
        }else{
            std::cout << "ERROR" << std::endl;
        }
    }
    return 0;
}
