#include <iostream>

using namespace std;

int main() {
    int a = 1;
    int* pa = &a;
    long long int b = reinterpret_cast<long long int>(pa);
    cout << "pa = " << pa << endl;
    cout << "b =  " << b << endl;
    int* c = reinterpret_cast<int*>(b);
    cout << "c =  " << c << endl;
}
/*
运行结果：
pa = 0x7ffe325c49c4
b =  140729743329732
c =  0x7ffe325c49c4
*/
