#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, Sp, Sq;
    while(cin >> N >> Sp >> Sq){
        int A_B = 0;
        while((Sp<<A_B)+Sp < Sq){
            ++A_B;
        }
        cout << "A_B:" << A_B << endl;
        int sum = (Sp<<A_B)+Sp;
        int B = 0;
        while(sum-(Sp>>(1+B)) >= Sq and B < 30){
            sum -= (Sp>>(1+B));
            ++B;
        }
        cout <<(A_B+B) << " " << B << endl; 
    }
    return 0;
}
