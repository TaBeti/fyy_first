#include <iostream>
using namespace std;

//函数重载满足条件
//1、同一个作用域下
//2、函数名相同
//3、参数不同、顺序不同
void func() {
    cout << "func的调用" << endl;
}

void func(int a) {
    cout << "func的调用" << endl;
}

//函数返回值不可以作为重载条件
int func(int a) {
    cout << "func的调用" << endl;
}

int main() {
    //函数重载
    func();
    func(1);
    return 0;
}