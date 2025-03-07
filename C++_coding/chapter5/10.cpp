#include <cstring>
#include <iostream>
using namespace std;

const int N = 20, M = 1 << N;

int n;
int w[N][N];
int f[M][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
        // 如果状态 i 中包含点 j（即 i 的二进制位 j 为 1）
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    // 如果从状态 i 中去掉顶点 j 后，状态中包含顶点 k（即 k 是在访问 j 之前访问的顶点）
                    if ((i - (1 << j)) >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}