#include <iostream>
using namespace std;

//string的构造函数

void test01() {
    string s1;//默认构造

    //使用字符串s初始化
    const char* str = "hello world";
    string s2(str);
    cout << "s2 = " << s2 << endl;

    //使用一个string对象初始化另一个string对象
    string s3(s2);
    cout << "s3 = " << s3 << endl;

    //使用n个字符c初始化
    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;
}

int main() {
    test01();
    return 0;
}