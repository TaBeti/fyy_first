#include <iostream>
using namespace std;

double n;
const double eps = 1e-6;

int main() {
    cin >> n;
    double l = 0, r = n;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6f", l);
    return 0;
}