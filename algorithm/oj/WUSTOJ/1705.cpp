#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    double x, y, m, n, w;
    while(std::cin >> x >> y >> m >> n >> w){
        if(x>=m and x <= m+w and y >= n-w and y <= n){
            std::cout << "yes" << std::endl;
        }else{
            std::cout << "no" << std::endl;
        }
    }
    return 0;
}
