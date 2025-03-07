#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base构造函数" << endl;
    }
    ~Base() {
        cout << "Base析构函数" << endl;
    }
};

class Son: public Base {
public:
    Son() {
        cout << "Son构造函数" << endl;
    }
    ~Son() {
        cout << "Son析构函数" << endl;
    }
};

void test01() {
    // Base b;
    //继承中的构造和析构顺序相反
    //先构造父类再构造子类，先析构子类再析构父类
    Son s;
}

int main() {
    test01();
    return 0;
}