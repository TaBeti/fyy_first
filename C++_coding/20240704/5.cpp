#include <iostream>
using namespace std;

class Person {
public:
    int *m_age;
    Person(int age) {
        m_age = new int(age);
    }
    ~Person() {
        if (m_age != NULL) {
            delete m_age;
            m_age = NULL;
        }
    }
    //重载赋值运算符
    Person& operator=(Person &p) {
        //编译器是提供浅拷贝
        // m_age = p.m_age;
        //应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if (m_age != NULL) {
            delete m_age;
            m_age = NULL;
        }
        //深拷贝
        m_age = new int(*p.m_age);
        return *this;
    }
};



void test01() {
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;
    cout << "p1的年龄是：" << *p1.m_age << endl;
    cout << "p2的年龄是：" << *p2.m_age << endl;
    cout << "p3的年龄是：" << *p3.m_age << endl;
}

int main() {
    test01();
    return 0;
}