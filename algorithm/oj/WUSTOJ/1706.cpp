#include <iostream>

int main(){
    double dis;
    while(std::cin >> dis){
        double b_t = dis/3.0+50;
        double w_t = dis/1.2;
        if(w_t == b_t) std::cout << "All\n";
        else if(w_t > b_t) std::cout << "Bike\n";
        else std::cout << "Walk\n";
    }
    return 0;
}
