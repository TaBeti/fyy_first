#include <iostream>
using namespace std;
#include <string>

//1.自定义数据类型
struct student {
    string name;
    int age;
    int score;
} s3;

//2.通过学生类型创建具体学生
int main() {
    //结构体
    //法一
    //使用strcuct变量关键字可以省略
    struct  student s1;
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;
    cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 分数：" << s1.score << endl;

    //法二
    struct student s2 = {"李四", 19, 80};
    cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 分数：" << s1.score << endl;

    //法三
    s3.name = "王五";
    s3.age = 20;
    s3.score = 60;
    cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 分数：" << s3.score << endl;

    return 0;
}