#include <iostream>

int main(){
    int a, b, c;
    while(std::cin >> a >> b >> c){
        if(a>=90 and b >= 90 and c>=90)
            std::cout << "very good" << std::endl;
        else if(a<60 or b <60 or c<60){
            std::cout << "bad" << std::endl;
        }else{
            std::cout << "good" << std::endl;
        }

    }
    return 0;
}
