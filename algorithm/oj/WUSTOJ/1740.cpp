#include <iostream>

int main(){
    int n;
    while(std::cin >> n){
        bool primer = true;
        int i = 2;
        while(i*i <= n){
            if(n%i==0) {
                primer = false;
                break;
            }
            ++i;
        }
        if(primer) std::cout << "yes" << std::endl;
        else std::cout << "no" << std::endl;
    }
    return 0;
}
