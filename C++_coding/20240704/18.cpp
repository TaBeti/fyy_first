#include <iostream>
using namespace std;

//纯虚函数和抽象类
//有纯虚函数的类称为抽象类
//抽象类特点：
//1、无法实例化对象
//2、抽象类的子类必须重写父类中的纯虚函数，否则也属于抽象类
class Base {
public:
    //纯虚函数
    virtual void func() = 0;
};

class Son: public Base {
public:
    virtual void func() {
        cout << "func函数调用" << endl;
    }
};

void test01() {
    // Base b; // 报错，抽象类无法实例化对象
    // new Base; // 报错，抽象类无法实例化对象
    Base *base = new Son();
    base->func();
}

int main() {
    test01();
    return 0;
}