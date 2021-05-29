#include <iostream>

int main(){
		double a, b;
		while(std::cin >> a >> b) {
				if((b < 100 && b < a) || (b>=100 && b*0.9 < a)) {
						std::cout << "yes\n";
				}else{
						std::cout << "no\n";
				}
		}
		return 0;
}
