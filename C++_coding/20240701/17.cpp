#include <iostream>
using namespace std;

//常函数
class Person {
public:
    int m_A;
    mutable int m_B; //mutable修饰的变量，可以被const函数修改
    //this指针的本质是指针常量，指针的指向是不可以修改的
    //const Person* const this;
    //在成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改
    Person() {}
    void showPerson() const {
        // this->m_A = 100;//常函数内不可以修改属性，修改会报错
        this->m_B = 100;
    }
    void func() {

    }
};

// void test01() {
//     Person p;
//     p.showPerson();
// }

void test02() {
    const Person p;//常对象
    // p.m_A = 100;
    p.m_B = 200;//m_B是特殊值，在常对象下也可以修改
    //常对象只能调用常函数
    p.showPerson();
    // p.func();//报错
}

int main() {
    // test01();
    test02();
    return 0;
}