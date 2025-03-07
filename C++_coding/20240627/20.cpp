#include <iostream>
using namespace std;
#include <ctime>

int main() {
    //添加随机数种子
    srand((unsigned int)time(NULL));
    //1.系统生成随机数
    int num = rand() % 100 + 1;//生成1~100之间的随机整数
    // cout << "随机数：" << num << endl;

    //2.玩家进行猜测
    int val = 0;
    while (1) {
        cin >> val;
        if (val > num) {
            cout << "猜大了" << endl;
        }
        else if (val < num) {
            cout << "猜小了" << endl;
        }
        else {
            cout << "猜对了" << endl;
            break;
        }
    }
    
    return 0;
}