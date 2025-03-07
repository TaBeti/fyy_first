#include <iostream>
using namespace std;

struct student {
    string name;
    int age;
    int score;
};

//将函数中的形参改为指针，可以减少内存空间，而且不会复制出新的副本出来
void printStudents(const student *s) {
    // s->age = 150;//加入const之后会报错
    cout << "姓名：" << s->name << endl;
    cout << "年龄：" << s->age << endl;
    cout << "分数：" << s->score << endl;
}

int main() {
    struct student s = {"张三", 15, 70};
    printStudents(&s);
    return 0;
}