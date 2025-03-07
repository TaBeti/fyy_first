#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 3e6 + 10;

int n, m;
int a[N], s[N];

vector<int> alls; // 记录用到的坐标(所以要进行去重和排序)
vector<PII> add, query;


//二分求出x对应的离散化的值
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main() {
    cin >> n >> m;
    //在x位置的数+c
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    //unique算法原理
    // vector<int>::iterator unique(vector<int> &a) {
    //     int j = 0;
    //     for (int i = 0; i < a.size(); i++) {
    //         if (!i || a[i] != a[i - 1]) a[j++] = a[i];
    //     }
    //     // a[0]~a[j-1]所有a中不重复的数
    //     return a.begin() + j;
    // }

    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //处理插入
    for (auto item: add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    //预处理前缀和
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    //处理询问
    for (auto item: query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}