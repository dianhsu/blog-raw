#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a, b;
  while (cin >> a >> b) {
    cout << ((b%a==0) ? "yes" : "no") << endl;
  }
  return 0;
}
