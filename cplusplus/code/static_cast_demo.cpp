#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    double a = 1.23;
    auto b = static_cast<int>(a);
    cout << b << endl;                   // 1
    cout << typeid(b).name() << endl;    // i (i 表示 int)
    return 0;
}
/*
运行结果：
b = 2 c = 3
type of b is i
type of c is i
*/
