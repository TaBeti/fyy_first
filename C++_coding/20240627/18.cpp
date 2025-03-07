#include <iostream>
using namespace std;

int main() {
    cout << "请给电影进行打分" << endl;
    int score = 0;
    cin >> score;
    cout << "您的评分为：" << score << endl;
    switch (score) {
        case 10: 
            cout << "您认为是经典电影" << endl;
            break;
        case 9: 
            cout << "您认为是经典电影" << endl;
            break;
        case 8: 
            cout << "您认为电影非常好" << endl;
            break;
        case 7: 
            cout << "您认为电影非常好" << endl;
            break;
        case 6: 
            cout << "您认为定影一般" << endl;
            break;
        case 5: 
            cout << "您认为电影一般" << endl;
            break;
        default: 
            cout << "您认为这是烂片" << endl;
            break;
    }

    return 0;
}