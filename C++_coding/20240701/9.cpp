#include <iostream>
using namespace std;

//深拷贝与浅拷贝
//浅拷贝：简单的赋值拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作

class Person {
public:
    int m_age;
    int *m_height;
    Person() {
        cout << "Person的默认构造函数调用" << endl;
    }

    Person(int age, int height) {
        m_age = age;
        m_height = new int(height);
        cout << "Person的有参构造函数调用" << endl;
    }

    //如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
    //自己实现拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person &p) {
        m_age = p.m_age;
        // m_height = p.m_height;//浅拷贝，编译器默认实现这行代码
        cout << "Person的拷贝构造函数调用" << endl;
        //深拷贝操作
        m_height = new int(*p.m_height);
    }

    ~Person() {
        //析构代码，将堆区开辟数据做释放操作
        if (m_height != NULL) {
            delete m_height;
            m_height = NULL;
        }
        cout << "Person的析构函数调用" << endl;
    }
};

void test01() {
    Person p1(18, 160);
    cout << "p1的年龄为：" << p1.m_age << " 身高为：" << p1.m_height << endl;
    Person p2(p1);
    cout << "p2的年龄为：" << p1.m_age << " 身高为：" << p2.m_height << endl;
}

int main() {
    test01();
    return 0;
}