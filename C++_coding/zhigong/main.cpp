#include <iostream>
#include <fstream>
using namespace std;

//职工管理系统

//职工抽象类
class Worker{
public:
    //显示个人信息
    virtual void showInfo() = 0;

    //获取岗位名称
    virtual string getDeptName() = 0;

    //职工编号
    int m_Id;
    //职工姓名
    string m_Name;
    //岗位
    int m_did;
};

//员工类
class Employee: public Worker{
public:
    Employee(int id, string name, int did) {
        this->m_Id = id;
        this->m_Name = name;
        this->m_did = did;
    }

    //显示个人信息
    virtual void showInfo() {
        cout << "职工编号：" << this->m_Id
             << "\t职工姓名：" << this->m_Name
             << "\t岗位：" << this->getDeptName()
             << "\t岗位职责：完成经理交给的任务"
             << endl;
    }

    //获取岗位名称
    virtual string getDeptName() {
        return string("员工");
    }
};

//经理类
class Manager: public Worker{
public:
    Manager(int id, string name, int did) {
        this->m_Id = id;
        this->m_Name = name;
        this->m_did = did;
    }

    //显示个人信息
    virtual void showInfo() {
        cout << "职工编号：" << this->m_Id
             << "\t职工姓名：" << this->m_Name
             << "\t岗位：" << this->getDeptName()
             << "\t岗位职责：完成老板交给的任务，并下发任务给员工"
             << endl;
    }

    //获取岗位名称
    virtual string getDeptName() {
        return string("经理");
    }
};

//老板类
class Boss: public Worker{
public:
    Boss(int id, string name, int did) {
        this->m_Id = id;
        this->m_Name = name;
        this->m_did = did;
    }

    //显示个人信息
    virtual void showInfo() {
        cout << "职工编号：" << this->m_Id
             << "\t职工姓名：" << this->m_Name
             << "\t岗位：" << this->getDeptName()
             << "\t岗位职责：管理公司所有事务"
             << endl;
    }

    //获取岗位名称
    virtual string getDeptName() {
        return string("老板");
    }
};

class WorkerManager {
public:
    //职工人数
    int m_EmpNum;

    //职工数组指针
    Worker **m_EmpArray;

    //文件是否为空标志
    bool FileIsEmpty;

    WorkerManager() {
        ifstream ifs;
        ifs.open("empFile.txt", ios::in);//读文件
        //1、文件不存在情况
        if (!ifs.is_open()) {
            // cout << "文件不存在" << endl;
            //初始化属性
            //初始化记录人数
            this->m_EmpNum = 0;
            //初始化数组指针
            this->m_EmpArray = NULL;
            //初始化文件是否为空
            this->FileIsEmpty = true;
            ifs.close();
            return;
        }

        //2、文件存在 数据为空
        char ch;
        ifs >> ch;
        if (ifs.eof()) {
            // cout << "文件为空" << endl;
            //初始化属性
            //初始化记录人数
            this->m_EmpNum = 0;
            //初始化数组指针
            this->m_EmpArray = NULL;
            //初始化文件是否为空
            this->FileIsEmpty = true;
            ifs.close();
            return;
        } 

        //3、文件存在，并且记录数据
        int num = this->get_EmpNum();
        // cout << "职工人数为：" << num << endl;
        this->m_EmpNum = num;
        this->FileIsEmpty = false;
        //开辟空间
        this->m_EmpArray = new Worker*[this->m_EmpNum];
        //将文件中的数据存到数组中
        this->init_Emp();
        // for (int i = 0; i < this->m_EmpNum; i++) {
        //     cout << "职工编号：" << this->m_EmpArray[i]->m_Id
        //          << " 姓名：" << this->m_EmpArray[i]->m_Name
        //          << " 部门编号：" << this->m_EmpArray[i]->m_did << endl;
        // }
    }

    //显示菜单
    void Show_Menu() {
        cout << "*********************************" << endl;
        cout << "*******欢迎使用职工管理系统******" << endl;
        cout << "******** 0、退出管理程序 ********" << endl;
        cout << "******** 1、增加职工信息 ********" << endl;
        cout << "******** 2、显示职工信息 ********" << endl;
        cout << "******** 3、删除离职职工 ********" << endl;
        cout << "******** 4、修改职工信息 ********" << endl;
        cout << "******** 5、查找职工信息 ********" << endl;
        cout << "******** 6、按照编号排序 ********" << endl;
        cout << "******** 7、清空所有文档 ********" << endl;
        cout << "*********************************" << endl;
    }

    //退出系统
    void ExitSystem() {
        cout << "欢迎下次使用" << endl;
        exit(0);
    }

    //保存文件
    void save() {
        ofstream ofs;
        //写入文件
        ofs.open("empFile.txt", ios::out);
        for (int i = 0; i < this->m_EmpNum; i++) {
            ofs << this->m_EmpArray[i]->m_Id << " "
                << this->m_EmpArray[i]->m_Name << " "
                << this->m_EmpArray[i]->m_did << endl;
        }
        ofs.close();
    }

