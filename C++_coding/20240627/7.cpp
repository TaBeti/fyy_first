#include <iostream>
using namespace std;

int main() {
    //布尔类型
    bool flag = true;
    cout << "flag = " << flag << endl;
    flag = false;
    cout << "flag = " << flag << endl;

    //占用空间
    cout << "bool类型占用内存空间" << sizeof(bool) << endl;

    return 0;
}