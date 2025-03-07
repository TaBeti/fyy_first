#include <iostream>
using namespace std;

class Cube {
    //设计属性
private:
    int m_l;
    int m_w;
    int m_h;
    //设计行为，获取立方体面积和体积
public:
    void setL(int l) {
        m_l = l;
    }
    int getL() {
        return m_l;
    }
    void setW(int w) {
        m_w = w;
    }
    int getW() {
        return m_w;
    }
    void setH(int h) {
        m_h = h;
    }
    int getH() {
        return m_h;
    }
    //获取立方体面积
    int calculateArea() {
        return 2 * (m_l * m_w + m_w * m_h + m_h * m_l);
    }
    //获取立方体体积
    int calculateVolume() {
        return m_l * m_w * m_h;
    }
    //分别利用全局函数和成员函数，判断两个立方体是否相等
    bool isSameByClass(Cube &c) {
        if (m_l == c.getL() && m_w == c.getW() && m_h == c.getH()) {
            return true;
        }
        return false;
    }

};

bool isSame(Cube &c1, Cube &c2) {
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
        return true;
    }
    return false;
}

int main() {
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);
    cout << "c1的面积为：" << c1.calculateArea() << endl;
    cout << "c1的体积为：" << c1.calculateVolume() << endl;

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);
    
    //利用全局函数判断
    bool ret = isSame(c1, c2);
    if (ret) {
        cout << "c1和c2相等" << endl;
    }
    else {
        cout << "c1和c2不相等" << endl;
    }

    //利用成员函数判断
    ret = c1.isSameByClass(c2);
    if (ret) {
        cout << "c1和c2相等" << endl;
    }
    else {
        cout << "c1和c2不相等" << endl;
    }

    return 0;
}