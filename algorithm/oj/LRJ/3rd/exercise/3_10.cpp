#include <bits/stdc++.h>

using namespace std;
struct Pallet{
    unsigned w, h;
    bool operator < (const Pallet& p) const{
        if(w == p.w) return h < p.h;
        return w < p.w;
    }
}pallet[6];

int main(){
    while(cin >> pallet[0].w >> pallet[0].h){
        if(pallet[0].w > pallet[0].h) swap(pallet[0].w, pallet[0].h);
        for(unsigned i = 1; i < 6; ++i){
            cin >> pallet[i].w >> pallet[i].h;
            if(pallet[i].w > pallet[i].h) swap(pallet[i].w, pallet[i].h);
        }
        sort(pallet, pallet+6);
        bool possible = true;
        for(unsigned i = 0; i < 6; i+=2){
            if(pallet[i].w != pallet[i+1].w or pallet[i].h != pallet[i+1].h){
                possible = false;
                break;
            }
        }
        if(possible){
            if(pallet[0].w != pallet[2].w or pallet[0].h != pallet[4].w or pallet[2].h != pallet[4].h){
                possible = false;
            }
        }
        if(possible) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
