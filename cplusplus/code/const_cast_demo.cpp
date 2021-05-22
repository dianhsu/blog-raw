#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    const int a = 1;
    auto b = const_cast<int*>(&a);
    auto c = const_cast<int&>(a);
    *b = 2;
    c = 3;
    cout << "b = " << *b << " c = " << c << endl;
    cout << "type of b is " << typeid(*b).name() << endl;
    cout << "type of c is " << typeid(c).name() << endl;
    return 0;
}
/*
运行结果：
b = 2 c = 3
type of b is i
type of c is i
*/