#include <bits/stdc++.h>

using namespace std;
array<unsigned, 400> arr;
int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        unsigned c1 = s1.length(), c2 = s2.length();
        arr.fill(0);
        for(unsigned i = c1; i < c1+c2; ++i){
            arr[i] = s2[i-c1] - '0';
        }
        unsigned ans = c1 + c2;
        for(unsigned i = 0; i < c1+c2; ++i){
            bool accept = true;
            for(unsigned j = i; j < i+c1; ++j){
                if(s1[j-i]+arr[j] > '3'){
                    accept = false;
                }
            }
            if(!accept) continue;
            unsigned pos_l = min(i, c1);
            unsigned pos_r = max(i+c1, c1+c2);
            ans = min(ans, pos_r - pos_l);
        }
        cout << ans << endl;
    }
    return 0;
}
