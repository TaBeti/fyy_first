#include <iostream>
#include <vector>
using namespace std;

//判断是否有A>=B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    //从高位开始比较
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}

//高精度减法
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;//借位
    //模拟两个数相减（列竖式）
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        //判断是否借位
        if (t < 0) t = 1;
        else t = 0;
    }
    //去除前导0（如答案003需要转为3）
    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {
    //用字符串存储两个高精度数
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for (int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size()-1; i >= 0; i--) cout << C[i];
    }
    else {
        auto C = sub(B, A);
        cout << "-";
        for (int i = C.size()-1; i >= 0; i--) cout << C[i];
    }

    return 0;
}