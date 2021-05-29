#include <iostream>
#include <algorithm>
#include <cmath>
struct Point {
		int x, y;
		bool operator < (const Point & point)const {
				if(x == point.x) {
						return y < point.y;
				}
				return x < point.x;
		}
};
int main(){
		Point lp[3];
		while(std::cin >> lp[0].x >> lp[0].y >> lp[1].x >> lp[1].y >> lp[2].x >> lp[2].y) {
				std::sort(lp,lp+3);
				int dx1 = lp[1].x - lp[0].x;
				int dy1 = lp[1].y - lp[0].y;
				int dx2 = lp[2].x - lp[0].x;
				int dy2 = lp[2].y - lp[0].y;
				if(dx1*dy2 == dx2*dy1)
						std::cout << "yes\n";
				else
						std::cout << "no\n";
		}
		return 0;
}
