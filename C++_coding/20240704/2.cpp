#include <iostream>
using namespace std;

//左移运算符重载
class Person {
public:
    int m_A;
    int m_B;
    //一般来说不会利用成员函数进行左移运算符重载，因为无法实现cout在左侧
    // void operator<<(Person &p) {}
};

//只能利用全局函数重载左移运算符
//本质 operator<<(cout, p)，简化cout << p;
ostream& operator<<(ostream &out, Person &p) {
    out << "m_A = " << p.m_A << " m_B = " << p.m_B;
    return out;
}

void test01() {
    Person p;
    p.m_A = 10;
    p.m_B = 10;
    cout << p << endl; 
}

int main() {
    test01();
    return 0;
}