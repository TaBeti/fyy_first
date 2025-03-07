#include <stdio.h>

/*当使用<iostream>的时候，该头文件没有定义全局命名空间，必须使用
namespace std；这样才能正确使用cout。若不引入using namespace std ,需要这
样做。std::cout。*/
/*c++标准为了和C区别开，也为了正确使用命名空间，规定头文件不使用
后缀.h。*/
/*C++命名空间的定义： namespace name { … }*/
/*namespce定义可嵌套。*/

namespace NamespaceA{
    int a = 0;
}

namespace NamespaceB{
    int a = 1;
    namespace NamespaceC{
        struct Teacher{
            char name[10];
            int age;
        };
    }
}

int main(){
    using namespace NamespaceA;
    using NamespaceB::NamespaceC::Teacher;

    printf("a = %d\n", a);
    printf("a = %d\n", NamespaceB::a);

    NamespaceB::NamespaceC::Teacher t2;
    Teacher t1 = {"aaa", 3};

    printf("t1.name = %s\n", t1.name);
    printf("t1.age = %d\n", t1.age);

    return 0;
}