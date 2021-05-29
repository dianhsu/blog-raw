#include <bits/stdc++.h>

using namespace std;
char mat[15][15];
vector<pair<int, string>> row,col;
int main(){
    int n, m;
    int kase = 0;
    while(cin >> n and n){
        cin >> m;
        for(int i = 0; i < n; ++i) cin >> mat[i];
        int cnt = 0;
        row.clear();
        col.clear();
        for(int i = 0; i < n*m; ++i) {
            if(mat[i/m][i%m] == '*') continue;
            if(i/m == 0 or mat[i/m-1][i%m] == '*' or i%m == 0 or mat[i/m][i%m-1] == '*')
                ++cnt;
            if(i/m == 0 or mat[i/m-1][i%m] == '*'){
                string tmp = "";
                for(int j = i; j < n*m; j+= m){
                    if(mat[j/m][j%m] != '*')
                        tmp += mat[j/m][j%m];
                    else
                        break;
                }
                col.push_back(make_pair(cnt, tmp));
            }
            if(i%m == 0 or mat[i/m][i%m-1] == '*'){
                string tmp = "";
                for(int j = i; j/m == i/m; ++j){
                    if(mat[j/m][j%m] != '*'){
                        tmp += mat[j/m][j%m];
                    }else
                        break;
                }
                row.push_back(make_pair(cnt, tmp));
            }
        }
        if(kase) cout << endl;
        cout << "puzzle #" << ++kase << ":\n";
        cout << "Across" << endl;
        for(auto item:row)
            cout << setw(3) << item.first << "." << item.second << endl;
        cout << "Down" << endl;
        for(auto item:col)
            cout << setw(3) << item.first << "." << item.second << endl;
    }
    return 0;
}
