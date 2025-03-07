#include <iostream>
using namespace std;

int lowbit(int x) {
    return x & -x;
}

//计算每个数二进制表示中1的个数
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        int res = 0;
        while (x) x -= lowbit(x), res++;//每次减去x的最后一位1

        cout << res << ' ';
    }
    return 0;
}