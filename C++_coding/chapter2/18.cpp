#include <iostream>
using namespace std;

const int N = 10;
int path[N];
bool st[N];
int n;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) cout << path[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

//全排列
int main() {
    cin >> n;
    dfs(0);
    return 0;
}