#include <iostream>
#include <string>

int main(){
    int n;
    while(std::cin >> n){
        if(n == 0){
            std::cout << "zero" << std::endl;
        }else{
            std::cout << (n>0?"positive":"negative") << std::endl;
        }
    }

    return 0;
}
