#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long A, B;
        cin >> A >> B;
        cout << (long long)(log10(B+1))*A << endl;

    }
    return 0;
}
