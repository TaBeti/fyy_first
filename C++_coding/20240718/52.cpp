#include <iostream>
#include <set>
using namespace std;

//set查找和统计
void test01() {
    //查找
    set<int> s1;

    //插入数据
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end()) {
        cout << "找到元素：" << *pos << endl;
    }
    else {
        cout << "没有找到元素" << endl;
    }
}

//统计
void test02() {
    //查找
    set<int> s1;

    //插入数据
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    //统计元素个数
    //对于set而言，元素个数要么为0，要么为1
    int num = s1.count(30);
    cout << "num = " << num << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}