#include <iostream>

int main(){
    int n;
    while(std::cin >> n){
        int tmp = 1;
        int ans = 0;
        while(tmp*tmp <= n){
            if(n%tmp==0){
                if(tmp*tmp == n){
                    ans+=tmp;
                }else{
                    ans += tmp + n/tmp;
                }
            }
            ++tmp;
        }
        if(ans == n*2){
            std::cout << "yes" << std::endl;
        }else{
            std::cout << "no" << std::endl;
        }
    }
    return 0;
}
