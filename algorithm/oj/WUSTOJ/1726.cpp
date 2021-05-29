#include <iostream>
#include <algorithm>
int main(){
    int a;
    while(std::cin >> a){
        std::cout << (a>=0 and a<=100?"yes":"no") << std::endl;
    }
    return 0;
}
