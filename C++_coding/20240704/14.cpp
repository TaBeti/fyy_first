#include <iostream>
using namespace std;

//多继承语法
class Base1 {
public:
    int m_A;
    Base1() {
        m_A = 100;
    }
};

class Base2 {
public:
    int m_A;
    Base2() {
        m_A = 200;
    }
};

//语法：class 子类：继承方式 父类1，继承方式 父类2
class Son: public Base1, public Base2 {
public:
    int m_C;
    int m_D;
    Son() {
        m_C = 300;
        m_D = 400;
    }
};

void test01() {
    Son s;
    cout << "sizeof Son = " << sizeof(s) << endl;
    //当父类中出现同名成员，需要加作用域
    cout << "m_A = " << s.Base1::m_A << endl;
    cout << "m_A = " << s.Base2::m_A << endl;
}

int main() {
    test01();
    return 0;
}