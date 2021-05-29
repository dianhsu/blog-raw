#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> vec[26];
int main(){
    int T;
    cin >> T;
    string s, t;
    while(T--){
        cin >> s >> t;
        for(unsigned i = 0; i < 26; ++i) vec[i].clear();
        for(unsigned i = 0; i < s.length(); ++i){
            vec[s[i] - 'a'].push_back(i);
        }
        int pos = -1;
        int ans = 1;
        bool exist = true;
        for(unsigned i = 0; i < t.length(); ++i){
            auto upper = upper_bound(vec[t[i]-'a'].cbegin(), vec[t[i]-'a'].cend(), pos);
            if(upper == vec[t[i]-'a'].cend()){
                if(pos >= 0) {
                    pos = -1;
                    upper = upper_bound(vec[t[i]-'a'].cbegin(), vec[t[i]-'a'].cend(), pos);
                    if(upper == vec[t[i]-'a'].cend()){
                        exist = false;
                        break;
                    }else{
                        ++ans;
                        pos = *upper;
                    }
                }else{
                    exist = false;
                    break;
                }
                
            }else{
                pos = *upper;
            }
        }
        if(exist) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}
