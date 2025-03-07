#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N];

//快速排序
void quicksort(int q[], int l, int r) {
    if (l >= r) return;
    //确定边界点
    int x = q[l], i = l - 1, j = r + 1;
    //调整区间
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    //递归左右两边
    quicksort(q, l, j);
    quicksort(q, j + 1, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    quicksort(q, 0, n - 1);
    for (int i = 0; i < n; i++) cout << q[i] << " ";
    return 0;
}