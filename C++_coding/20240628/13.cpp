#include <iostream>
using namespace std;

int main() {
    //空指针：指针变量指向内存地址编号为0的空间
    //1.用于给指针变量进行初始化
    int *p = NULL;

    //2.空指针不能进行访问
    //0-255之间的内存编号是系统占用的，不能直接访问
    *p = 100;//会出现异常

    return 0;
}