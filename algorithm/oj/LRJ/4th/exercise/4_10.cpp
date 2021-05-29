#include <bits/stdc++.h>

using namespace std;
vector<double> vec;
pair<int, double> count(double meter){
    pair<int,double> ans = make_pair(0,0);
    for(auto item:vec){
        if(meter > item){
            ans.first++;
            ans.second += (meter-item)*100;
        }
    }
    return ans;
}
int main(){
    int n, m;
    cout.setf(ios::fixed);
    cout.precision(2);
    int region = 1;
    while(cin >> n >> m and n){
        vec.clear();
        double tmp;
        for(int i = 0; i < n*m; ++i){
            cin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end());
        double water;
        cin >> water;
        double high = water;
        double low = 0;
        pair<int, double> cnt;
        while(high - low > 0.00001){
            double mid = (high+low)/2;
            cnt=count(mid);
            if(cnt.second > water){
                high = mid;
            }else{
                low = mid;
            }
        }
        cnt = count(low);
        cout << "Region " << region++ << endl;
        cout << "Water level is " << low << " meters." << endl;
        cout << (double)cnt.first*100.0/(n*m) << " percent of the region is under water." << endl;
    }
    return 0;
}
