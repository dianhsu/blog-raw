#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long n, g, d;
        cin >> n >> g >> d;
        long long half = n - n/2;
        long long ans = ((half % g)?(half%g):(-d)) + half/g*(g+d);
        cout << max(ans, n) << endl;
    }
    return 0;
}
