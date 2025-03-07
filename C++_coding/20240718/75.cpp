#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//常用查找算法 binary search
//注意容器必须是有序序列
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //查找容器中是否有9元素
    bool ret = binary_search(v.begin(), v.end(), 9);
    if (ret) {
        cout << "找到元素9" << endl;
    }
    else {
        cout << "未找到元素9" << endl;
    }
}

int main() {
    test01();
    return 0;
}