#include <bits/stdc++.h>
using namespace std;
double eps = 1e-4;
double M[20][40];
long long E[20][40];

int main(){
    string s;
    while(cin >> s and s != "0e0"){
        s[s.find('e')] = ' ';
        for(int i = 0; i <= 9; ++i)
            for(int j = 1; j <= 30; ++j){
                double m = 1- exp2(-1-i);
                double e = exp2(j) - 1;
                double t = log10(m) + e*log10(2);
                E[i][j] = t;
                M[i][j] = pow(10, t - E[i][j]);
            }
        stringstream ss(s);
        double A;
        long long B;
        ss >> A >> B;
        while(A<1) A*=10,B-=1;
        for(int i = 0; i <= 9; ++i)
            for(int j = 1; j <= 30; ++j){
                if(B == E[i][j] and (fabs(A-M[i][j]) < eps or fabs(A/10-M[i][j]) < eps)){
                    cout << i << " " << j << endl;
                    break;
                }
            }
    }
    return 0;
}
