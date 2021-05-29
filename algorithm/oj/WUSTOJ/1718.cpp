#include <iostream>

int main(){
    int n;
    while(std::cin >> n){
        std::cout << (n%3?"no":"yes") << std::endl;
    }

    return 0;
}
