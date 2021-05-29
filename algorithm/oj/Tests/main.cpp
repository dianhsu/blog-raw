#include <bits/stdc++.h>

using namespace std;

int f(int n){
    return n == 0 ? 1 : f(n-1) * n;
}
int main(){
    cout << f(3) << endl;

    return 0;
}
