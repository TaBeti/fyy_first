#include <iostream>
using namespace std;

class C1 {
    int m_A;//默认权限是private
};

struct C2 {
    int m_A;//默认权限是public
};

int main() {
    //在C++中，struct和class的区别在于默认的访问权限不同。
    //struct默认的访问权限是public，而class默认的访问权限是private。
    C1 c1;
    C2 c2;
    // c1.m_A = 10;//会报错
    c2.m_A = 20;

    return 0;
    
}