#include <iostream>

int main(){
    int n;
    while(std::cin >> n){
        std::cout << (((n%4==0 and n%100) or n%400==0)?"leap year":"not leap year") << std::endl;
    }

    return 0;
}
