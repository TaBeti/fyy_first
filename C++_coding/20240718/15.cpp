#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//回调函数
void myPrint(int val) {
    cout << val << endl;
}

//vector容器存放内置数据类型
void test01() {
    //创建了一个vector容器（数组）
    vector<int> v;
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //通过迭代器访问容器中的数据
    // vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
    // vector<int>::iterator itEnd = v.end();//终止迭代器，指向容器中最后一个元素的下一位置
    // //第一种遍历方式
    // while (itBegin != itEnd) {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    //第二种遍历方式
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    //     cout << *it << endl;
    // }

    //第三种遍历方式
    for_each(v.begin(), v.end(), myPrint);
}

int main() {
    test01();
    return 0;
}