    //添加职工
    void Add_Emp() {
        cout << "请输入添加职工数量" << endl;
        int addNum = 0;
        cin >> addNum;
        if (addNum > 0) {
            //添加，计算添加新空间大小
            int newSize = this->m_EmpNum + addNum;
            //开辟新空间
            Worker **newSpace = new Worker*[newSize];
            //将原来空间下数据拷贝到新空间下
            if (this->m_EmpArray != NULL) {
                for (int i = 0; i < this->m_EmpNum; i++) {
                    newSpace[i] = this->m_EmpArray[i];
                }
            }
            //批量添加新数据
            for (int i = 0; i < addNum; i++) {
                int id;//职工编号
                string name;//职工姓名
                int dSelect;//部门选择

                cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
                cin >> id;
                cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
                cin >> name;
                cout << "请选择该职工岗位：" << endl;
                cout << "1、普通员工" << endl;
                cout << "2、经理" << endl;
                cout << "3、老板" << endl;
                cin >> dSelect;

                Worker *worker = NULL;
                switch (dSelect) {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
                }
                
                //将创建职工职责，保存到数组中
                newSpace[this->m_EmpNum + i] = worker;
            }
            //释放原有空间
            delete[] this->m_EmpArray;
            //更改新空间的指向
            this->m_EmpArray = newSpace;
            //更新新的职工人数
            this->m_EmpNum = newSize;
            //更新职工不为空标志
            this->FileIsEmpty = false;
            //提示添加成功
            cout << "成功添加" << addNum << "名新职工" << endl;
            //成功添加后保存到文件中
            this->save();
        }
        else {
            cout << "输入数据有误" << endl;
        }
    }

    //统计文件中人数
    int get_EmpNum() {
        ifstream ifs;
        ifs.open("empFile.txt", ios::in);//读文件

        int id;
        string name;
        int did;

        int num = 0;

        while (ifs >> id && ifs >> name && ifs >> did) {
            //记录人数
            num++;
        }
        ifs.close();
        return num;
    }

    //初始化员工
    void init_Emp() {
        ifstream ifs;
        ifs.open("empFile.txt", ios::in);//读文件

        int id;
        string name;
        int did;

        int index = 0;
        while (ifs >> id && ifs >> name && ifs >>did) {
            Worker *worker = NULL;
            if (did == 1) {
                worker = new Employee(id, name, did);
            }
            else if (did == 2) {
                worker = new Manager(id, name, did);
            }
            else if (did == 3) {
                worker = new Boss(id, name, did);
            }
            this->m_EmpArray[index] = worker;
            index++;
        }
        ifs.close();
    }

    //显示职工
    void Show_Emp() {
        //判断文件是否为空
        if (this->FileIsEmpty) {
            cout << "文件不存在或记录为空" << endl;
        }
        else {
            for (int i = 0; i < this->m_EmpNum; i++) {
                //利用多态调用程序接口
                this->m_EmpArray[i]->showInfo();
            }
        }
    }

    //判断职工是否存在
    int is_Exist(int id) {
        int index = -1;
        for (int i = 0; i < this->m_EmpNum; i++) {
            if (this->m_EmpArray[i]->m_Id == id) {
                index = i;
                break;
            }
        }
        return index;
    }

    //删除职工
    void Del_Emp() {
        if (this->FileIsEmpty) {
            cout << "文件不存在或记录为空" << endl;
        }
        else {
            //按照职工编号删除
            cout << "请输入想到删除的职工编号" << endl;
            int id = 0;
            cin >> id;
            int index = this->is_Exist(id);
            if (index != -1) {
                //说明职工存在，并且要删除掉index位置上的职工
                for (int i = index; i < this->m_EmpNum - 1; i++) {
                    //数据前移
                    this->m_EmpArray[i] = this->m_EmpArray[i + 1];
                }
                this->m_EmpNum--;//更新职工人数
                this->save();//更新数据
                cout << "删除成功" << endl;
            }
            else {
                cout << "删除失败，未找到该职工" << endl;
            }
        }
    }

    //修改职工信息
    void Mod_Emp() {
        if (this->FileIsEmpty) {
            cout << "文件不存在或记录为空" << endl;
        }
        else {
            cout << "请输入想修改的职工编号" << endl;
            int id;
            cin >> id;
            int ret = this->is_Exist(id);
            if (ret != -1) {
                //查找到职工的编号
                delete this->m_EmpArray[ret];
                int newId = 0;
                string newName = "";
                int dSelect = 0;

                cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
                cin >> newId;

                cout << "请输入新姓名：" << endl;
                cin >> newName;

                cout << "请输入岗位：" << endl;
                cout << "1、普通员工" << endl;
                cout << "2、经理" << endl;
                cout << "3、老板" << endl;
                cin >> dSelect;

                Worker *worker = NULL;
                switch (dSelect) {
                case 1:
                    worker = new Employee(newId, newName, 1);
                    break;
                case 2:
                    worker = new Manager(newId, newName, 2);
                    break;
                case 3:
                    worker = new Boss(newId, newName, 3);
                    break;
                default:
                    break;
                }
                //更新数据到数组中
                this->m_EmpArray[ret] = worker;
                cout << "修改成功" << endl;
                //保存文件
                this->save();
            }
            else {
                cout << "修改失败，查无此人" << endl;
            }
        }
    }

