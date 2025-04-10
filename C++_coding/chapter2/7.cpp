#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N];

//返回集合x的编号+路径压缩
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    //初始化只有根节点
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        //集合合并
        if (op[0] == 'M') p[find(a)] = find(b);
        //判断两个元素是否属于同一集合
        else {
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}