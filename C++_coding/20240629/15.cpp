#include <iostream>
using namespace std;

class Student {
public:
    string m_name;
    int m_id;

    void show() {
        cout << "姓名：" << m_name << endl;
        cout << "学号：" << m_id << endl;
    }

    void setName(string name) {
        m_name = name;
    }

    void setId(int id) {
        m_id = id;
    }
};

int main() {
    Student stu;
    stu.setName("张三");
    stu.setId(123456);
    stu.show();
    return 0;
}