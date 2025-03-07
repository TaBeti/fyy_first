#include <iostream>
using namespace std;

//空指针访问成员函数
class Person {
public:
    int m_age;
    void showClassName() {
        cout << "this is person class" << endl;
    }
    void showPersonAge() {
        if (this == NULL) {
            return;
        }
        cout << "age = " << m_age << endl;
    }
};

void test01() {
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();
}

int main() {
    test01();
    return 0;
}