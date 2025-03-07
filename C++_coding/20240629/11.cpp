#include <iostream>
using namespace std;
void func(int a, int) {
    cout << "this is a func" << endl;
}

int main() {
    
    //函数占位参数
    func(10, 10);//占位参数必须填补

    return 0;
}