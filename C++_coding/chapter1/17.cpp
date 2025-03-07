#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n;
vector<PII> segs;

void merge(vector<PII>& segs) {
    vector<PII> res;

    //按区间的左端点排序
    sort(segs.begin(), segs.end());

    //维护区间
    int st = -2e9, ed = -2e9;
    for (auto seg: segs) {
        //第三种情况：左端点>当前维护区间右端点，作为一个单独区间加入结果
        if (ed < seg.first) {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        //合并区间
        else ed = max(ed, seg.second);
    }
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
}