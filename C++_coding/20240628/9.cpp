#include <iostream>
using namespace std;

//函数声明
//声明可以多次，定义只能一次
int max(int a, int b);

int main() {
    int a = 10;
    int b = 20;
    cout << max(a, b) << endl;

    return 0;
}

//函数定义
int max(int a, int b){
    return a > b ? a : b;
}