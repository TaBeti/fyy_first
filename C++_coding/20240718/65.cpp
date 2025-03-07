#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//谓词：返回bool类型的仿函数
//一元谓词：重载参数只有一个
class GeaterFive {
public:
    bool operator()(int val) {
        return val > 5;
    }
};
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //查找容器中有没有大于5的数字
    vector<int>::iterator it = find_if(v.begin(), v.end(), GeaterFive());
    if (it == v.end()) {
        cout << "未找到" << endl;
    }
    else {
        cout << "找到了大于5的数字为：" << *it << endl;
    }
}

int main() {
    test01();
    return 0;
}