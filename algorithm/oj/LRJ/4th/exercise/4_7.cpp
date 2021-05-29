#include <bits/stdc++.h>

using namespace std;
vector<string> vec;
char dic[] = "0123456789ABCDEF";
bool check(int type, int d, int s, int b){
    for(int i = 0; i < b; ++i){
        for(int j = 0; j < d; ++j){
            if(i%d == j){
                for(int k = 0; k < s; ++k){
                    if(vec[j][i*s+k] == 'x') {
                        return false;
                    }
                }
            }
        }
    }
    for(int pos = 0; pos < b * s; ++pos){
        int ans = 0;
        int unknow = 0;
        for(int i = 0; i < d; ++i){
            if(vec[i][pos] == 'x') 
                unknow++;
            else 
                ans ^= (vec[i][pos]-'0');
        }
        if(unknow > 1){
            return false;
        }else if(unknow == 0){
            if(ans != type) {
                return false;
            }
        }else{
            for(int i = 0; i < d; ++i){
                if(vec[i][pos] == 'x') vec[i][pos] = '0' + (ans ^ type);
            }
        }
    }
    return true;
}
void show_matrix(){
    for(auto item: vec){
        cout << item << endl;
    }
}
string show(int d, int s, int b){
    string ret = "";
    for(int i = 0; i < b; ++i){
        for(int j = 0; j < d; ++j){
            if(i%d != j){
                for(int k = 0; k < s; ++k){
                    ret += vec[j][i*s+k];
                }
            }
        }
    }
    while(ret.length()%4) ret+='0';
    string ans = "";
    for(int i = 0; i < ret.length(); i+=4){
        int v = 0;
        for(int j = 0; j < 4; ++j){
            v<<=1;
            if(ret[i+j] == '1'){
                v++;
            }
        }
        ans += dic[v];
    }
    return ans;
}

int main(){
    int d, s, b;
    int kase = 0;
    while(cin >> d and d){
        cin >> s >> b;
        string type, tmp;
        cin >> type;
        vec.clear();
        for(int i = 0; i < d; ++i){
            cin >> tmp;
            vec.push_back(tmp);
        }
        if(check(type != "E", d, s, b)){
            cout << "Disk set " << ++kase << " is valid, contents are: " << show(d,s,b) << endl;
        }else{
            cout << "Disk set " << ++kase << " is invalid." << endl;
        }
    }
    return 0;
}
