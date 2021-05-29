#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
stack<int> st;
int main(){
    int n;
    while(cin >> n and n){
        int tmp;
        while(cin >> tmp and tmp){
            vec.clear();
            vec.push_back(tmp);
            for(int i = 1; i < n; ++i){
                cin >> tmp;
                vec.push_back(tmp);
            }
            while(!st.empty()) st.pop();
            int pos = 1;
            bool exist = true;
            for(int i = 0; i < n; ++i){
                if(pos == vec[i]){
                    ++pos;
                }else if(!st.empty() and st.top() == vec[i]){
                    st.pop();
                }else if(pos <= n){
                    while(pos <= n and pos != vec[i]){
                        st.push(pos++);
                    }
                    if(pos == vec[i]){
                        ++pos;
                    }else{
                        exist = false;
                        break;
                    }
                }else{
                    exist = false;
                    break;
                }
            }
            if(exist) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;   
}
