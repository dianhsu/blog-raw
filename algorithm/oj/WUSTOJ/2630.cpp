#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        string v = s;
        reverse(s.begin(), s.end());
        if(s == v || v[0] != '0') cout << "True" << endl;
        else cout << "False" << endl;
    }
    return 0;
}
