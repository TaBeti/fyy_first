#include <iostream>
#include <map>
using namespace std;

//map排序 自定义数据类型
class Person {
public:
    string m_name;
    int m_age;

    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
};

class MyCompare {
public:
    bool operator()(const Person &p1, const Person &p2){
        //降序
        return p1.m_age > p2.m_age;
    }
};

void test01() {
    map<Person, int, MyCompare> m;

    Person p1("赵一", 10);
    Person p2("王二", 20);
    Person p3("张三", 30);

    m.insert(make_pair(p1, 1));
    m.insert(make_pair(p2, 2));
    m.insert(make_pair(p3, 3));

    for (map<Person, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "姓名：" << it->first.m_name << " 年龄：" << it->first.m_age << " value = " << it->second << endl;
    }
}

int main() {
    test01();
    return 0;
}