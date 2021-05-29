#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> st;
int val[100100];
pair<bool, bool> valid[100100];
int main(){
	int n;
	while(cin >> n){
		st.clear();
		for(int i = 0; i < n; ++i){
			cin >> val[i];
			valid[i].first = false;
			valid[i].second = false;
			if(st.size() == 0 || *(st.rbegin()) < val[i]){
				valid[i].first = true;
			}
			st.insert(val[i]);
		}
		st.clear();
		int cnt = 0;
		for(int i = n - 1; i >= 0; --i){
			if(st.size() == 0 || *(st.begin()) > val[i]){
				valid[i].second = true;
				if(valid[i].first) ++cnt;
			}
			st.insert(val[i]);
		}
		bool space = false;
		cout << cnt << endl;
		for(int i = 0; i < n; ++i){
			if(valid[i].first and valid[i].second){
				if(space){
					cout << " ";
				}else{
					space = true;
				}
				cout << val[i];
			}
		}
		cout << endl;
	}
	return 0;
}
