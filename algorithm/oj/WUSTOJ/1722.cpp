#include <iostream>

int main(){
    int a, b, c;
    while(std::cin >> a >> b >> c){
        std::cout << ((b*b-4*a*c>=0)?"yes":"no") << std::endl;
    }
    return 0;
}
