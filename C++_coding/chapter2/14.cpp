#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    // 创建长度为10的vector
    // vector<int> b(10);
    // 创建长度为10，元素值为3的vector
    // vector<int> c(10, 3);
    for (int i = 0; i < 10; i++) a.push_back(i);
    cout << a.size() << endl;
    cout << a.empty() << endl;
    for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
    cout << endl;
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
        cout << *i << ' ';
    cout << endl;
    for (auto x : a) cout << x << ' ';
    cout << endl;
    return 0;
}