#include <bits/stdc++.h>

using namespace std;

array<int, 1010> guess, answer;
array<int, 10> cnt_g, cnt_a;
int main(){
    int n;
    int index = 0;
    while(cin >> n and n){
        cout << "Game " << (++index) << ":\n";
        for(int i = 0; i < n; ++i){
            cin >> answer[i];
        }
        bool status = true;
        while(status){
            status = false;
            for(int i = 0; i < n; ++i){
                cin >> guess[i];
                if(guess[i]) status = true;
            }
            if(!status) break;
            cnt_a.fill(0);
            cnt_g.fill(0);
            int a = 0, b = 0;
            for(int i = 0; i < n; ++i){
                if(guess[i] == answer[i]){
                    ++a;
                }else{
                    cnt_g[guess[i]]++;
                    cnt_a[answer[i]]++;
                }
            }
            for(int i = 0; i < 10; ++i) b += min(cnt_g[i], cnt_a[i]);
            cout << "    (" << a << "," << b << ")" << endl;
        }
    }
    return 0;
}
