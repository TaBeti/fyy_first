#include <iostream>
using namespace std;

int main() {
    //指针所占内存空间
    int a = 10;
    int *p = &a;
    //32位系统下指针占4字节，64位系统下指针占8字节，不管什么数据类型
    cout << "sizeof(int *) = " << sizeof(int *) << endl;
    cout << "sizeof(int *) = " << sizeof(float *) << endl;
    cout << "sizeof(int *) = " << sizeof(double *) << endl;
    cout << "sizeof(int *) = " << sizeof(char *) << endl;
    return 0;
}