#include <iostream>
using namespace std;

//菱形继承
//动物类
class Animal {
public:
    int m_Age;
};

//利用虚继承解决菱形继承的问题，此时Animal叫虚基类
//虚继承实际上使用的是虚基类指针vbptr，其指向虚基类表vbtable
//羊类
class Sheep: virtual public Animal {

};

//驼类
class Tuo: virtual public Animal {

};

//羊驼类
class SheepTuo: public Sheep, public Tuo {

};

void test01() {
    SheepTuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;
    //当菱形继承，两个父类拥有相同数据，需要加以作用域区分
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    //这份数据我们知道，只有一份就可以，菱形继承导致数据有两份，资源浪费
    cout << "st.m_Age = " << st.m_Age << endl;
}

int main() {
    test01();
    return 0;
}