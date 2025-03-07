#include <iostream>
using namespace std;
#include <ctime>

struct student {
    string name;
    int score;
};

struct teacher {
    string tname;
    struct student sArray[5];
};

void allocateSpace(struct teacher tArray[], int len) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++) {
        tArray[i].tname = "Teacher_";
        tArray[i].tname += nameSeed[i];
        for (int j = 0; j < 5; j++) {
            tArray[i].sArray[j].name = "Student_";
            tArray[i].sArray[j].name += nameSeed[i];
            int random = rand() % 61 + 40;//40-60 + 40
            tArray[i].sArray[j].score = random;
        }
    }
}

void printInfo(struct teacher tArray[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "老师姓名：" << tArray[i].tname << endl;
        for (int j = 0; j < 5; j++) {
            cout << "\t学生姓名：" << tArray[i].sArray[j].name << endl;
            cout << "\t学生分数：" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));
    struct teacher tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray, len);
    printInfo(tArray, len);
    return 0;
}