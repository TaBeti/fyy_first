#include <iostream>
using namespace std;

int main() {
    //数组名用途
    //1.可以通过数组名统计整个数组占用内存大小
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "整个数组占用内存空间为：" << sizeof(arr) << endl;
    cout << "每个元素占用内存空间为：" << sizeof(arr[0]) << endl;
    cout << "数组中的元素个数为：" << sizeof(arr) / sizeof(arr[0]) << endl;

    //2.可以通过数组名查看元素首地址
    cout << "数组首地址为：" << arr << endl;
    // cout << "数组首地址为：" << (long*)arr << endl;
    cout << "数组首地址为：" << &arr[0] << endl;
    // cout << "数组首地址为：" << (int*)&arr[0] << endl;

    // arr = 10;//数组名是常量，不能赋值

    return 0;
}