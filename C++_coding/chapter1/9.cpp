#include <iostream>
using namespace std;

// 输入一个长度为n的整数序列。
// 接下来再输入m个询问，每个询问输入一对l, r。
// 对于每个询问，输出原序列中从第l个数到第r个数的和。

const int N = 1e6 + 10;
int n, m;
int a[N], s[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //一维前缀和
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}