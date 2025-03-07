#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], tmp[N];
long long res = 0;

//Acwing 788
void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] < q[j]) tmp[k++] = q[i++];
        else {
            tmp[k++] = q[j++];
            res += mid - i + 1;
        } 
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    merge_sort(q, 0, n - 1);
    cout << res << endl;
    return 0;
}