    //查找职工
    void Find_Emp() {
        if (this->FileIsEmpty) {
            cout << "文件不存在或记录为空" << endl;
        }
        else {
            cout << "请输入查找的方式：" << endl;
            cout << "1、按职工编号查找" << endl;
            cout << "2、按职工姓名查找" << endl;
            int select = 0;
            cin >> select;
            if (select == 1) {
                int id;
                cout << "请输入查找的员工编号：" << endl;
                cin >> id;
                int ret = this->is_Exist(id);
                if (ret != -1) {
                    cout << "查找成功！该职工信息如下：" << endl;
                    this->m_EmpArray[ret]->showInfo();
                }
                else {
                    cout << "查找失败，查无此人" << endl;
                }
            }
            else if (select == 2) {
                string name;
                cout << "请输入职工姓名：" << endl;
                cin >> name;
                //判断是否查到标志
                bool flag = false;
                for (int i = 0; i < this->m_EmpNum; i++) {
                    if (this->m_EmpArray[i]->m_Name == name) {
                        cout << "查找成功，职工编号为" 
                             << this->m_EmpArray[i]->m_Id
                             << "号信息如下：" << endl;
                        flag = true;
                        this->m_EmpArray[i]->showInfo();
                    }
                }
                if (flag == false) {
                    cout << "查找失败，查无此人" << endl;
                }
            }
            else {
                cout << "输入选项有误" << endl;
            }
        }
    }

    //排序
    void Sort_Emp() {
        if (this->FileIsEmpty) {
            cout << "文件不存在或记录为空" << endl;
        }
        else {
            cout << "请选择排序的方式：" << endl;
            cout << "1、按职工号进行升序" << endl;
            cout << "2、按职工号进行降序" << endl;

            int select = 0;
            cin >> select;

            for (int i = 0; i < m_EmpNum; i++) {
                int minOrmax = i;//声明最小值或最大值下标
                for (int j = i + 1; j < this->m_EmpNum; j++) {
                    if (select == 1) {//升序
                        if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id) {
                            minOrmax = j;
                        }
                    }
                    else {//降序
                        if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id) {
                            minOrmax = j;
                        }
                    }
                }
                //判断一开始认定的最小值或最大值是不是计算的最小值或最大值，如果不是交换数据
                if (i != minOrmax) {
                    Worker *temp = this->m_EmpArray[i];
                    this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
                    this->m_EmpArray[minOrmax] = temp;
                }
            }
            cout << "排序成功！排序后的结果为：" << endl;
        }
    }

    //清空文件
    void Clear_File() {
        cout << "确定清空？" << endl;
        cout << "1、确定" << endl;
        cout << "2、取消" << endl;
        int select = 0;
        cin >> select;
        if (select == 1) {
            //清空文件
            ofstream ofs("empFile.txt", ios::trunc);//删除文件后再重新创建
            ofs.close();

            if (this->m_EmpArray != NULL) {
                //删除堆区的每一个职工对象
                for (int i = 0; i < this->m_EmpNum; i++) {
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }

                //删除堆区数组指针
                delete[] this->m_EmpArray;
                this->m_EmpArray = NULL;
                this->m_EmpNum = 0;
                this->FileIsEmpty = true;
            }
            cout << "清空成功！" << endl;
        }
    }

    ~WorkerManager() {
        if (this->m_EmpArray != NULL) {
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
        }
    }
};

int main() {
    //测试代码
    // Worker *worker = NULL;
    // worker = new Employee(1, "张三", 1);
    // worker->showInfo();
    // delete worker;

    // worker = new Manager(2, "李四", 2);
    // worker->showInfo();
    // delete worker;

    // worker = new Boss(3, "王五", 3);
    // worker->showInfo();
    // delete worker;

    // //实例化管理者对象
    WorkerManager wm;

    int choice = 0;

    while (true) {
        wm.Show_Menu();
        cout << "请输入您的选择：" << endl;
        cin >> choice;
        switch (choice) {
        case 0://退出系统
            wm.ExitSystem();
            break;
        case 1://增加职工
            wm.Add_Emp();
            break;
        case 2://显示职工
            wm.Show_Emp();
            break;
        case 3: 
            wm.Del_Emp();
            break;
        case 4://修改职工
            wm.Mod_Emp();
            break;
        case 5://查找职工
            wm.Find_Emp();
            break;
        case 6://排序
            wm.Sort_Emp();
            break;
        case 7://清空文档
            wm.Clear_File();
            break;
        }
    }
    return 0;
}