#include <iostream>
#include <set>
using namespace std;

//set构造和赋值
void printSet(set<int> &s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int> s1;

    //插入数据只有insert
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30);

    //set容器特点：所有元素插入时自动被排序
    //set容器不允许插入重复值
    printSet(s1);

    //拷贝构造
    set<int> s2(s1);
    printSet(s2);

    //赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);
}

int main() {
    test01();
    return 0;
}