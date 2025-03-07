#include <iostream>
using namespace std;

//友元
class Building {
    //全局函数做友元
    friend void goodgay(Building *building);
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
public:
    Building() {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
};

//全局函数
void goodgay(Building *building) {
    cout << "好基友正在访问：" << building->m_SittingRoom << endl;
    cout << "好基友正在访问：" << building->m_BedRoom << endl;
}

void test01() {
    Building building;
    goodgay(&building);
}

int main() {
    test01();
    return 0;
}