#include <iostream>
#include <algorithm>
int main(){
    int a, b, c;
    while(std::cin >> a >> b >> c){
        std::cout << std::min(a, std::min(b, c)) << std::endl; 
    }
    return 0;
}
