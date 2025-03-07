#include <iostream>
using namespace std;

int main() {
    //break语句
    //1.用在switch语句中
    // cout << "请选择您挑战副本的强度" << endl;
    // cout << "1.简单" << endl;
    // cout << "2.中等" << endl;    
    // cout << "3.困难" << endl;

    // int select = 0;
    // cin >> select;
    // switch (select) {
    //     case 1:
    //         cout << "您选择了简单副本" << endl;
    //         break;
    //     case 2:
    //         cout << "您选择了中等副本" << endl;
    //         break;
    //     case 3:
    //         cout << "您选择了困难副本" << endl;
    //         break;
    //     default:
    //         break;
    // }

    //2.用在循环语句中
    // for (int i = 0; i < 10; i++) {
    //     if (i == 5) {
    //         break;
    //     }
    //     cout << i << endl;
    // }

    //3.用在嵌套循环语句中
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 5) {
                break;
            }
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}