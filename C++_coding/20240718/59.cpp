#include <iostream>
#include <map>
using namespace std;

//map插入和删除
void printMap(map<int, int> &m) {
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test01() {
    map<int, int> m;

    //插入
    //第一种
    m.insert(pair<int, int>(1, 10));
    //第二种
    m.insert(make_pair(2, 20));
    //第三种
    m.insert(map<int, int>::value_type(3, 30));
    //第四种
    m[4] = 40;//不建议使用

    // cout << m[5] << endl; //输出0，因为不存在key为5的元素

    printMap(m);

    //删除
    //第一种
    m.erase(m.begin());
    printMap(m);
    //第二种 按照key删除
    m.erase(3);
    printMap(m);
    //第三种
    m.erase(m.begin(), m.end());
    printMap(m);

    //清空
    m.clear();
    printMap(m);

}

int main() {
    test01();
    return 0;
}