#include <iostream>
using namespace std;

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
class Person {
public:
    static int m_A;
    int m_B;
    static void func() {
        m_A = 100;
        // m_B = 200;//报错，静态成员不可以访问非静态成员变量，无法区分到底是哪个对象
        cout << "static void func调用" << endl;
    }
};

void test01() {
    //1、通过对象访问
    Person p;
    p.func();
    //2、通过类名访问
    Person::func();
}

int main() {
    test01();
    return 0;
}