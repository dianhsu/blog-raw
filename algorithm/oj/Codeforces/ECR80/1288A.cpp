#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long n, d;
        cin >> n >> d;
        bool exist = false;
        for(long long i = 0; i*(i+1) <=d; ++i){
            long long tmp = i + d/(i+1) +(d%(i+1)!=0);
            if(tmp <= n){
                exist = true;
                break;
            }
        }
        cout << (exist?"YES":"NO") << endl;
    }
    return 0;
}
