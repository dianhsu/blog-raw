#include <bits/stdc++.h>

using namespace std;
struct Matrix{
    int a, b;
}m[26];
stack<Matrix> st;
int main(){
    int n;
    cin >> n;
    string s;
    int a, b;
    for(int i = 0; i < n; ++i){
        cin >> s >> a >> b;
        m[s[0] - 'A'].a = a;
        m[s[0] - 'A'].b = b;
    }
    string expr;
    while(cin >> expr){
        int len = expr.length();
        bool error = false;
        int ans = 0;
        for(int i = 0; i < len; ++i){
            if(isalpha(expr[i])) st.push(m[expr[i] - 'A']);
            else if(expr[i] == ')'){
                Matrix m2 = st.top(); st.pop();
                Matrix m1 = st.top(); st.pop();
#ifndef ONLINE_JUDGE
                cout << "+++++++++++++++++++++++++++++++" << endl;
                cout << "index: " << i << endl;
                cout << m1.a << " " << m1.b << endl;
                cout << m2.a << " " << m2.b << endl;
#endif
                if(m1.b != m2.a){
                    error = true;
                    break;
                }else{
                    ans += m1.a*m1.b*m2.b;
                    st.push(Matrix{m1.a, m2.b});
                }
            }
        }
        if(error) cout << "error" << endl;
        else cout << ans << endl;
    }
    return 0;
}
