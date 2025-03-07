#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
// int f[N][N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    // for (int i = 1; i <= n; i++)
    //     for (int j = 0; j <= m; j++) {
    //         f[i][j] = f[i - 1][j];
    //         if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
    //     }
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--) {
            //优化前：f[i][j] = f[i - 1][j];
            //优化后：f[j] = f[j];   恒成立可省略
            if (j >= v[i]) 
                //优化前：f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
                //优化后
                f[j] = max(f[j], f[j - v[i]] + w[i]);
    }

    // cout << f[n][m] << endl;
    cout << f[m] << endl;
    return 0;
}