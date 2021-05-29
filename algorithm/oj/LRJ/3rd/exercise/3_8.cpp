#include <bits/stdc++.h>

using namespace std;
map<unsigned, unsigned> mp;
vector<unsigned> vec;
int main(){
    unsigned a, b;
    while(cin >> a >> b){
        unsigned ta = a;
        mp.clear();
        vec.clear();
        vec.push_back(a/b);
        a%=b;
        unsigned index = 1;
        while(mp.count(a)==0){
            mp[a] = index++;
            vec.push_back(a*10/b);
            a = (a*10)%b;
        }
        cout << ta << "/" << b << " = ";
        for(unsigned i = 0; i < mp[a]; i++){
            cout << vec[i];
            if(!i) cout << '.';
        }
        cout << "(";
        for(unsigned i = mp[a]; i < index and i < mp[a]+50; ++i){
            cout << vec[i];
            
        }
        if(index - mp[a] > 50) cout << "...";
        cout << ")" << endl;
        cout << "   " << index - mp[a] << " = number of digits in repeating cycle\n\n";
    }
    return 0;
}
