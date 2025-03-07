#include <iostream>
using namespace std;

//类做友元
class Building {
    friend class GoodGay;
public:
    Building() {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    };
    string m_SittingRoom;
private:
    string m_BedRoom;
};

class GoodGay {
public:
    void visit() {
        cout << "好基友正在访问：" << building->m_SittingRoom << endl;
        cout << "好基友正在访问：" << building->m_BedRoom << endl;
    };
    GoodGay() {
        building = new Building;
    };
    Building *building;
};

void test01() {
    GoodGay gg;
    gg.visit();
}

int main() {
    test01();
    return 0;
}