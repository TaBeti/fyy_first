#include <iostream>
using namespace std;

void func(int &ref) {
    ref = 100;//ref是引用，转换为*ref = 100
}

int main() {
    //引用的本质在C++内部实现是一个指针常量
    int a = 10;
    //自动转换为int* const ref = &a
    int &ref = a;
    ref = 20;
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    func(a);
    cout << "a = " << a << endl;
    return 0;
}