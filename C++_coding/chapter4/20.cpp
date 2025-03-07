#include <iostream>
using namespace std;

typedef long long LL;

const int N = 20;

int n, m;
int p[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> p[i];

    int res = 0;
    for (int i = 1; i < 1 << m; i++) {
        //t表示当前所有质数的乘积，cnt表示i的二进制1的个数
        int t = 1, cnt= 0;
        for (int j = 0; j < m; j++)
            if (i >> j & 1) {
                cnt++;
                if ((LL)t * p[j] > n) {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        //奇数个集合应该加上，偶数个集合应该减去
        if (t != -1) {
            if (cnt % 2) res += n / t;
            else res -= n / t;
        }
    }
    cout << res << endl;
    return 0;
}