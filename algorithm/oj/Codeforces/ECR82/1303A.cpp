#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int sum = 0;
        for(int i = 0; i < s.length(); ++i){
            if (s[i]=='0') sum++;
        }
        for(int i = 0; i < s.length(); ++i){
            if(s[i] =='1') break;
            else sum --;
        }
        for(int i = s.length()-1; i >=0; --i){
            if(s[i] =='1') break;
            else sum --;
        }
        if(sum < 0) sum = 0;
        cout << sum  << endl;
    }
    return 0;
}
