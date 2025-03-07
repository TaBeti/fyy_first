#include <iostream>
using namespace std;

//重置递减运算符
class MyInteger {
    // friend ostream& operator<<(ostream &out, MyInteger &myint);
    friend ostream& operator<<(ostream &out, MyInteger myint);
public:
    MyInteger() {
        m_num = 1;
    }
    //重置前置递减运算符
    MyInteger& operator--() {
        m_num--;
        return *this;
    }
    MyInteger operator--(int) {
        MyInteger temp = *this;
        m_num--;
        return temp;
    }
private:
    int m_num;
};

// ostream& operator<<(ostream &out, MyInteger &myint) {
//     out << myint.m_num;
//     return out;
// }

ostream& operator<<(ostream &out, MyInteger myint) {
    out << myint.m_num;
    return out;
}

// void test01() {
//     MyInteger myint;
//     cout << --myint << endl;
//     cout << myint << endl;
// }

void test02() {
    MyInteger myint;
    cout << myint-- << endl;
    cout << myint << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}