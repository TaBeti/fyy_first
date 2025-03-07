#include <iostream>
using namespace std;

//判断点和圆的关系
class Point {
public:
    void setX(int x) {
        m_x = x;
    }
    int getX() {
        return m_x;
    }
    void setY(int y) {
        m_y = y;
    }
    int getY() {
        return m_y;
    }
private:
    int m_x;
    int m_y;
};

class Circle {
public:
    void setR(int r) {
        m_r = r;
    }
    int getR() {
        return m_r;
    }
    void setCenter(Point center) {
        m_center = center;
    }
    Point getCenter() {
        return m_center;
    }

private:
    int m_r;//半径
    //在类中可以使用领一个类作为成员变量
    Point m_center;//圆心

};

void isInside(Circle &c, Point &p) {
    int distance = (c.getCenter().getX() - p.getX()) * 
    (c.getCenter().getX() - p.getX())  + (c.getCenter().getY() - p.getY()) 
    * (c.getCenter().getY() - p.getY());
    int rDistance = c.getR() * c.getR();
    if (distance == rDistance) {
        cout << "点在圆上" << endl;
    }
    else if (distance > rDistance) {
        cout << "点在圆外" << endl;
    }
    else {
        cout << "点在圆内" << endl;
    }
}

int main() {
    //创建圆
    Circle c;
    c.setR(5);
    Point center;
    center.setX(10);
    center.setY(10);
    c.setCenter(center);

    //创建点
    Point p;
    p.setX(10);
    p.setY(9);

    //判断点和圆的关系
    isInside(c, p);

    return 0;
}