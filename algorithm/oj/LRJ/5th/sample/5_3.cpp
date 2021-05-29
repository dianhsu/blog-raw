#include <bits/stdc++.h>

using namespace std;

set<string> st;

int main(){
    string in;
    st.clear();
    while(getline(cin, in)){
        for(int i = 0; i < in.length(); ++i){
            if(!isalpha(in[i])){
                in[i] = ' ';
            }else{
                in[i] = tolower(in[i]);
            }
        }
        stringstream ss(in);
        string tmp;
        while(ss >> tmp){
            st.insert(tmp);
        }
    }
    for(auto item: st){
        cout << item << endl;
    }
    return 0;
}
