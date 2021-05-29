#include <iostream>
#include <cmath>

int main() {
  int n, x, y;
  while (std::cin >> n >> x >> y) {
    int t = std::min(y/x+((y%x)?1:0),n);
    std::cout << n-t << std::endl;
  }
  return 0;
}
