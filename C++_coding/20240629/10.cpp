#include <iostream>
using namespace std;

int func(int a, int b = 20, int c = 30) {
    return a + b + c;
}

//1、注意某个位置已经有了默认参数，后面的参数必须都有默认参数
// int fun2(int a, int b = 20, int c = 30, int d) {
// //这是错误的
// return a + b + c + d;
// }

//2、如果函数声明有默认参数，函数实现就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
    return a + b;
}

int main() {
    //函数形参可以有默认参数
    cout << func2() << endl; 
    return 0;
}