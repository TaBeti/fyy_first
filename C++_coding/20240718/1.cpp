#include <iostream>
using namespace std;

//函数模板

//两个整数交换
void SwapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//两个小数交换
void SwapDouble(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

//上述两个交换的逻辑都很类似，可以使用模板
template<typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 10;
    int b = 20;
    // SwapInt(a, b);
    //两种方式使用函数模板
    //1、自动类型推导
    // Swap(a, b);
    //2、显示指定类型
    Swap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    double c = 1.1;
    double d = 2.2;
    // SwapDouble(c, d);
    // cout << "c = " << c << endl;
    // cout << "d = " << d << endl;

    return 0;
}