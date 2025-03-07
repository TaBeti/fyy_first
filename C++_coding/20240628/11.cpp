#include <iostream>
using namespace std;

int main() {
    //指针：间接访问内存，指针就是一个地址
    //1.定义指针
    int a = 10;
    int *p;
    p = &a;
    cout << "a的地址为：" << &a << endl;
    cout << "指针p为：" << p << endl;

    //2.使用指针
    // 指针前加*表示解引用，找到指针指向的内存中的数据
    *p = 20;
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;

    return 0;
}