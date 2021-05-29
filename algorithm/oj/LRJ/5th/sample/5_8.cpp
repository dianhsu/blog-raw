#include <bits/stdc++.h>

using namespace std;
vector<string> vec;
int main(){
    int n;
    while(cin >> n){
        string ins;
        vec.clear();
        int MAX_SIZE = INT_MIN;
        while(n--){
            cin >> ins;
            vec.push_back(ins);
            MAX_SIZE = max(MAX_SIZE, (int)ins.length());
        }
        int row = 1 + (60 - MAX_SIZE)/(MAX_SIZE+2);
        sort(vec.begin(), vec.end());
        int col = vec.size() / row + (vec.size() % row != 0);
        cout << "------------------------------------------------------------" << endl;
        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
                if(j*col+i < vec.size()){
                    if(j) cout << "  ";
                    cout << left << setw(MAX_SIZE) << vec[j*col+i];
                }
            }
            cout << endl;
        }

    }
    return 0;
}
