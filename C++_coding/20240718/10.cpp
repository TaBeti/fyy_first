#include <iostream>
using namespace std;

//类模板对象做函数参数
template<class T1, class T2>
class Person {
public:
    T1 m_Name;
    T2 m_Age;

    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
    }
};
//1、指定传入类型
void PrintPerson1(Person<string, int> &p) {
    p.showPerson();
}

void test01() {
    Person<string, int> p("孙悟空", 100); 
    PrintPerson1(p);
}

//2、参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p) {
    p.showPerson();
    cout << "T1的类型为：" << typeid(T1).name() << endl;
    cout << "T2的类型为：" << typeid(T2).name() << endl;
}

void test02() {
    Person<string, int> p("猪八戒", 90);
    printPerson2(p);
}

//3、整个类模板化
template<class T>
void printPerson3(T &p) {
    p.showPerson();
    cout << "T的类型为：" << typeid(T).name() << endl;
}

void test03() {
    Person<string, int> p("沙僧", 30);
    printPerson3(p);
}

int main() {
    // test01();
    // test02();
    test03();
    return 0;
}