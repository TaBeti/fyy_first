#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N;//记录最小的各个连通块中点数的最大值

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//以u为根的子树中点的数量
int dfs(int u) {
    st[u] = true;//标记，已经被搜过了
    //sum=1是因为加上去掉的那个数
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            res = max(res, s);//求子节点中点数最大的
            sum += s;////求以j为头节点的子节点的点数之和
        }
    }

    res = max(res, n - sum);////求头节点所在连通块和其子节点最大的点数中最大的值
    ans = min(ans, res);//求我们每一种情况中，最小的值
    return sum;
}

//深度优先遍历
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}