#include <bits/stdc++.h>

using namespace std;
array<int, 26> arr[2];
int main(){
    string a, b;
    while(cin >> a >> b){
        arr[1].fill(0);
        arr[0].fill(0);
        for(auto item: a) arr[0][item-'A']++;
        for(auto item: b) arr[1][item-'A']++;
        sort(arr[0].begin(), arr[0].end());
        sort(arr[1].begin(), arr[1].end());
        bool exist = true;
        for(int i = 0; i < 26; ++i)
            if(arr[0][i] - arr[1][i])
                exist = false;
        if(exist) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
