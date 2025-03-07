#include <iostream>
using namespace std;

int main(){
    //continue语句：跳过后面的语句，直接进入下一次循环
    for (int i = 0; i <= 100; i++) {
        //如果是奇数输出，偶数不输出
        if (i % 2 == 0) {
            continue;
        }
        cout << i << endl;
    }
    return 0;
}