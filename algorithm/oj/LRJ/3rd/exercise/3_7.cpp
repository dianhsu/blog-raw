#include <bits/stdc++.h>

using namespace std;
vector<string> vec;
array<unsigned, 4> arr;
char str[] = "ACGT";
int main(){
    int T;
    cin >> T;
    while(T--){
        int m, n;
        cin >> m >> n;
        string tmp;
        vec.clear();
        for(int i = 0; i < m; ++i){
            cin >> tmp;
            vec.push_back(tmp);
        }
        string ans;
        int dis = 0;
        for(int i = 0; i < n; ++i){
            arr.fill(0);
            for(int j = 0; j < m; ++j){
                if(vec[j][i] == 'A') arr[0]++;
                if(vec[j][i] == 'C') arr[1]++;
                if(vec[j][i] == 'G') arr[2]++;
                if(vec[j][i] == 'T') arr[3]++;
            }
            unsigned pos = 0;
            for(unsigned j = 1; j < 4; ++j){
                if(arr[j] > arr[pos]){
                    pos = j;
                }
            }
            dis += m - arr[pos];
            ans += str[pos];
        }
        cout << ans << endl << dis << endl;
    }
    return 0;
}
