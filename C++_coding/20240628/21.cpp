#include <iostream>
using namespace std;

struct student {
    string name;
    int age;
    int score;
};

int main() {
    //结构体指针
    //1.创建结构体变量
    struct student s = {"张三" , 18, 19};
    //2.通过指针指向结构体变量
    struct student *p = &s;
    //3.通过指针访问结构体变量中的数据
    cout << "姓名：" << p->name << endl;
    cout << "年龄：" << p->age << endl;
    cout << "分数：" << p->score << endl;
    return 0;
}