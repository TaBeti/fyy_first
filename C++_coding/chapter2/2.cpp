#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int m;
int e[N], l[N], r[N], idx;

//初始化
void init() {
    //0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

//在下标为k的结点右边插入新结点
void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

//删除第k个结点
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}