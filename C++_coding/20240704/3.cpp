#include <iostream>
using namespace std;

//重载递增运算符
//自定义整型
class MyInteger {
    // friend ostream& operator<<(ostream &out, MyInteger &myint);
    friend ostream& operator<<(ostream &out, MyInteger myint);
public:
    MyInteger() {
        m_num = 0;
    }
    //重载前置递增运算符
    //返回引用是为了一直实现递增
    MyInteger& operator++() {
        m_num++;
        return *this;
    }
    //重载后置递增运算符
    MyInteger operator++(int) {//int参数是为了区分前置和后置
        MyInteger temp = *this;//先记录当前结果
        m_num++;//后递增
        return temp;
    }
private:
    int m_num;
};

//重载左移运算符
// ostream& operator<<(ostream &out, MyInteger &myint) {
//     out << myint.m_num;
//     return out;
// }

ostream& operator<<(ostream &out, MyInteger myint) {
    out << myint.m_num;
    return out;
}

void test01() {
    MyInteger myint;
    cout << ++myint << endl;
    cout << myint << endl;
}

void test02() {
    MyInteger myint;
    cout << myint++ << endl;
    cout << myint << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}