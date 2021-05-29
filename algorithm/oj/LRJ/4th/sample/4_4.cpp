#include <bits/stdc++.h>

using namespace std;
string codec;
int pos;
int c_read(int length){
    char ch;
    int ret = 0;
    while(pos + length > codec.length()){
        string tmp;
        getline(cin, tmp);
        codec += tmp;
    }
    for(int i = 0; i < length; ++i){
        ret <<= 1;
        ret += codec[pos+i] - '0';
    }
    pos += length;
    return ret;
}
int getId(int length, int code){
    int ans = code;
    for(int i = 0; i < length; ++i){
        ans += (1<<i)-1;
    }
    return ans;
}
int main(){
    string header;
    while(getline(cin, header)){
        int length = 0;
        string ans;
        codec.clear();
        pos = 0;
        while(1){
            length = c_read(3);
            if(length == 0) break;
            int code;
            while(1){
                code = c_read(length);
                if(code == (1<<length)-1) break;
                ans += header[getId(length, code)];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
