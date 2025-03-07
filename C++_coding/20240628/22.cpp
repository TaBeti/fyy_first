#include <iostream>
using namespace std;

//嵌套结构体
struct student {
    string name;
    int age;
    int score;
};

struct teacher {
    int id;
    string name;
    int age;
    struct student stu;
};

int main() {
    teacher t;
    t.id = 10000;
    t.name = "老王";
    t.age = 50;
    t.stu.name = "小王";
    t.stu.age = 20;
    t.stu.score = 60;
    cout << "老师id：" << t.id << endl;
    cout << "老师姓名：" << t.name << endl;
    cout << "老师年龄：" << t.age << endl;
    cout << "学生姓名：" << t.stu.name << endl;
    cout << "学生年龄：" << t.stu.age << endl;
    cout << "学生分数：" << t.stu.score << endl;

    return 0;
}