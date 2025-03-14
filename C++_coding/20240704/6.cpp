#include <iostream>
using namespace std;

//关系运算符重载
class Person {
public:
    string m_name;
    int m_age;
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    bool operator==(Person &p) {
        if (this->m_name == p.m_name && this->m_age == p.m_age) {
            return true;
        }
        return false;
    }
    bool operator!=(Person &p) {
        if (this->m_name != p.m_name && this->m_age != p.m_age) {
            return true;
        }
        return false;
    }
};

void test01() {
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if (p1 == p2) {
        cout << "p1和p2是相等的！" << endl;
    }
    else {
        cout << "p1和p2是不相等的！" << endl;
    }
    if (p1 != p2) {
        cout << "p1和p2是不相等的！" << endl;
    }
    else {
        cout << "p1和p2是相等的！" << endl;
    }
}

int main() {
    test01();
    return 0;
}