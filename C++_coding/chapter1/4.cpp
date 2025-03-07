#include <iostream>
using namespace std;

//求平方根
int main() {
    double x;//要查找的值
    cin >> x;

    //浮点二分
    double l = 0, r = x;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid >= x) r = mid;
        else l = mid;
    }
    cout << l << endl;

    return 0;
}