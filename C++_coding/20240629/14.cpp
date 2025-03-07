#include <iostream>
using namespace std;

//设计一个圆类，求圆的周长
const double PI = 3.14;
class Circle {
    //访问权限
public: 
    int m_r;//半径
    //行为
    //获取圆的周长
    double calculateZC() {
        return 2 * PI * m_r;
    }
};

int main() {
    //创建对象
    Circle c1;
    c1.m_r = 10;
    cout << "圆的周长为：" << c1.calculateZC() << endl;
    return 0;
}