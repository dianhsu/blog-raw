#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool inCircle(pair<double, double> &centre, pair<double, double> &point){
		if(pow(centre.first-point.first,2)+pow(centre.second - point.second,2)<=1) {
				return true;
		}else{
				return false;
		}
}
int main(){
		double x, y;
		while(cin >> x >> y) {
				pair<double, double> point = make_pair(x,y);
				pair<double, double> centre1 = make_pair(2,2);
				pair<double, double> centre2 = make_pair(2,-2);
				pair<double, double> centre3 = make_pair(-2,2);
				pair<double, double> centre4 = make_pair(-2,-2);
				if(inCircle(centre1, point) or inCircle(centre2, point) or inCircle(centre3, point) or inCircle(centre4, point)) {
						std::cout << "10" << std::endl;
				}else{
						std::cout << "0" << std::endl;
				}
		}
		return 0;
}
