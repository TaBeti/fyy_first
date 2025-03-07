#include <iostream>
using namespace std;

//类对象作为类成员
class Phone {
public:
    string m_pname;
    Phone(string pname) {
        m_pname = pname;
        cout << "Phone构造函数调用" << endl;
    }
    ~Phone() {
        cout << "Phone析构函数调用" << endl;
    }
};

class Person {
public:
    string m_name;
    Phone m_phone;
    //Phone m_phone = pname; 隐式转换法
    Person(string name, string pname) : m_name(name), m_phone(pname) {
        cout << "Person构造函数调用" << endl;
    }
    ~Person() {
        cout << "Person析构函数调用" << endl;
    }
};

//当其他类对象作为本类成员，构造时先构造类对象，再构造自身，析构顺序相反
void test01() {
    Person p("张三", "苹果max");
    cout << p.m_name << "拿着：" << p.m_phone.m_pname << endl;
}

int main() {
    test01();
    return 0;
}