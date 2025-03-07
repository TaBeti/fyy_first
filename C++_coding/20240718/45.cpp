#include <iostream>
#include <list>
using namespace std;

//list插入和删除
void printList(const list<int> &L) {
    for(list<int>::const_iterator it = L.begin(); it!= L.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int> L1;

    //尾插
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //头插
    L1.push_front(1000);
    L1.push_front(2000);
    L1.push_front(3000);

    printList(L1);

    //尾删
    L1.pop_back();
    printList(L1);

    //头删
    L1.pop_front();
    printList(L1);

    //insert插入
    L1.insert(L1.begin(), 100);
    printList(L1);

    //删除
    L1.erase(++L1.begin());
    printList(L1);

    //移除
    L1.remove(1000);
    printList(L1);

    //清空
    L1.clear();
    printList(L1);
}

int main() {
    test01();
    return 0;
}