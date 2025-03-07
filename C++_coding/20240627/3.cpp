#include <iostream>
using namespace std;

int main() {
    //浮点型
    //默认情况下，输出一个小数会显示六位有效数字
    //1.单精度float
    float f1 = 3.1415926f;
    cout << "f1=" << f1 << endl;

    //2.双精度double
    double d1 = 3.1415926;
    cout << "d1=" << d1 << endl;

    //占用空间
    cout << "float占用内存空间" << sizeof(f1) << endl;
    cout << "double占用内存空间" << sizeof(d1) << endl;

    //科学计数法
    float f2 = 3e2; //3 * 10 ^ 2
    cout << "f2=" << f2 << endl;
    float f3 = 3e-2; //3 * 10 ^ -2
    cout << "f3=" << f3 << endl;

    return 0;
}