#include <iostream>

int main(){
    int a, b, c;
    while(std::cin >> a >> b >> c){
        if(std::max(a, std::max(b, c)) * 2 < a + b + c){
            std::cout << "can\n";
        }else{
            std::cout << "can\'t\n";
        }
    }
    return 0;
}
