#include <iostream>
using namespace std;

int main() {
    //记忆技巧：将const翻译成常量
    //const修饰指针：常量指针
    //特点：指针的指向可以修改，但是指针指向的值不可以修改
    int a = 10;
    int b = 20;
    const int *p = &a;
    p = &b;//正确，指针的指向可以修改
    // *p = 30;//错误，指针指向的值不可以修改

    //const修饰常量：指针常量
    //特点：指针的指向不可以修改，但是指针指向的值不可以修改
    // int const *p = &a;
    // p = &b;//错误，指针的指向不可以修改
    // *p = 30;//正确，指针指向的值可以修改

    // const同时修饰指针和常量
    // const int * const p = &a;
    //p = &b;//错误，指针的指向不可以修改
    //*p = 30;//错误，指针指向的值不可以修改

    return 0;
}