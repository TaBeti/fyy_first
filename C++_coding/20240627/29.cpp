#include <iostream>
using namespace std;

int main() {
    //1.第一种一维数组的定义
    // int arr[5];
    // arr[0] = 10;
    // arr[1] = 20;
    // arr[2] = 30;
    // arr[3] = 40;
    // arr[4] = 50;

    // cout << arr[0] << endl;
    // cout << arr[1] << endl;
    // cout << arr[2] << endl;
    // cout << arr[3] << endl;
    // cout << arr[4] << endl;

    //2.第二种一维数组的定义
    // int arr2[5] = {10, 20, 30};//多余值会自动填充默认值0

    // cout << arr2[0] << endl;
    // cout << arr2[1] << endl;
    // cout << arr2[2] << endl;
    // cout << arr2[3] << endl;    
    // cout << arr2[4] << endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << arr2[i] << endl;
    // }

    //3.第三种一维数组的定义
    int arr3[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    for (int i = 0; i < 9; i++) {
        cout << arr3[i] << endl;
    }

    return 0;
}