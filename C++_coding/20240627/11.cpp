#include <iostream>
using namespace std;

int main() {
    //算术运算符3
    //1.前置递增
    int a = 10;
    ++a;
    cout << "a=" << a << endl;

    //2.后置递增
    int b = 10;
    b++;
    cout << "b=" << b << endl;

    //前置递增先让变量+1，然后再进行计算
    //后置递增先进行计算，然后让变量+1
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << "a2=" << a2 << endl;
    cout << "b2=" << b2 << endl;

    int a3 = 10;
    int b3 = a3++ * 10;
    cout << "a3=" << a3 << endl;
    cout << "b3=" << b3 << endl;

    return 0;
}