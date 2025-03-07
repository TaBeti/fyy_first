#include <iostream>
using namespace std;

//1、构造函数：进行初始化操作
//2、析构函数：进行清理的操作
class Person {
public:
//1.1、构造函数
    //没有返回值，不用写void
    //函数名与类名相同
    //构造函数可以有参数，可以发生重载
    //创建对象的时候，构造函数会自动调用，而且只调用一次
    Person() {
        cout << "Person构造函数的调用" << endl;
    }
//1.2、析构函数
    //没有返回值，不用写void
    //函数名和类名相同，在名称前面加~
    //析构函数不能有参数，不能重载
    //对象销毁的时候，析构函数会自动调用，而且只调用一次
    ~Person() {
        cout << "Person析构函数的调用" << endl;
    }

};

void test01() {
    Person p;
}

int main() {
    Person p;
    return 0;
}