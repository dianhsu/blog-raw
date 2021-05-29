#include <iostream>
bool is_primer(int val){
    return (val%4==0 and val%100) or val%400==0;
}
int main(){
    int y, m;
    while(std::cin >> y >> m){
        if(y<=0 or m <= 0 or m > 12){
            std::cout << "ERROR\n";
            continue;
        }
        int ans = 0;
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
            ans = 31;
        }else if(m == 2 and is_primer(y)){
            ans = 29;
        }else if(m == 2 and !is_primer(y)){
            ans = 28;
        }else{
            ans = 30;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
