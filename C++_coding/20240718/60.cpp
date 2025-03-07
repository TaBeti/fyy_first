#include <iostream>
#include <map>
using namespace std;

//map查找和统计
void test01() {
    //查找
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    map<int, int>::iterator pos =  m.find(4);
    if (pos != m.end()) {
        cout << "查到了元素key = " << pos->first << " value = " << pos->second << endl;
    }
    else {
        cout << "未找到元素" << endl;
    }

    //统计
    //map的计数结果要么是0，要么是1
    //multimap的结果可能大于1
    int num = m.count(3);
    cout << "num = " << num << endl;
}


int main() {
    test01();
    // test02();
    return 0;
}