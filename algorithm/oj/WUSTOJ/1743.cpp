#include <iostream>
#include <string>
#include <algorithm>

int main(){
    int val;
    while(std::cin >> val){
        std::string tmp = std::to_string(val);
        std::reverse(tmp.begin(),tmp.end());
        if(tmp == std::to_string(val)){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
