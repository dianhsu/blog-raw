#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::string s;
    while(getline(std::cin, s)){
        std::stringstream ss(s);
        int val = 0;
        int tmp;
        int times = 0;
        while(ss >> tmp){
            if(tmp&1){
                val += tmp;
                ++times;
            }
        }
        std::cout << val << " " << times << std::endl;
    }
    return 0;
}
