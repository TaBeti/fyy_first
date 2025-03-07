#include <iostream>

/*
    在C语⾔中，重复定义多个同名的全局变量是合法的
    在C++中，不允许定义多个同名的全局变量
    C语⾔中多个同名的全局变量最终会被链接到全局数据区的同⼀个地址空间上
    int	g_var;
    int	g_var	=	1;
    C++直接拒绝这种⼆义性的做法。
*/

int g_var;
int g_var = 1;

int main(int argc, char* argv[]){
    printf("g_var = %d\n", g_var);

    return 0;
}