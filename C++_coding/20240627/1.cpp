#include <iostream>
using namespace std;

int main() {
    //整型
    //1.短整型(-32768~32767)
    short num1 = 55555;

    //2.整型(-2147483648~2147483647)
    int num2 = 10;

    //3.长整型(-9223372036854775808~9223372036854775807)
    long num3 = 10;

    //4.长长整型(-18446744073709551616~18446744073709551615)
    long long num4 = 10;

    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;
    cout << "num3=" << num3 << endl;
    cout << "num4=" << num4 << endl;

    return 0;
}