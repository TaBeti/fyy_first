#include <iostream>
using namespace std;

void swap(int num1, int num2) {
    cout << "交换前：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "交换后：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    //return;
}

int main() {
    //值传递：形参改变，实参不变
    int a = 10;
    int b = 20;
    cout << "交换前：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(a, b);
    cout << "交换后：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}