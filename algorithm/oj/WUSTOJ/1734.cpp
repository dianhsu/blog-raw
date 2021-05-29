#include <iostream>
#include <algorithm>
#include <climits>
int main(){
    int n;
    while(std::cin >> n){
        int tmp;
        int maxn = INT_MIN;
        int minn = INT_MAX;
        while(n--){
            std::cin >> tmp;
            maxn = std::max(maxn, tmp);
            minn = std::min(minn, tmp);
        }
        std::cout << maxn - minn << std::endl;
    }
    return 0;
}
