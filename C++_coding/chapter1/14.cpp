#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                bool flag = true;
                for ()
            }
        }
    }
    return 0;
}