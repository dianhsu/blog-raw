#include <bits/stdc++.h>

using namespace std;
int inf = 1e6;
vector<pair<int, int>> vec;
vector<int> stat;
int n;

int update_stat(const int cnt){
    int ret = 0;
    for(int i = 0; i < n; ++i){
        if(stat[i] == vec[i].first - 1){
            if(cnt > n - cnt){
                ret++;
                stat[i] = vec[i].first;
            }
        }else if(stat[i] == vec[i].first + vec[i].second - 1){
            stat[i] = 0;
        }else{
            stat[i] = stat[i] + 1;
            if(stat[i] >= vec[i].first){
                ++ret;
            }
        }
    }
    return ret;
}

int main(){
    int kase = 1;
    while(cin >> n and n){
        int a, b, c;
        vec.clear();
        stat.clear();
        int cnt = 0;
        //cnt是睡觉的人的数量
        for(int i = 0; i < n; ++i){
            cin >> a >> b >> c;
            vec.emplace_back(a,b);
            stat.push_back(c - 1);
            if(c > a) cnt++;
        }
        int pos = 1;
        while(cnt and pos < inf){
#ifndef ONLINE_JUDGE
            cout << "pos: " << pos << " cnt: " << cnt << endl;
#endif
            pos++;
            cnt = update_stat(cnt);
        }
        cout << "Case " << kase++ << ": ";
        if(cnt){
            cout << -1 << endl;
        }else{
            cout << pos << endl;
        }
    }
    return 0;
}
