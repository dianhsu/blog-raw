#include <bits/stdc++.h>

using namespace std;
string msg[4] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char get_r(char c){
    if(isalpha(c)) return rev[c-'A'];
    else return rev[c-'1'+26];
}
int main(){
    string s;
    while(cin >> s){
        string s_r = s;
        reverse(s_r.begin(), s_r.end());
        bool palindrome = false;
        if(s_r == s) palindrome = true;
        bool mirror = true;
        for(unsigned i = 0; i < s.length(); ++i){
            if(get_r(s[i]) != s_r[i]) {
                mirror = false;
                break;
            }
        }
        cout << s << " -- is " << msg[mirror*2+palindrome] << ".\n\n";
    }
    return 0;
}
