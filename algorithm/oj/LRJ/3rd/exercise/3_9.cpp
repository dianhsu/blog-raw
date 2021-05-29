#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    while(cin >> s >> t){
        unsigned pos = 0;
        for(unsigned i = 0; i < t.length(); ++i){
            if(pos>=s.length()){
                break;
            }
            if(t[i] == s[pos]){
                ++pos;
            }
        }
        if(pos >= s.length()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
