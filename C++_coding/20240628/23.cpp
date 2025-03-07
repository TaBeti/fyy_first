#include <iostream>
using namespace std;

struct student {
    string name;
    int age;
    int score;
};

//值传递
void printStudent1(struct student s) {
    s.age = 100;
    cout << "子函数1中打印" << endl;
    cout << "姓名：" << s.name << endl;
    cout << "年龄：" << s.age << endl;
    cout << "分数：" << s.score << endl;
}

//地址传递
void printStudent2(struct student *s) {
    s->age = 100;
    cout << "子函数2中打印" << endl;
    cout << "姓名：" << s->name << endl;
    cout << "年龄：" << s->age << endl;
    cout << "分数：" << s->score << endl;
}

int main() {
    //结构体做函数参数
    struct student s;
    s.name = "张三";
    s.age = 20;
    s.score = 85;
    cout << "main函数中打印" << endl;
    cout << "姓名：" << s.name << endl;
    cout << "年龄：" << s.age << endl;
    cout << "分数：" << s.score << endl;
    // printStudent1(s);
    printStudent2(&s);
    return 0;
}