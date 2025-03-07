#include <iostream>
using namespace std;

class Person {
public:
    void setName(string name) {
        m_name = name;
    }
    string getName() {
        return m_name;
    }
    int getAge() {
        return m_age;
    }
    void setIdol(string idol) {
        m_idol = idol;
    }

private: 
    string m_name;
    int m_age = 18;
    string m_idol;
}

int main() {
    //成员属性设置为私有
    Person p;
    p.setName("Alice");
    cout << "姓名：" << p.getName() << endl;
}