#include <iostream>
#include <vector>
using namespace std;

//高精度加法
vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;//进位
    //模拟两个数相加（列竖式）
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    //判断高位是否有进位，若有，则在最高位加1
    if(t) C.push_back(1);
    return C;
}

int main() {
    //用字符串存储两个高精度数
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for (int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

    auto C = add(A, B);
    for (int i = C.size()-1; i >= 0; i--) cout << C[i];
    return 0;
}