#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 10010;
int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    LL res = 0;
    for (int i = 0; i < n; i++) res += abs(a[i] - a[n / 2]);
    cout << res << endl;
    return 0;
}