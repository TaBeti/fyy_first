#include <iostream>
using namespace std;

class Person {
public:
    int age;
    Person(int age) {
        //this指针指向被调用成员函数所属的对象
        this->age = age;
    }
    Person& PersonAddAge(Person &p) {
        //如果返回值是Person，则不会一直相加
        this->age += p.age;
        return *this;
    }
};

//this指针
//1、解决名称冲突
void test01() {
    Person p1(20);
    cout << "p1的年龄是" << p1.age << endl;
}
//2、返回对象本身用*this;
void test02() {
    Person p1(10);
    Person p2(10);
    // p2.PersonAddAge(p1);
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//链式编程思想
    cout << "p2的年龄为：" << p2.age << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}