#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 1000;
typedef pair<int, int> PII;

int n = 16;              // 本例固定点的数量为 16
int h[N], w[N], e[N], ne[N], idx;  // 邻接表
int dist[N];             // dist[i] 表示 1 号点到 i 号点的最短距离
bool st[N];              // 标记某个点的最短距离是否已经确定
int pre[N];              // 用于存储路径中的前驱节点

// 向邻接表中插入一条边 a -> b，权重为 c
void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

// Dijkstra 求最短路径
int dijkstra(int start, int end) {
    // 初始化 dist[]，pre[]，以及 st[]
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    for (int i = 1; i <= n; i++) {
        pre[i] = -1; // 前驱节点初始置为 -1
    }

    // 起点距离为 0
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // 距离 + 节点编号
    heap.push({0, start});

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver]) continue;  // 如果该节点的最短路已经确定，跳过
        st[ver] = true;

        // 用 ver 的距离去更新它的所有邻居
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                pre[j] = ver;  // 记录 j 的前驱是 ver
                heap.push({dist[j], j});
            }
        }
    }

    // 如果 end 不可达，返回 -1
    if (dist[end] == 0x3f3f3f3f) return -1;
    return dist[end];
}

// 打印从 start 到 end 的最短路径
void printPath(int start, int end) {
    // 如果没有路径，直接返回
    if (dist[end] == 0x3f3f3f3f) {
        cout << "No path found!" << endl;
        return;
    }

    // 回溯路径
    vector<int> path;
    for (int i = end; i != -1; i = pre[i]) {
        path.push_back(i);
    }
    // 由于是从 end 回溯到 start，顺序相反，需反转
    reverse(path.begin(), path.end());

    // 输出路径
    cout << "Shortest path: ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 < (int)path.size()) cout << " -> ";
    }
    cout << endl;
}

int main() {
    // 初始化邻接表的头指针
    memset(h, -1, sizeof h);

    // 根据题意：从上到下、从左到右编号，小明为1，爷爷为16
    // 以下是无向图还是有向图需根据实际要求，如果是双向道路，则需要 add(a, b, c) 和 add(b, a, c)
    // 下面看上去更像是有向图示例，如果需要双向请自行添加反向边
    add(1, 2, 5);   add(1, 3, 3);
    add(2, 4, 1);   add(2, 5, 3);   add(2, 6, 6);
    add(3, 5, 8);   add(3, 6, 7);   add(3, 7, 6);
    add(4, 8, 6);   add(4, 9, 8);
    add(5, 8, 3);   add(5, 9, 5);
    add(6, 9, 3);   add(6, 10, 3);
    add(7, 9, 8);   add(7, 10, 4);
    add(8, 11, 2);  add(8, 12, 2);
    add(9, 12, 1);  add(9, 13, 2);
    add(10, 12, 3); add(10, 13, 3);
    add(11, 14, 3); add(11, 15, 5);
    add(12, 14, 5); add(12, 15, 2);
    add(13, 14, 6); add(13, 15, 6);
    add(14, 16, 4); add(15, 16, 3);

    // 求 1 号点到 16 号点的最短距离
    int res = dijkstra(1, 16);

    // 输出最短距离
    cout << "Shortest distance from 1 to 16: " << res << endl;

    // 如果最短距离存在，则打印最短路径
    if (res != -1) {
        printPath(1, 16);
    }

    return 0;
}