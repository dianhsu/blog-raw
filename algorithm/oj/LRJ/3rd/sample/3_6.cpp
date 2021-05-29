#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    while(cin >> T){
        while(T--){
            string s;
            cin >> s;
            string ls = s;
            ls += s;
            int pos = 0;
            for(int i = 1; i < s.length(); ++i){
                if(ls.compare(pos, s.length(), ls, i, s.length())>0) pos = i; 
            }
            cout << ls.substr(pos, s.length()) << endl;
        }
    }
    return 0;
}
