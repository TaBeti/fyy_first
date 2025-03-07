#include <iostream>
using namespace std;

int main() {
    int score = 0;
    cout << "请输入分数：" << endl;
    cin >> score;
    cout << "你输入的分数是：" << score << endl;
    if (score > 600) {
        cout << "恭喜您考上了一本大学" << endl;
        if (score > 700) {
            cout << "您能考上清华" << endl;
        }
        else if (score > 650) {
            cout << "您能考上北大" << endl;
        }
        else {
            cout << "您能考上人大" << endl;
        }
    }
    else if (score > 500) {
        cout << "恭喜您考上了二本大学" << endl;
    }
    else if (score > 400) {
        cout << "恭喜您考上了三本大学" << endl;
    }
    else {
        cout << "很遗憾，您没有考上本科大学" << endl;
    }
}