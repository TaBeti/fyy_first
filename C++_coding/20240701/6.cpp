#include <iostream>
using namespace std;

class Person {
    int age;
public:
    //1、构造函数的分类及调用
    //分类
    //按照参数分类：无参构造和有参构造
    //按照类型分类：普通构造、拷贝构造
    Person() {
        cout << "Person无参构造函数的调用" << endl;
    }
    Person(int a) {
        age = a;
        cout << "Person有参构造函数的调用" << endl;
    }
    //拷贝构造函数
    Person(const Person &p) {
        //将传入的人身上的所有属性，拷贝到我身上
        age = p.age;
        cout << "Person拷贝构造函数的调用" << endl;
    }

    //2、析构函数
    ~Person() {
        cout << "Person析构函数的调用" << endl;
    }

};

//调用
void test01() {
    //1、括号法
    // Person p1;
    // Person p2(10);//有参构造
    // Person p3(p2);//拷贝构造
    //调用默认构造函数时，不要加括号，编译器会认为是函数声明
    // Person p1();

    //2、显示法
    // Person p1;
    // Person p2 = Person(10);//有参构造
    // Person p3 = Person(p2);//拷贝构造
    // Person(10);//匿名对象，当前行执行结束后，系统后立即回收掉匿名对象
    //不要利用拷贝构造函数初始化匿名对象，编译器会认为Person(p3) = Person p3;
    // Person(p3);//会报错

    //3、隐式转换法
    Person p4 = 10;//Person p4 = Person(10);
    //Person p5 = p4;//Person p5 = Person(p4);
}

int main() {
    test01();
    return 0;
}