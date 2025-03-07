#include <iostream>
using namespace std;

//构造函数的调用规则
//1、创建一个类，C++编译器会给每个类都添加至少3个函数
//默认构造
//析构函数
//拷贝构造
//2、如果我们写了有参构造函数，编译器就不再提供默认构造，依然提供拷贝构造
//3、如果我们写了拷贝构造函数，编译器就不再提供普通构造

class Person {
public:
    int m_age;
    // Person() {
    //     cout << "Person默认构造函数调用" << endl;
    // }

    Person(int age) {
        m_age = age;
        cout << "Person有参构造函数调用" << endl;
    }

    // Person(const Person &p) {
    //     m_age = p.m_age;
    //     cout << "Person拷贝构造函数调用" << endl;
    // }

    ~Person() {
        cout << "Person析构函数调用" << endl;
    }
};

// void test01() {
//     Person p;
//     p.m_age = 18;
//     Person p2(p);
//     cout << "p2的年龄为：" << p2.m_age << endl;
// }

void test02() {
    Person p(20);
    Person p2(p);
    cout << "p2的年龄为：" << p2.m_age << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}