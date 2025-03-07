#include <iostream>
#include <queue>
using namespace std;

int main() {
    //实际上是一个大根堆
    priority_queue<int> heap;
    heap.push(5);
    heap.push(10);
    //返回堆顶元素
    cout << heap.top() << endl;
    //弹出堆顶元素
    heap.pop();
    cout << heap.top() << endl;
    cout << heap.size() << endl;

    return 0;
}