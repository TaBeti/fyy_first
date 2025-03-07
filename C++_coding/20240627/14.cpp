#include <iostream>
using namespace std;

int main() {
    //逻辑运算符-非
    int a = 10;
    cout << !a << endl;
    cout << !!a << endl;

    //逻辑运算符-与
    int b = 10;
    cout << (a && b) << endl;
    a = 0;
    cout << (a && b) << endl;
    b = 0;
    cout << (a && b) << endl;

    //逻辑运算符-或
    a = 10;
    b = 10;
    cout << (a || b) << endl;
    a = 0;
    cout << (a || b) << endl;
    b = 0;
    cout << (a || b) << endl;

    return 0;
}