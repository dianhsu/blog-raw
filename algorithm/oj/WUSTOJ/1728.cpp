#include <iostream>

int main(){
    int n;
    while(std::cin >> n){
        if(n==1 || n==3 || n==5) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;
    }
}
