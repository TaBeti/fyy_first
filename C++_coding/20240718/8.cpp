#include <iostream>
using namespace std;

//类模板与函数模板区别
template<class NameType, class AgeType = int>
class Person {
public:
    NameType m_Name;
    AgeType m_Age;

    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "name: " << this->m_Name << " age: " << this->m_Age << endl; 
    }
};

//1、类模板没有自动类型推导使用方式
void test01() {
    // Person p("孙悟空", 1000);//报错
    Person<string, int> p("孙悟空", 1000);//报错
    p.showPerson();
}

//2、类模板可以有默认参数
void test02() {
    Person<string> p("猪八戒", 999);
    p.showPerson();
}

int main() {
    // test01();
    test02();
    return 0;
}