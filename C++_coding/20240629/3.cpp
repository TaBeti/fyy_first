#include <iostream>
using namespace std;

int* func() {
    //在堆区创建整型数据
    //new返回的是该数据类型的指针
    int *p = new int(10);
    return p;
}

void test01() {
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    delete p; //释放内存
    cout << *p << endl;//异常
}

//2、在堆区开辟数组
void test02() {
    int *arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 100;
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
    //释放堆区数组
    delete[] arr;//释放数组要加[]
}

int main() {

    test01();
    test02();

    return 0;
}