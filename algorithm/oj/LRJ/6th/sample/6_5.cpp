#include <bits/stdc++.h>

using namespace std;
const int maxn = 100100;

int n, ptr_l[maxn], ptr_r[maxn];

inline void link(int L, int R){
    ptr_r[L] = R;
    ptr_l[R] = L;
}

int main(){
    int m, kase = 0;
    while(cin >> n >> m){
        for(int i = 1; i <= n; ++i){
            ptr_l[i] = i-1;
            ptr_r[i] = (i+1)%(n+1);
        }
        ptr_r[0] = 1;
        ptr_l[0] = n;
        int op, X, Y, inv = 0;
        while(m--){
            cin >> op;
            if(op == 4) inv = !inv;
            else{
                cin >> X >> Y;
                if(op == 3 and ptr_r[Y] == X) swap(X, Y);
                if(op != 3 and inv) op = 3 - op;
                if(op == 1 and X == ptr_l[Y]) continue;
                if(op == 2 and X == ptr_r[Y]) continue;
                int LX = ptr_l[X], RX = ptr_r[X], LY = ptr_l[Y], RY = ptr_r[Y];
                if(op == 1){
                    link(LX, RX); link(LY, X); link(X, Y);
                }else if(op == 2){
                    link(LX, RX); link(Y, X); link(X, RY);
                }else if(op == 3){
                    if(ptr_r[X] == Y){
                        link(LX, Y); link(Y, X); link(X, RY);
                    }else{
                        link(LX, Y); link(Y, RX); link(LY, X); link(X, RY);
                    }
                }
            }
        }
        int b = 0;
        long long ans = 0;
        for(int i = 1; i <= n; ++i){
            b = ptr_r[b];
            if(i&1) ans += b;
        }
        if(inv and (n&1==0)) ans = (long long)n*(n+1)/2 - ans;
        cout << "Case " << ++kase << ": " << ans << endl;
    }
    return 0;
}
