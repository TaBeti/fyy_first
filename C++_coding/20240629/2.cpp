#include <iostream>
using namespace std;

// int* func() {//形参数据也会放在栈区
//     int* a = 10;//局部变量存放在栈区，栈区的数据在函数执行完后自动释放
//     return &a;
// }

int *func() {
    //利用new关键字，可以将数据开辟到堆区
    //指针本质也是局部变量，放在栈上，指针保存的数据是放在堆区
    int *p = new int(10);
    cout << "p = " << p << endl;
    return p;
}

int main() {
    /*程序运行后
    栈区:
    由编译器自动分配释放,存放函数的参数值,局部变量等
    注意事项:不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
    堆区:
    由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
    在C++中主要利用new在堆区开辟内存
    */

    // int *p = func();
    // cout << *p << endl; //出现异常

    int *p = func();
    cout << *p << endl;

    return 0;
}