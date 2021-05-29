#include <iostream>

int main(){
    int m, n;
    while(std::cin >> m >> n){
        int ans = 0;
        for(int i = m; i <= n; ++i) if(i%17==0) ans+=i;
        std::cout << ans << std::endl;
    }
    return 0;
}
