#include <iostream>
using namespace std;

void bubblesort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//打印数组
void printArray(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    //指针、数组和函数
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, len);
    printArray(arr, len);
    return 0;
}