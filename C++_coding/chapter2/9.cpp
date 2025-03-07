#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], size;

void down(int u) {
    int t = u;//最小值编号
    //判断是否有左子结点，若有则判断当前结点与左子结点的大小
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    //判断是否有右子结点，若有则判断当前结点与右子结点的大小
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        //当前结点不是最小值就进行交换
        swap(h[u], h[t]);
        //进行递归操作
        down(t);
    }
}

void up(int u) {
    //判断是否有父结点，若有则判断当前结点与父结点的大小
    while (u / 2 && h[u / 2] > h[u]) {
        swap(h[u], h[u / 2]);
        u /= 2;
    } 
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    size = n;
    for (int i = n / 2; i; i--) down(i);
    while (m--) {
        cout << h[1] << " ";
        h[1] = h[size];
        size--;
        down(1);
    }
    return 0;
}