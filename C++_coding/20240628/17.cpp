#include <iostream>
using namespace std;

void swap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "swap01 a = " << a << endl;
    cout << "swap01 b = " << b << endl;
}

void swap02(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    cout << "swap02 a = " << *a << endl;
    cout << "swap02 b = " << *b << endl;
}

int main() {
    //指针和函数
    int a = 10, b = 20;
    //1.值传递
    swap01(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    //2.地址传递
    //可以改变实参的值
    swap02(&a, &b);
    cout << "a = " << a << endl;    
    cout << "b = " << b << endl;

    return 0;
}