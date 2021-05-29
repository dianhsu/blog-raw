#include <iostream>
#include <string>

int main(){
    int n;
    while(std::cin >> n){
        std::cout << ((n<10 or n>=100)?"no":"yes") << std::endl;
    }

    return 0;
}
