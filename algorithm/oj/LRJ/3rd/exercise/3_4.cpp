#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool first = true;
    while(n--){
        string s;
        cin >> s;
        int x = s.length();
        for(int i = 1; i <= x; ++i){
            if(x%i) continue;
            bool exist = true;
            for(int j = i; j<x; j+=i){
                if(s.compare(0, i, s, j, i)!=0){
                    exist = false;
                }
            }
            if(exist){
                if(first) first = false;
                else cout << endl;
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
