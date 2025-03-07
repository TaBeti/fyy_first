#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

//常用的集合算法 set_intersection交集
void myPrint(int val) {
    cout << val << " ";
}

void test01() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;
    //最特殊情况：大容器包含小容器 取小容器的size
    vTarget.resize(min(v1.size(), v2.size()));

    //获取交集
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
    cout << endl;
}

int main() {
    test01();
    return 0;
}