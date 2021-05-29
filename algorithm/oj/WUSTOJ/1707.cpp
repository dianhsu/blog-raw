#include <iostream>
#include <string>

int main(){
    int wei;
    std::string s;
    while(std::cin >> wei >> s){
        int base = 8;
        if(s[0] == 'y') base += 5;
        if(wei%500){
            wei += 500 - wei%500;
        }
        if(wei>1000){
            base += (wei-1000)/125;
        }
        std::cout << base << std::endl;
    }
    return 0;
}
