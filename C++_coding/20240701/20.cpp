#include <iostream>
using namespace std;

class Building;

class GoodGay {
public:
    GoodGay() ;
    void visit();//访问Building中私有成员
    void visit2();//不可以访问Building中私有成员
    Building *building;
};

//成员函数做友元
class Building {
    friend void GoodGay::visit();
public:
    Building() {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    };
    string m_SittingRoom;
private:
    string m_BedRoom;
};

//类外实现成员函数
GoodGay::GoodGay() {
    building = new Building;
}

void GoodGay::visit() {
    cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
    cout << "visit函数正在访问：" << building->m_BedRoom << endl;
}

void GoodGay::visit2() {
    cout << "visit2函数正在访问：" << building->m_SittingRoom << endl;
    // cout << "visit2函数正在访问：" << building->m_BedRoom << endl;
}

void test01() {
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main() {
    test01();
    return 0;
}