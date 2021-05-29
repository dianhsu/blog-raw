#include <iostream>

int main(){
    int v;
    while(std::cin >> v){
        std::cout << (v&1?"odd":"even") << std::endl;
    }
    return 0;
}
