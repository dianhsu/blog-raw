#include <iostream>

int main(){
    char str[8];
    while(std::cin >> str){
        bool v1 = (str[0]-'0'+str[1]-'0'+str[2]-'0'+str[3]-'0')%4==0;
        bool v2 = (str[0]-'0'+str[1]-'0'+str[2]-'0')%3==0;
        std::cout << (v1&&v2?"congratulation":"sorry") << std::endl;
    }
    return 0;
}
