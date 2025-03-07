#include <iostream>
using namespace std;

struct hero {
    string name;
    int age;
    string gender;
};

void printHero(hero h) {
    cout << "姓名：" << h.name << " 年龄：" << h.age << " 性别：" << h.gender << endl;
}

int main() {
    struct hero hArray[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"},
    };
    int len = sizeof(hArray) / sizeof(hArray[0]);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (hArray[j].age > hArray[j+1].age) {
                hero temp = hArray[j];
                hArray[j] = hArray[j+1];
                hArray[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printHero(hArray[i]);
    }

    return 0;
}