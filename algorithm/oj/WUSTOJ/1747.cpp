#include <iostream>

int main(){
    int n;
    while(std::cin >> n){
        while(n!=1){
            if(n&1){
                std::cout << n << "*3+1=" << n*3+1 << std::endl;
                n = n*3+1;
            }else{
                std::cout << n << "/2=" << n/2 << std::endl;
                n/=2;
            }
        }
        std::cout << "End" << std::endl;
    }
    return 0;
}
