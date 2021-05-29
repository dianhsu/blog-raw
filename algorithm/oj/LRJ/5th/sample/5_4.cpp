#include <bits/stdc++.h>

using namespace std;
map<string, string> mp;
string format(const string& s){
    string ret = "";
    for(auto item: s){
        ret += tolower(item);
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main(){
    string s;
    mp.clear();
    while(cin >> s and s != "#"){
        string ret = format(s);
        if(mp.count(ret) == 0){
            mp[ret] = s;
        }else{
            mp[ret] = "";
        }
    }
    vector<string> vec;
    for(auto item: mp){
        if(item.second != ""){
            vec.push_back(item.second);
        }
    }
    sort(vec.begin(), vec.end());
    for(auto item: vec){
        cout << item << endl;
    }
    return 0;
}
