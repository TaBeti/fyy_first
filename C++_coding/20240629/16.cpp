#include <iostream>
using namespace std;

//访问权限
//三种
//公共权限：public 成员 类内可以访问 类外可以访问
//私有权限：private 成员 类内可以访问 类外不能访问 子类不能访问
//保护权限：protected 成员 类内可以访问 类外不可以访问 子类可以访问 

class Person {
public:
    string m_name;

protected:
    int m_car;

private:
    int m_password;

public:
    void func() {
        m_name = "张三";
        m_car = "拖拉机";
        m_password = 123456;
    }

};

int main() {
    Person p;
    p.m_name = "李四";
    p.m_car = "汽车"; // 错误，保护权限的成员只能在类内访问
    p.m_password = 654321; // 错误，私有权限的成员只能在类内访问

}