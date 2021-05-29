#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::string in;
    while(getline(std::cin, in)){
        std::stringstream ss(in);
        int a = 0, b = 0;
        int tmp;
        while(ss >> tmp){
            if(tmp > 0){
                a++;
            }else if(tmp < 0){
                b++;
            }
        }
        std::cout << a << " " << b << std::endl;
    }
    return 0;
}
