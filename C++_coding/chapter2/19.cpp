#include <iostream>
using namespace std;

const int N = 20;

int n;
char g[N][N];
int row[N], col[N], dg[N], udg[N];

//按行遍历
// void dfs(int u) {
//     if (u == n) {
//         for (int i = 0; i < n; i++) puts(g[i]);
//         puts("");
//         return;
//     }
//     for (int i = 0; i < n; i++) {
//         if (!col[i] && !dg[u + i] && !udg[n + u - i]) {
//             g[u][i] = 'Q';
//             col[i] = dg[u + i] = udg[n + u - i] = true;
//             dfs(u + 1);
//             col[i] = dg[u + i] = udg[n + u - i] = false;
//             g[u][i] = '.';
//         }
//     }
// }

//按每个格子遍历
void dfs(int x, int y, int s) {
    if (y == n) y = 0, x++;
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; i++) puts(g[i]);
            puts("");
        }
        return;
    }
    //不放皇后
    dfs(x, y + 1, s);
    //放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

//n皇后问题
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0, 0, 0);

    return 0;
}