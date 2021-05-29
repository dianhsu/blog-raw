#include <iostream>
#include <algorithm>

int main(){
    int n;
    while(std::cin >> n){
        int a = 0, b = 0, c = 0;
        int tmp;
        while(n--){
            std::cin >> tmp;
            if(tmp == 1) a++;
            if(tmp == 5) b++;
            if(tmp == 10) c++;
        }
        std::cout << a << " " << b << " " << c << std::endl;
    }
    return 0;
}
