#include <iostream>
using namespace std;

//1、不要返回局部变量的引用
int& test01() {
    int a = 10;//局部变量存放在栈区
    return a;
}

//2、函数的调用可以作为左值
int& test02() {
    static int a = 10;//静态变量存放在全局区
    return a;
}

int main() {
    //引用做函数返回值
    // int &ref = test01();
    // cout << "ref = " << ref << endl;//异常
    int &ref = test02();
    cout << "ref = " << ref << endl;
    cout << "ref = " << ref << endl;
    test02() = 1000;
    cout << "ref = " << ref << endl;
}