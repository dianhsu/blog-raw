#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
queue<int> q_in, q_out;
stack<int> st_tmp;
int main(){
	int n;
	while(cin >> n){
		while(!q_in.empty()) q_in.pop();
		while(!q_out.empty()) q_out.pop();
		while(!st_tmp.empty()) st_tmp.pop();
		string s_ans;
		bool exist = true;
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			q_in.push(x);
		}
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			q_out.push(x);
		}
		while(!q_in.empty() or !q_out.empty()){
			if(!st_tmp.empty() and !q_out.empty() and st_tmp.top() == q_out.front()){
				st_tmp.pop();
				q_out.pop();
				s_ans += 'O';
			}else if(!q_in.empty()){
				st_tmp.push(q_in.front());
				q_in.pop();
				s_ans += 'I';
			}else{
				exist = false;
				break;
			}
		}
		if(exist) cout << s_ans << endl;
		else cout << "No" << endl;

	}
	return 0;
}
