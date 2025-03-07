#include <iostream>
using namespace std;


int main() {
    short num1 = 55555;
    int num2 = 10;
    long num3 = 10;
    long long num4 = 10;

    cout << "short占用的内存空间为" << sizeof(num1) << "字节" << endl;
    cout << "int占用的内存空间为" << sizeof(num2) << "字节" << endl;
    cout << "long占用的内存空间为" << sizeof(num3) << "字节" << endl;
    cout << "long long占用的内存空间为" << sizeof(num4) << "字节" << endl;

    return 0;
}