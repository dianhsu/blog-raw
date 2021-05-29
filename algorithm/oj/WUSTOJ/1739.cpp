#include <iostream>
#include <algorithm>
int main(){
    long long a, b;
    while(std::cin >> a >> b){
        long long tmp = std::__gcd(a,b);
        std::cout << tmp << " " << a/tmp*b << std::endl;
    }
    return 0;
}
