#include <iostream>
using namespace std;

//继承同名成员处理
class Base {
public:
    int m_A;
    Base() {
        m_A = 100;
    }
    void func() {
        cout <<  "Base-func调用" << endl;
    }
    void func(int a) {
        cout <<  "Base-func(int a)调用" << endl;
    }
};

class Son: public Base {
public:
    int m_A;
    Son() {
        m_A = 200;
    }
    void func() {
        cout <<  "Son-func调用" << endl;
    }
};

//同名属性处理
void test01() {
    Son s;
    cout << "Son下m_A = " << s.m_A << endl; //输出200
    //如果通过子类对象访问到父类中同名成员，需要加作用域
    cout << "Base下m_A = " << s.Base::m_A << endl; //输出1+00
}

//同名成员函数处理
void test02() {
    Son s;
    s.func();//直接调用是子类中的同名成员
    s.Base::func();//通过作用域调用父类中的同名成员
    s.Base::func(100);
}

int main() {
    test01();
    test02();
    return 0;
}