#include <bits/stdc++.h>

using namespace std;
map<char, string> mp;
vector<string> word, morse;
int main(){
    string key, value;
    mp.clear();
    while(cin >> key and key != "*"){
        cin >> value;
        mp[key[0]] = value;
    }
    word.clear();
    morse.clear();
    while(cin >> key and key != "*"){
        word.push_back(key);
        string ms = "";
        for(auto item: key){
            ms += mp[item];
        }
        morse.push_back(ms);
    }
    while(cin >> key and key != "*"){
        int cnt = 0;
        int pos = -1;
        for(int i = 0; i < word.size(); ++i){
            if(key == morse[i]){
                if(!cnt) pos = i;
                ++cnt;
                
            }
        }
        if(cnt > 1){
            cout << word[pos] << "!" << endl;
            continue;
        }else if(cnt==1){
            cout << word[pos] << endl;
            continue;
        }else{
            int size_1 = INT_MAX;
            int pos_1 = -1;
            for(int i = 0; i < word.size(); ++i){
                if(morse[i].length() <= key.length() and key.compare(0, morse[i].length(), morse[i])==0){
                    int len1 = morse[i].length();
                    int len2 = key.length();
                    if(size_1 > abs(len1-len2)){
                        size_1 = abs(len1-len2);
                        pos_1 = i;
                    }
                }else if(morse[i].length() > key.length() and morse[i].compare(0, key.length(), key)==0){
                    int len1 = morse[i].length();
                    int len2 = key.length();
                    if(size_1 > abs(len1-len2)){
                        size_1 = abs(len1-len2);
                        pos_1 = i;
                    }
                }
            }
            if(pos_1>=0){
                cout << word[pos_1] << "?" << endl;
            }
        }
    }
    return 0;
}
