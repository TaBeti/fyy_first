#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n, m, x;
int a[N], b[N];

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] + b[j] == x) {
                cout << i << " " << j << endl;
                break;
            }
        }
    }
    return 0;
}