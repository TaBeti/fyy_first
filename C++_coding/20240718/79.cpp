#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
using namespace std;

//常用排序算法 random_shuffle
void myPrint(int val) {
    cout << val << " ";
}

void test01() {
    srand((unsigned int)time(NULL));

    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    //打乱顺序
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
}

int main() {
    test01();
    return 0;
}