#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int pos[30][2];
int vis[30];
bool check(int a, int b){
		bool left = false, right = false;
		int la = a;
		while(pos[la][0]!=-1 and pos[la][0]!=b) {
				la = pos[la][0];
		}
		if(pos[la][0]==b) left = true;
		int ra = a;
        while(pos[ra][1]!=-1 and pos[ra][1]!=b) {
				ra = pos[ra][1];
		}
        if(pos[ra][1]==b) right = true;
        return left and right;
}
void show(int d){
    if(pos[d][0] == -1 and pos[d][1] == -1) {
        vis[d] = 1;
        cout << (char)('a'+d);
    } else if(pos[d][0] == -1){
        vis[d] = 1;
        while(pos[d][1]>=0){
            cout << (char)('a'+d);
            d = pos[d][1];
            vis[d] = 1;
        }
        cout << (char)('a'+d);
    }else if(pos[d][1] == -1){
        vis[d] = 1;
        while(pos[d][0]>=0){
            cout << (char)('a'+d);
            d = pos[d][0];
            vis[d] = 1;
        }
        cout << (char)('a'+d);
    }
}
void debug(){
    for(int i = 0; i < 26; ++i){
        cout << pos[i][0] << " " << pos[i][1] << endl;
    }
}
int main(){
		int T;
		cin >> T;
		while(T--) {
				memset(pos, -1, sizeof pos);
				string s;
				cin >> s;
                bool exist = true;
                for(unsigned i = 1; i < s.length(); ++i){
                    int a = s[i] - 'a';
                    int b = s[i-1] - 'a';
                    if(pos[a][0]== b or pos[b][0] == a){
                        continue;
                    }else if(pos[a][0] == -1 and pos[b][1] == -1){
                        pos[a][0] = b;
                        pos[b][1] = a;
                    }else if(pos[a][1] == -1 and pos[b][0] == -1){
                        pos[a][1] = b;
                        pos[b][0] = a;
                    }else{
                        exist = false;
                        break;
                    }
                    if(check(a,b)) {
                        exist = false;
                        break;
                    }
                }
                //debug();
                if(exist == false){
                    cout << "NO" << endl;
                }else{
                    cout << "YES" << endl;
                    memset(vis, 0, sizeof vis);
                    for(int i = 0; i < 26;++i){
                        if(vis[i] == 0)
                            show(i);
                    }
                    cout << endl;
                }

		}
		return 0;
}
