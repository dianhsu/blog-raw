#include <bits/stdc++.h>

using namespace std;
vector<unsigned> vec;
void show_address(unsigned address){
    cout << ((address>>24)&255)
        << "." << ((address>>16)&255)
        << "." << ((address>>8)&255)
        << "." << (address&255)
        << endl;
}
int main(){
    int n;
    while(cin >> n){
        vec.clear();
        for(int i = 0; i < n; ++i){
            string in;
            cin >> in;
            for(int j = 0; j < in.length(); ++j){
                if(in[j]=='.') in[j]=' ';
            }
            stringstream ss(in);
            unsigned t1,t2,t3,t4;
            ss >> t1 >> t2 >> t3 >> t4;
            unsigned address = (t1<<24)+(t2<<16)+(t3<<8)+t4;
            vec.push_back(address);
        }
        unsigned mask = 0;
        for(int i = 31; i >= 0; --i){
            unsigned cmp = ((unsigned)1) << i;
            unsigned first = cmp & vec[0];
            bool eq = true;
            for(auto item: vec){
                if((item & cmp) != first){
                    eq = false;
                    break;
                }
            }
            if(eq){
                mask += cmp;
            }else{
                break;
            }
        }
        unsigned ip = (mask&vec[0]);
        show_address(ip);
        show_address(mask);
    }
    return 0;
}
