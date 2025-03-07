#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m = 0;
int h[N], size;
//ph[i]表示第i个插入的结点的下标，hp[i]表示堆中第i个结点是第几个插入的
//这两个数组互为反函数：ph[j]=k, hp[k]=j
int ph[N], hp[N];

void heat_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;//最小值编号
    //判断是否有左子结点，若有则判断当前结点与左子结点的大小
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    //判断是否有右子结点，若有则判断当前结点与右子结点的大小
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        //当前结点不是最小值就进行交换
        heat_swap(u, t);
        //进行递归操作
        down(t);
    }
}

void up(int u) {
    //判断是否有父结点，若有则判断当前结点与父结点的大小
    while (u / 2 && h[u / 2] > h[u]) {
        heat_swap(u, u / 2);
        u /= 2;
    } 
}

int main() {
    cin >> n;
    
    while (n--) {
        string op;
        int k, x;
        cin >> op;
        //插入一个数x
        if (op == "I") {
            cin >> x;
            size++;
            m++;
            ph[m] = size, hp[size] = m;
            h[size] = x;
            up(size);
        }
        //输出当前集合中的最小值
        else if (op == "PM") cout << h[1] << endl;
        //删除当前集合中的最小值
        else if (op == "DM") {
            heat_swap(1, size);
            size--;
            down(1);
        }
        //删除第k个插入的数
        else if (op == "D") {
            cin >> k;
            k = ph[k];
            heat_swap(k, size);
            size--;
            down(k), up(k);
        }
        //修改第k个插入的数的值为x
        else {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}