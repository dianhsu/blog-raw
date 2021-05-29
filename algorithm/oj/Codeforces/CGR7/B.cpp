#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    long long a = 0;
    long long b;
    long long x = 0;
    bool first = true;
    for(int i = 1; i <= n; ++i){
        cin >> b;
        a = b + x;
        x = max(a, x);
        if(first) first = false;
        else cout << " ";
        cout << a;
    }
    cout << endl;
    return 0;
}
