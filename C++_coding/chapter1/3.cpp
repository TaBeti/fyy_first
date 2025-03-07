#include <iostream>
using namespace std;

//给定一个按照升序排列的长度为n的整数数组，以及m个查询。
//对于每个查询，返回一个元素k的起始位置和终止位置(位置从0开始计数)
//如果数组中不存在该元素，则返回“-1 -1”。

//整数二分
const int N = 1e6 + 10;
int n, m;
int q[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> q[i];
    while (m--) {
        int x;//要找的值
        cin >> x;

        int l = 0, r = n - 1;
        //查找最左位置
        while (l < r) {
            //确定分界点
            int mid = (l + r) / 2;
            //判断
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        //没找到
        if (q[l] != x) cout << "-1 -1" << endl;
        //查找最右位置
        else {
            cout << l << ' ';
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}