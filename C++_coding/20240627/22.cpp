#include <iostream>
using namespace std;

int main() {
    //水仙花数
    int num = 100;
    do {
        int a = num / 100; //百位
        int b = num / 10 % 10;//十位
        int c = num % 10;//个位
        if (a * a * a + b * b * b + c * c * c == num) {
            cout << num << " ";
        }
        num++;
    } while (num < 1000);
    return 0;
}