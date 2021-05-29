#include <iostream>
#include <algorithm>

using namespace std;
void print_bin(int val){
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 4; ++j){
      if(val&(1<<(i*4+j)))
        cout << 1;
      else
        cout << 0;
    }
    if(i==7){
      cout << endl;
    }else{
      cout << ' ';
    }
  }
}
int main(){
  int x, m, n;
  while(cin >> x >> m >> n){
    int part1 = 0;
    int part2 = 0;
    int part3 = 0;
    for(int i = 0; i < 16; ++i){
        if(i < m){
          part1 += (1<<i) & x;
        }else if(i < m + n){
          part2 += (1<<i) & x;
        }else{
          part3 += (1<<i) & x;
        }
    }
    part2 = part2 << (16-m-n);
    part3 = part3 >> n;
    cout << part2 << endl;
  }
  return 0;
}
