#include <iostream>
using namespace std;

void showValue(const int &val) {
    //const用来修饰形参，防止误操作
    // val = 1000;//会报错
    cout << "val = " << val << endl;
}

int main() {
    //常量引用
    //用来修饰形参，防止误操作
    // int a = 10;
    // int &ref = 10; //错误，引用必须引一块合法的内存空间
    // //加上const之后，编译器将代码修改为int temp = 10; const int &ref = temp;
    // const int &ref = 10;//正确
    // ref = 20;//加入const之后变为可读，不可修改

    int a = 100;
    showValue(a);
    return 0;
}