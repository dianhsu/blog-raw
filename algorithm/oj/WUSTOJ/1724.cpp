#include <iostream>
#include <algorithm>
int main(){
    int a, b;
    while(std::cin >> a >> b){
        std::cout << std::max(a, b) << std::endl; 
    }
    return 0;
}
