#include <iostream>
using namespace std;

//Acwing 786
const int N = 1e6 + 10;
int n, k;
int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> q[i];
    quick_sort(q, 0, n - 1);
    cout << q[k - 1] << endl;
    return 0;
}