#include <iostream>
using namespace std;

int main() {
    //赋值运算符
    int a = 10;
    cout << "a=" << a << endl;
    a = 100;
    cout << "a=" << a << endl;
    a = 10;
    a += 2;
    cout << "a=" << a << endl;
    a = 10;
    a -= 2;
    cout << "a=" << a << endl;
    a = 10;
    a *= 2;
    cout << "a=" << a << endl;
    a = 10;
    a /= 2;
    cout << "a=" << a << endl;
    a = 10;
    a %= 2;
    cout << "a=" << a << endl;

    return 0;
}