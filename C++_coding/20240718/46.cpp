#include <iostream>
#include <list>
using namespace std;

//list数据存取
void test01() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //list本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的
    cout << "第一个元素为：" << L1.front() << endl;
    cout << "最后一个元素为：" << L1.back() << endl;

    list<int>::iterator it = L1.begin();
    it++;
    it--;
    // it = it + 1;//报错
}

int main() {
    test01();
    return 0;
}