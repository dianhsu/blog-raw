#include <iostream>
#include <cstring>
#include <algorithm>

int cmp(char a, char b){
    return a>b;
}
int main(){
    char str[10];
    while(std::cin >> str){
        std::sort(str,str+sizeof(str),cmp);
        std::cout << str << std::endl;
    }
    return 0;
}
