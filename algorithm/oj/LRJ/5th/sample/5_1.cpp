#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
int main(){
    int n, m;
    int kase = 1;
    while(cin >> n >> m and n){
        vec.clear();
        int tmp;
        for(int i = 0; i < n; ++i){
            cin >> tmp;
            vec.push_back(tmp);
        }
        cout << "CASE# " << kase++ << ":" << endl;
        sort(vec.begin(), vec.end());
        for(int i = 0; i < m; ++i){
            cin >> tmp;
            auto ptr = lower_bound(vec.begin(), vec.end(), tmp);
            if(ptr != vec.end() and *ptr == tmp){
                cout << tmp << " found at " << (ptr-vec.begin()+1) << endl;
            }else{
                cout << tmp << " not found" << endl;
            }
        }
    }
    return 0;
}
