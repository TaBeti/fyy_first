#include <iostream>
using namespace std;

int main() {
    //数组逆置
    int arr[5] = {1, 3, 2, 5, 4};
    int tmp = 0;
    //法一
    // for (int i = 0; i < 5 / 2; i++) {
    //     tmp = arr[i];
    //     arr[i] = arr[4 - i];
    //     arr[4 - i] = tmp;
    // }

    //法二
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while(start < end) {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}