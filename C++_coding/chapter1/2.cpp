#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], tmp[N];

//归并排序
void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    //确定分界点
    int mid = (l + r) / 2;
    //递归排序左右两边
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    //使用双指针归并
    //使用tmp数组存储两个指针指向的元素中较小的元素
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    //将比较完剩余元素复制到tmp数组
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    //将tmp数组中的元素复制回原数组
    for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j]; 
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) cout << q[i] << " ";
    return 0;
}