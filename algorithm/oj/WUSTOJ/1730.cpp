#include <iostream>

int main(){
    int n;
    while(std::cin >> n){
        if((n>6 and n<19) or n >= 60){
            std::cout << "Yes" << std::endl;
        }else{
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
