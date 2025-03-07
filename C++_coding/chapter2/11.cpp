#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;

void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    //将数组所有元素初始化为-1
    memset(h, -1, sizeof(h));

    while (n--) {
        char op[2];
        int x;
        cin >> op >> x;
        if (*op == 'I') insert(x);
        else {
            if (find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}