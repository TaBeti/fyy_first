#include <iostream>
using namespace std;

//交换函数
//1、值传递
void swap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
//2、地址传递
void swap02(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//3、引用传递
void swap03(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 10;
    int b = 20;
    // swap01(a, b);//值传递，形参不会改变实参的值
    // swap02(&a, &b);//地址传递，形参会改变实参的值
    swap03(a, b);//引用传递，形参也会改变实参的值
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}