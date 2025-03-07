#include <iostream>
using namespace std;

int main() {
    int scores[3][3] = {{100, 100, 100}, 
                        {90, 50, 100},
                        {60, 70, 80}};
    string names[3] = {"张三", "李四", "王五"};
    // int a = 0;
    // int b = 0;
    // int c = 0;
    // for (int i = 0; i < 3; i++) {
    //     a += scores[0][i];
    //     b += scores[1][i];
    //     c += scores[2][i];
    // }
    // cout << "张三总分为：" << a << endl;
    // cout << "李四总分为：" << b << endl;
    // cout << "王五总分为：" << c << endl;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += scores[i][j];
        }
        cout << names[i] << "的总分为：" << sum << endl;
    }
    return 0;
}