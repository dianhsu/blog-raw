#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

vector<long long> vec;
long long solve(long long r, long long n){
    vec.clear();
    for(long long i = 2; i*i <= n; ++i){
        if(n%i == 0){
            vec.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n > 1) vec.push_back(n);
    long long rev = 0;
    for(int msk = 1; msk < (1 << vec.size()); ++msk){
        long long mult = 1;
        int bits = 0;
        for(int i = 0; i < vec.size(); ++i){
            if(msk & (1LL << i)){
                ++bits;
                mult *= vec[i];
            }
        }
        long long cur = r/mult;
        if(bits & 1) rev += cur;
        else rev -= cur;
    }
    return r - rev;
}

int main(){
    unsigned T;
    cin >> T;
    while(T--){
        long long a, m;
        cin >> a >> m;
        long long tmp = gcd(a, m);
        a/=tmp;
        m/=tmp;
        cout << solve(a+m-1,m)-solve(a-1,m) << endl;
    }
    return 0;
}
