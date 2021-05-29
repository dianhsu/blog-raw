#include <iostream>
#include <algorithm>

using namespace std;
bool check(int a){
		return a>= 0 and a<=100;
}
int main(){
		int a,b,c,d,e;
		while (cin >> a >> b >> c >> d >> e) {
				int sum = a+b+c+d+e;
				if(!check(a) or !check(b) or !check(c) or !check(d) or !check(e)) {
                    std::cout << "成绩错误" << '\n';
				}
				else if(a < 60 || b < 60 || c < 60 || d < 60 or e < 60) {
						std::cout << "无奖学金" << '\n';
				}else if (sum>=90*5) {
						std::cout << "甲等奖学金" << '\n';
				}else if(sum>=80*5) {
						std::cout << "乙等奖学金" << '\n';
				}else if(sum>=70*5) {
						std::cout << "丙等奖学金" << '\n';
				}else{
						std::cout << "无奖学金" << '\n';
				}
		}
		return 0;
}
