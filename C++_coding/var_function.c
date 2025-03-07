/*
    C++中所有的变量和函数都必须有类型
    C语⾔中的默认类型在C++中是不合法的
    
    在C语言中, int f( )；表示返回值为int，接受任意参数的函数 
    int f(void)；表示返回值为int的无参函数 
    在C++中,int f( );和int f(void)具有相同的意义，都表示返回值为int的无参函数
*/

f(i){
    printf("i = %d\n", i);
}

g(){
    return 5;
}

int main(){
    f(10);

    printf("g() = %d\n", g(1, 2, 3, 4, 5));

    getchar();

    return 0;
}