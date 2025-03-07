#include <iostream>
using namespace std;

//多态
//Animal类内部结构：vfptr->vftable(存着虚函数地址&Animal::speak)
class Animal {
public:
    //虚函数
    virtual void speak() {
        cout << "动物在说话" << endl;
    }
};

//Cat类内部结构：vfptr->vftable(存着虚函数地址&Cat::speak)
class Cat: public Animal {
public:
    virtual void speak() {
        cout << "小猫在说话" << endl;
    }
};

class Dog: public Animal {
public:
    virtual void speak() {
        cout << "小狗在说话" << endl;
    }
};

//地址早绑定：在编译阶段确定函数地址(静态多态)
//地址晚绑定：在运行阶段确定函数地址(动态多态)
//如果想执行让猫说话，那么这个地址就不能提前绑定，需要在运行阶段进行绑定：地址晚绑定
//动态多态满足条件
//1、有继承关系
//2、子类重写父类的虚函数
//动态多态使用
//父类的指针或者引用指向子类对象
void doSpeak(Animal &animal) {
    animal.speak();
}

void test01() {
    Cat cat;//Animal &animal = cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

void test02() {
    cout << "sizeof Animal = " << sizeof(Animal) << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}