#include <iostream>
using namespace std;

template<typename T> //typename可以替换成class
void mySwap(T &a, T &b) {
    int temp = a;
    a = b;
    b = temp;
}

//函数模板注意事项
//1、自动类型推导，必须推导出一致的数据类型T才可以使用
void test01() {
    int a = 10;
    int b = 20;
    // char b = 'b';//会报错，类型不一致
    mySwap(a, b); //调用函数模板
    cout << "a = " << a << " b = " << b << endl;
}

//2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func() {
    cout << "func函数调用" << endl;
}
void test02() {
    // func();//会报错，因为没指定类型
    func<int>();//不报错
}

int main() {
    test01();
    test02();
    return 0;
}