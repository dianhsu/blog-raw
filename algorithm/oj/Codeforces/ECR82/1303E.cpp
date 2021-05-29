#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <cstring>

using namespace std;
int dp[420][420];
bool exist(const string &s, const string t1, const string t2){
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(unsigned i = 0; i < s.length(); i++){
        for(unsigned j = 0; j <= t1.length(); ++j){
            if(dp[i][j] < 0) continue;
            if(j < t1.length() and s[i] == t1[j])
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            if(dp[i][j] < (int)t2.length() and s[i] == t2[dp[i][j]])
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            //cout << "[exist function] " << dp[i+1][j] << " " << dp[i+1][j+1] << endl;
        }
    }
    if(dp[s.length()][t1.length()] >= (int)t2.length()) return true;
    return false;
}
bool solve(const string &s, const string &t){
    for(unsigned i = 0; i < t.length(); ++i){
        //cout << "[solve function]" << s << ' ' << t.substr(0, i) << ' ' << t.substr(i) << ' ' << endl;
        if(exist(s, t.substr(0,i), t.substr(i))){
            return true;
        }
    }
    return false;
}

int main(){
    int T;
    cin >> T;
    string s,t;
    while(T--){
        cin >> s >> t;
        cout << (solve(s, t)?"YES":"NO") << endl;
    }
    return 0;
}
