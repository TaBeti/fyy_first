#include <iostream>
using namespace std;

//虚析构和纯虚析构
class Animal {
public:
    Animal() {
        cout << "Animal构造函数调用" << endl;
    }
    //纯虚函数
    virtual void speak() = 0;
    //虚析构可以解决父类指针释放子类对象时内存泄漏问题
    // virtual ~Animal() {
    //     cout << "Animal析构函数调用" << endl;
    // }
    //纯虚析构 需要声明也需要实现
    //有了纯虚析构之后，这个类也属于抽象类
    virtual ~Animal() = 0;
};

Animal::~Animal() {
    cout << "Animal纯虚析构函数调用" << endl;
}

class Cat: public Animal {
public:
    string *m_Name;
    Cat(string name) {
        m_Name = new string(name);
        cout << "Cat构造函数调用" << endl;
    }
    virtual void speak() {
        cout << *m_Name <<"小猫在说话" << endl;
    }
    ~Cat() {
        if (m_Name != NULL) {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
};

void test01() {
    Animal *animal = new Cat("Tom");
    animal->speak();
    //父类指针在析构时候不会调用子类析构函数，会导致内存泄漏
    delete animal;
}


int main() {
    test01();
    return 0;
}