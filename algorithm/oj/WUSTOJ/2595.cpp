#include <iostream>
#include <regex>
#include <string>

using namespace std;
int main(){
  string text;
  while(getline(cin, text)){
    for(int i = 0; i < text.length(); ++i){
      if(text[i] == '6'){
        int j = i;
        while(j < text.length()){
          if(text[j]!='6'){
            break;
          }else{
            ++j;
          }
        }
        if(j-i>9){
          cout << "27";
        }else if(j-i>3){
          cout << "9";
        }else{
          for(int k = i; k < j; ++k){
            cout << '6';
          }
        }
        i = j-1;
      }else{
        cout << text[i];
      }
    }
    cout << endl;
  }
  return 0;
}
