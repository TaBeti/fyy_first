#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 3, null = 0x3f3f3f3f;

int h[N];

int find(int x) {
    int k = (x % N + N) % N;
    //从k开始搜索，直到找到x或到达数组末尾
    while (h[k] != null && h[k] != x) {
        k++;
        //若没找到，则从数组开头开始找
        if (k == N) k = 0;
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    memset(h, 0x3f, sizeof h);

    while (n--) {
        char op[2];
        int x;
        cin >> op >> x;

        int k = find(x);
        if (*op == 'I') h[k] = x;
        else {
            if (h[k] != null) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}