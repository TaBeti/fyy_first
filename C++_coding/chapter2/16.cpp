#include <iostream>
using namespace std;

int main() {
    pair<int, int> p1;
    p1 = make_pair(10, 20);
    cout << p1.first << endl;
    cout << p1.second << endl;
}