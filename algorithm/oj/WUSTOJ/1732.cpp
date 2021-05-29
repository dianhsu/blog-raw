#include <iostream>

int main(){
    int score;
    while(std::cin >> score){
        if(score >= 86) std::cout << "VERY GOOD\n";
        else if(score >=60) std::cout << "GOOD\n";
        else std::cout << "BAD\n";
    }
    return 0;
}
