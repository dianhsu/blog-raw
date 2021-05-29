#include <bits/stdc++.h>

using namespace std;
double per_mol[] = {12.01, 1.008, 16.00, 14.01};
map<char, int> mp;
int main(){
    cout.setf(ios::fixed);
    cout.precision(3);
    int T;
    cin >> T;
    while(T--){
        mp.clear();
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); ++i){
            if(isalpha(s[i])){
                int tmp = 0;
                for(int j = i+1; j < s.length(); ++j){
                    if(isdigit(s[j])) {
                        tmp = tmp*10+s[j]-'0';
                    }else break;
                }
                if(mp.count(s[i])) mp[s[i]] += max(tmp, 1);
                else mp[s[i]] = max(tmp, 1);
            }
        }
        cout << mp['C']*per_mol[0]+mp['H']*per_mol[1]+mp['O']*per_mol[2]+mp['N']*per_mol[3] << endl;
        
    }

    return 0;
}
