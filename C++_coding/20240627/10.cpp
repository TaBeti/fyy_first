#include <iostream>
using namespace std;

int main() {
    //算术运算符2
    int a1 = 10;
    int b1 = 3;

    cout << a1 % b1 << endl;

    //两个小数不能做取模运算
    double a2 = 10.5;
    double b2 = 3.2;
    // cout << a2 % b2 << endl;//报错

    return 0;
}