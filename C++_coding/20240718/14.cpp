#include <iostream>
using namespace std;

//自己的通用数组类
template<class T>
class MyArray {
private:
    T *pAddress;//指针指向堆区开辟的真实数组
    int m_Capacity;//数组的容量
    int m_Size;//数组的实际大小
public:
    //有参构造
    MyArray(int capacity) {
        // cout << "MyArray有参构造调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    //拷贝构造
    MyArray(const MyArray& arr) {
        // cout << "MyArray拷贝构造调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress = arr.pAddress;
        //深拷贝
        this->pAddress = new T[arr.m_Capacity];
        //将arr中的数据都拷贝过来
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator=防止浅拷贝问题
    MyArray& operator=(const MyArray& arr) {
        //先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    //尾插法
    void Push_Back(const T &val) {
        //判断容量是否等于大小
        if (this->m_Capacity == this->m_Size) {
            return;
        }
        this->pAddress[this->m_Size] = val;//在数组末尾插入数据
        this->m_Size++;//更新数组大小
    }

    //尾删法
    void Pop_Back() {
        //让用户访问不到最后一个元素即为尾删，逻辑删除
        if (this->m_Size == 0) {
            return;
        }
        this->m_Size--;
    }

    //通过下标方式访问数组中的元素
    T& operator[](int index) {
        return this->pAddress[index];
    }

    //返回数组容量
    int getCapacity() {
        return this->m_Capacity;
    }

    //返回数组大小
    int getSize() {
        return this->m_Size;
    }

    //析构函数
    ~MyArray() {
        // cout << "MyArray析构函数调用" << endl;
        if (this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }
};

void PrintArray(MyArray<int> &arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << endl;
    }
}

void test01() {
    MyArray<int> arr1(5);
    // MyArray<int> arr3(100);
    // arr3 = arr1;
    for (int i = 0; i < 5; i++) {
        //利用尾插法向数组中插入数据
        arr1.Push_Back(i);
    }
    cout << "arr1的打印输出为" << endl;
    PrintArray(arr1);
    cout << "arr1的容量为" << arr1.getCapacity() << endl;
    cout << "arr1的大小为" << arr1.getSize() << endl;

    MyArray<int> arr2(arr1);
    cout << "arr2的打印输出为" << endl;
    PrintArray(arr2);
    arr2.Pop_Back();
    cout << "arr2尾删后：" << endl;
    cout << "arr2的容量为" << arr2.getCapacity() << endl;
    cout << "arr2的大小为" << arr2.getSize() << endl;
}

//测试自定义数据类型
class Person {
public:
    string m_Name;
    int m_Age;
    Person() {}
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
};

void PrintPersonArray(MyArray<Person> &arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << "姓名：" << arr[i].m_Name << " 年龄：" << arr[i].m_Age << endl;
    }
}

void test02() {
    MyArray<Person> arr(10);
    Person p1("孙悟空", 999);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("赵云", 25);
    Person p5("安琪拉", 27);
    //将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);
    //打印数组
    PrintPersonArray(arr);
    //输出容量
    cout << "arr的容量为" << arr.getCapacity() << endl;
    //输出大小
    cout << "arr的大小为" << arr.getSize() << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}