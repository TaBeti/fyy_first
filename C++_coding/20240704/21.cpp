#include <iostream>
using namespace std;

//抽象CPU类
class CPU {
public:
    virtual void calculate() = 0;
};

//抽象显卡类
class GPU {
public:
    virtual void display() = 0;
};

//抽象内存条类
class Memory {
public:
    virtual void storage() = 0;
};

//电脑类
class Computer {
private:
    CPU *m_cpu;
    GPU *m_gpu;
    Memory *m_memory;
public:
    Computer(CPU *cpu, GPU *gpu, Memory *memory) {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }
    void work() {
        m_cpu->calculate();
        m_gpu->display();
        m_memory->storage();
    }
    ~Computer() {
        if (m_cpu != NULL) {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_gpu != NULL) {
            delete m_gpu;
            m_gpu = NULL;
        }
        if (m_memory != NULL) {
            delete m_memory;
            m_memory = NULL;
        }
    }
};

//Intel厂商
class IntelCPU: public CPU {
public: 
    virtual void calculate() {
        cout << "Intel的CPU开始计算了！" << endl;
    }
};

class IntelGPU: public GPU {
public: 
    virtual void display() {
        cout << "Intel的GPU开始显示了！" << endl;
    }
};

class IntelMemory: public Memory {
public: 
    virtual void storage() {
        cout << "Intel的内存条开始存储了！" << endl;
    }
};

//Lenovo厂商
class LenovoCPU: public CPU {
public: 
    virtual void calculate() {
        cout << "Lenovo的CPU开始计算了！" << endl;
    }
};

class LenovoGPU: public GPU {
public: 
    virtual void display() {
        cout << "Lenovo的GPU开始显示了！" << endl;
    }
};

class LenovoMemory: public Memory {
public: 
    virtual void storage() {
        cout << "Lenovo的内存条开始存储了！" << endl;
    }
};

void test01() {
    //第一台电脑零件
    cout << "第一台电脑：" << endl;
    CPU *intelCPU = new IntelCPU();
    GPU *intelGPU = new IntelGPU();
    Memory *intelMem = new IntelMemory();
    //创建第一台电脑
    Computer *computer1 = new Computer(intelCPU, intelGPU, intelMem);
    computer1->work();
    delete computer1;
    cout << "-----------" << endl;

    //创建第二台电脑
    cout << "第二台电脑：" << endl;
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMemory);
    computer2->work();
    delete computer2;
}

int main() {
    test01();
    return 0;
}