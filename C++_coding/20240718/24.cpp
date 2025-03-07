#include <iostream>
using namespace std;

//字符串插入和删除
// string& insert(int pos, const char* s); //插入字符串
// string& insert(int pos, const string& str); //插入字符串
// string& insert(int pos, int n, char c); //在指定位置插入n个字符c
// string& erase(int pos, int n = npos); //删除从Pos开始的n个字符

void test01() {
    string str = "hello";

    //插入
    str.insert(1, "111");//在第1个位置插入111
    cout << "str = " << str << endl;

    //删除
    str.erase(1, 3);//删除第1个位置开始的3个字符
    cout << "str = " << str << endl;
}

int main() {
    test01();
    return 0;
}