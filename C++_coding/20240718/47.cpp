#include <iostream>
#include <list>
using namespace std;

//list反转和排序
void printList(const list<int> &L) {
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int> L1;

    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(40);
    L1.push_back(30);

    cout << "反转前：" << endl;
    printList(L1);

    //反转
    L1.reverse();
    cout << "反转后：" << endl;
    printList(L1);
}

bool myCompare(int v1, int v2) {
    //降序 就让第一个数>第二个数
    return v1 > v2;
}

void test02() {
    list<int> L1;

    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(40);
    L1.push_back(30);

    cout << "排序前：" << endl;
    printList(L1);

    //排序
    // L1.sort();//从小到大
    L1.sort(myCompare);//从大到小
    cout << "排序后：" << endl;
    printList(L1);
}

int main() {
    test01();
    test02();
    return 0;
}