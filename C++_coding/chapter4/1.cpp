#include <iostream>
using namespace std;

int n, m;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n / i; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> m;
    while (m--) {
        cin >> n;
        if (is_prime(n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}