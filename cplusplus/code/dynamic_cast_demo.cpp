#include <iostream>

using namespace std;

class Fruit {
public:
    virtual void show() {
        cout << "I am fruit" << endl;
    }
};
class Apple : public Fruit {
public:
    void show() {
        cout << "I am apple" << endl;
    }
};
class Banana : public Fruit {
public:
    void show() {
        cout << "I am banana" << endl;
    }
};
int main() {
    Fruit f;
    Apple a;
    Banana b;
    // 转换成功
    Fruit* pf1 = dynamic_cast<Fruit*>(&a);
    a.show();               // I am apple
    pf1->show();            // I am apple
    cout << &a << endl;     // 0x7ffe3298d910
    cout << pf1 << endl;    // 0x7ffe3298d910
    Fruit* pf2 = dynamic_cast<Fruit*>(&b);
    b.show();               // I am banana
    pf2->show();            // I am banana
    cout << &b << endl;     // 0x7ffe3298d908
    cout << pf2 << endl;    // 0x7ffe3298d908
    // 转换失败
    Apple* pa = dynamic_cast<Apple*>(&b);
    cout << &b << endl;     // 0x7ffe3298d908
    cout << pa << endl;     // 0
    Banana& pb = dynamic_cast<Banana&>(a);    
// terminate called after throwing an instance of 'std::bad_cast'
}
