#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

int val[10];

using namespace std;

int main(){
	string s;
	while(cin >> s){
		memset(val, 0, sizeof(val));
		for(int i = 0; i < s.length(); ++i){
			val[s[i]-'0']++;
		}
		for(int i = 0; i < 10; ++i){
			if(val[i] > 0){
				cout << i << ':' << val[i] << endl;
			}
		}
	}
	return 0;
}
