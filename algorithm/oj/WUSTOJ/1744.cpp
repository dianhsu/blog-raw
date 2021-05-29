#include <iostream>

int main(){
    int a, b;
    while(std::cin >> a >> b){
        int ans = 0;
        int tmp = 0;
        for(int i = 0; i < b; ++i){
            tmp = tmp*10+a;
            ans += tmp;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
