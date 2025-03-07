#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N], size[N];

//返回集合x的编号+路径压缩
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    //初始化只有根节点
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        size[i] = 1;
    }

    while (m--) {
        char op[5];
        int a, b;
        cin >> op;

        //集合合并
        if (op[0] == 'C') {
            cin >> a >> b;
            //a,b属于同一个集合就不用执行操作
            if (find(a) == find(b)) continue;
            size[find(b)] += size[find(a)];
            p[find(a)] = find(b);
        }
        //判断两个元素是否属于同一集合
        else if (op[1] == '1'){
            cin >> a >> b;
            if (find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        //输出集合大小
        else {
            cin >> a;
            cout << size[find(a)] << endl;
        }
    }
    return 0;
}