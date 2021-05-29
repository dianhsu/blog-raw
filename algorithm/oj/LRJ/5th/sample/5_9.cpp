#include <bits/stdc++.h>

using namespace std;
vector<int> vec[10010];
int n, m;
map<string, int> mp;
bool solve(int &r1, int &r2, int &c1, int &c2){
    for(int i = 0; i < m; ++i){
        for(int j = i + 1; j < m; ++j){
            map<pair<int, int>, int> lmp;
            for(int k = 0; k < n; ++k){
                auto pr = make_pair(vec[k][i], vec[k][j]);
                if(lmp.count(pr)){
                    c1 = i, c2 = j, r1 = lmp[pr], r2 = k;
                    return true;
                }else{
                    lmp[pr] = k;
                }
            }
        }
    }
    return false;
}
int main(){
    string in;
    while(getline(cin, in)){
        stringstream ss(in);
        ss >> n >> m;
        int cnt = 0;
        mp.clear();
        for(int i = 0; i < n; ++i){
            vec[i].clear();
            getline(cin, in);
            string tmp="";
            for(auto item: in){
                if(item == ','){
                    if(mp.count(tmp)){     
                        vec[i].push_back(mp[tmp]);
                    }else{
                        mp[tmp] = ++cnt;
                        vec[i].push_back(cnt);
                    }
                    tmp = "";
                }else{
                    tmp += item;
                }
            }
            if(mp.count(tmp)){
                vec[i].push_back(mp[tmp]);
            }else{
                mp[tmp] = ++cnt;
                vec[i].push_back(cnt);
            }
        }
        int r1, r2, c1, c2;
        bool exist = solve(r1, r2, c1, c2);
        if(exist){
            cout << "NO" << endl;
            cout << r1+1 << " " << r2+1 << endl;
            cout << c1+1 << " " << c2+1 << endl;
        }else{
            cout << "YES" << endl;
        }
   }
    return 0;
}
