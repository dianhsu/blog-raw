#include <bits/stdc++.h>

using namespace std;
unsigned guess(string &s, char c){
    unsigned match = 0;
    for(auto ptr = s.begin(); ptr != s.end(); ptr++){
        if(*ptr == c){
            ++match;
            *ptr = ' ';
        }
    }
    return match;
}
int main(){
    int kase;
    string s, t;
    while(cin >> kase and kase != -1){
        cin >> s >> t;
        cout << "Round " << kase << endl;
        unsigned match = 0, chance = 7;
        string ans;
        for(auto item: t){
            unsigned tmp = guess(s, item);
            match += tmp;
            if(tmp == 0){
                --chance;
            }
            if(match == s.length()) {
                ans = "You win.";
                break;
            }
            if(chance == 0){
                ans = "You lose.";
                break;
            }
        }
        if(ans.empty()) ans = "You chickened out.";
        cout << ans << endl;
    }
    return 0;
}
