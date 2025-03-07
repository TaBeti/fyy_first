//通讯录管理系统
#include <iostream>
using namespace std;
#define MAX 1000//最大联系人数量
#include <string>

//菜单界面
void showMenu() {
    cout << "***************************" << endl;
    cout << "****** 1、添加联系人 ******" << endl;
    cout << "****** 2、显示联系人 ******" << endl;
    cout << "****** 3、删除联系人 ******" << endl;
    cout << "****** 4、查找联系人 ******" << endl;
    cout << "****** 5、修改联系人 ******" << endl;
    cout << "****** 6、清空联系人 ******" << endl;
    cout << "****** 0、退出通讯录 ******" << endl;
    cout << "***************************" << endl;
}

//设计联系人结构体
struct person {
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_addr;
};

//设计通讯录结构体
struct addressbooks {
    //通讯录中保存的联系人数组
    struct person personArray[MAX];
    //通讯录中当前的联系人数量
    int m_size;
};

//添加联系人
void addPerson(addressbooks *ads) {
    //先判断通讯录中当前的联系人数量是否已达到最大值
    if (ads->m_size == MAX) {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else {
        //添加具体联系人
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        ads->personArray[ads->m_size].m_name = name;

        //性别
        int sex;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                ads->personArray[ads->m_size].m_sex = sex;
                break;
            }
            cout << "输入错误，请重新输入！" << endl;
        }

        //年龄
        int age;
        cout << "请输入年龄：" << endl;
        while (true) {
            cin >> age;
            if (age > 0 && age < 150) {
                ads->personArray[ads->m_size].m_age = age;
                break;
            }
            cout << "输入错误，请重新输入！" << endl;
        }

        //电话
        string phone;
        cout << "请输入电话：" << endl;
        while (true) {
            cin >> phone;
            int len = phone.length();
            if (len == 11 && phone[0] == '1') {
                ads->personArray[ads->m_size].m_phone = phone;
                break;
            }
            cout << "输入错误，请重新输入！" << endl;
        }

        //地址
        string addr;
        cout << "请输入地址：" << endl;
        cin >> addr;
        ads->personArray[ads->m_size].m_addr = addr;

        //联系人数量加1
        ads->m_size++;

        cout << "添加成功！" << endl;
    }
}

//显示联系人
void showPerson(addressbooks *ads) {
    if (ads->m_size == 0) {
        cout << "当前记录为空" << endl;
    }
    else {
        for (int i = 0; i < ads->m_size; i++) {
            cout << "姓名：" << ads->personArray[i].m_name << "\t";
            cout << "性别：" << (ads->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << ads->personArray[i].m_age << "\t";
            cout << "电话：" << ads->personArray[i].m_phone << "\t";
            cout << "地址：" << ads->personArray[i].m_addr << endl;
        }
    }
}

//检测联系人是否存在，如果存在返回联系人所在数组中的具体位置，不存在返回-1
int isExist(addressbooks *ads, string name) {
    for (int i = 0; i < ads->m_size; i++) {
        if (ads->personArray[i].m_name == name) {
            return i;
        }
    }
    return -1;
}

//删除联系人
void deletePerson(addressbooks *ads) {
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(ads, name);
    if (ret != -1) {
        //找到此人，进行删除操作
        for (int i = ret; i < ads->m_size; i++) {
            //数据前移
            ads->personArray[i] = ads->personArray[i + 1];
        }
        ads->m_size--;
        cout << "删除成功！" << endl;
    }
    else {
        cout << "查无此人！" << endl;
    }
}

//查找指定联系人信息
void findPerson(addressbooks *ads) {
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;
    //判断指定的联系人是否存在
    int ret = isExist(ads, name);
    if (ret != -1) {
        cout << "姓名：" << ads->personArray[ret].m_name << "\t";
        cout << "性别：" << (ads->personArray[ret].m_sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << ads->personArray[ret].m_age << "\t";
        cout << "电话：" << ads->personArray[ret].m_phone << "\t";
        cout << "地址：" << ads->personArray[ret].m_addr << endl;
    }
    else {
        cout << "查无此人！" << endl;
    }
}

//修改指定联系人信息
void modifyPerson(addressbooks *ads) {
    cout << "请输入您要修改的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(ads, name);
    if (ret != -1) {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        ads->personArray[ret].m_name = name;

        //性别
        int sex;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                ads->personArray[ret].m_sex = sex;
                break;
            }
            else {
                cout << "输入错误，请重新输入！" << endl;
            }
        }

        //年龄
        int age;
        cout << "请输入年龄：" << endl;
        while (true) {
            cin >> age;
            if (age > 0 && age < 150) {
                ads->personArray[ret].m_age = age;
                break;
            }
            else {
                cout << "输入错误，请重新输入！" << endl;
            }
        }

        //电话
        string phone;
        cout << "请输入电话：" << endl;
        while (true) {
            cin >> phone;
            int len = phone.length();
            if (len == 11 && phone[0] == '1') {
                ads->personArray[ret].m_phone = phone;
                break;
            }
            else {
                cout << "输入错误，请重新输入！" << endl;
            }
        }

        //地址
        string addr;
        cout << "请输入地址：" << endl;
        cin >> addr;
        ads->personArray[ret].m_addr = addr;
        cout << "修改成功！" << endl;
    }
    else {
        cout << "查无此人！" << endl;
    }
}

//清空联系人
void clearPerson(addressbooks *ads) {
    ads->m_size = 0;//逻辑清空
    cout << "通讯录已清空！" << endl;
}

int main() {
    //创建通讯录结构体变量
    addressbooks ads;
    //初始化通讯录中当前的联系人数量
    ads.m_size = 0;

    int select = 0;//创建用户选择输入的变量

    while (true) {
        //菜单调用
        showMenu();

        cin >> select;

        switch (select) {
            case 1://添加联系人
            addPerson(&ads);//利用地址传递可以修改形参
                break;
            case 2://显示联系人
                showPerson(&ads);
                break;
            case 3://删除联系人
                deletePerson(&ads);
                break;
            case 4://查找联系人
                findPerson(&ads);
                break;
            case 5://修改联系人
                modifyPerson(&ads);
                break;
            case 6://清空联系人
                clearPerson(&ads);
                break;
            case 0:
                cout << "欢迎下次使用！" << endl;
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}