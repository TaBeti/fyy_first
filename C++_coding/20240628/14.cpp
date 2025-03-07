#include <iostream>
using namespace std;

int main() {
    //野指针：指向没有申请的地址空间的指针
    int *p = (int *)0x1100;
    cout << *p << endl;

    return 0;
}