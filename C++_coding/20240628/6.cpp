#include <iostream>
using namespace std;

int add(int num1, int num2) {//形参
    int sum = num1 + num2;
    return sum;
}

int main() {
    //函数
    int a = 10;
    int b = 20;
    int sum = add(a, b);//实参
    cout << "sum=" << sum << endl;
    return 0;
}