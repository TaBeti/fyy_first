#include <iostream>
using namespace std;

int main() {
    //字符型
    //1.字符型变量创建方式
    char ch = 'a';  //以ASCII码形式存储字符'a'
    cout << ch << endl;
    cout << int(ch) << endl;

    //2.字符型变量所占内存大小
    cout << "char型变量所占内存大小:" << sizeof(ch) << endl;
    cout << sizeof(int(ch)) << endl;

    //char ch1 = "b"; //错误，不能将字符串赋值给char型变量

    return 0;
}