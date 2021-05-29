#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < n; ++i){
			int length = max(i, n - 1 - i);
			for(int j = 0; j <= length; ++j){
				if(j == i or j == n - 1 - i){
					cout << '*';
				}else if(i == 0 or i == n - 1){
					cout << '*';
				}else{
					cout << ' ';
				}
			}
			cout << endl;
		}
	}
	return 0;
}
