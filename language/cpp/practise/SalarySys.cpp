#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;


// 枚举员工的级别
enum EmpLevel
{
    enumOfficer = 1, // 高级员工
    enumStaff = 2    // 一般员工
};

// 员工类

class Employee
{
    public:
        // 构造函数，根据员工的姓名和入职年份构造对象
        Employee(string strName, int nY)
        :m_strName(strName),m_nYear(nY){}
    // Employee 类的行为，这些行为都是供外界调用的接口
    // 所以将其访问级别设定为public
    public:
        // 获得员工入职年份
        string GetName() const{
            return m_strName;
        }
        // 获得员工入职年份
        int GetYear() const{
            return m_nYear;
        }
        EmpLevel GetLevel() const{
            return m_nLevel;
        }
        // 获得员工工资
        // 不同的派生类有不同的行为(计算方法), 所以在基类Employee中只是用
        // 纯虚函数表示接口，具体行为由其派生类实现
        virtual int GetSalary() = 0;
        // GetWorkTime()只是供自身和自己的派生类使用
        // 所以将其访问级别设定为protected
    protected:
        int GetWorkTime() const
        {
            time_t t = time(0);
            struct tm* now = localtime(&t);
            return now->tm_year + 1900 - m_nYear +1;
        }

    private:
        string m_strName; //姓名
        int m_nYear; // 入职年份
        EmpLevel m_nLevel; //级别
};

class Officer: public Employee{
    public:
        Officer(string strName, int nY):Employee(strName, nY)
        {
            m_nLevel = enumOfficer;
        }
    public:
        // 对基类的纯虚函数进行重写，具体实现员工计算工资的行为
        virtual int GetSalary() override
        {
            return GetWorkTime()*5000;
        }
};

class Staff: public Employee
{
    public:
    Staff(string strName, int nY):Employee(strName, nY)
    {
        m_nLevel = enumStaff;
    }
    public:
    // 不同的派生类对相同的行为有不同的实现
    // 这就是类的多态机制的体现

    virtual int GetSalary() override
    {
        return GetWorkTime()*1000;
    }
};

// 定义SalarySys中数组的最大数据量
// 也就是SalarySys最多能处理多少个员工数据
const int MAX = 100000;

// 工资管理类SalarySys
class SalarySys
{
    public:
        SalarySys()
        :m_nCount(0),m_strFileName("SalaryData.txt")
        {
            // 对数组进行初始化，使得数组中都是nullptr
            for(long i=0;i<MAX; ++i)
            {
                m_arrEmp[i] = nullptr;
            }
            // 读取员工数据文件
            Read();
        }
        // 析构函数，完成清理工作
        ~SalarySys()
        {
            // 将员工数据写入文件，以备下次读取
            Write();
            // 释放数组中已创建的员工对象
            for(long i=0;i<m_nCount;++i)
            {
                delete m_arrEmp[i];
                m_arrEmp[i] = nullptr;
            }

        }
    // SalarySys的公有行为
    public:
        int Read()
        {
            // 文件读取中间临时变量
            string strName = "";
            int nLevel = 0;
            int nYear = 0;
            // 读取数据个数
            int i = 0;
            // 打开数据文件
            ifstream in(m_strFileName);
            if(in.is_open()){
                while(true){
                    // 分别读取姓名，级别和入职年份
                    in>>strName>>nLevel>>nYear;
                    if(!in)
                        break;
                    if (enumOfficer == nLevel)
                    {
                        m_arrEmp[i] = new Officer(strName, nYear);
                        ++i;
                    }else if(enumStaff == nLevel)
                    {
                        m_arrEmp[i] = new Staff(strName, nYear);
                        ++i;
                    }
                    
                    if(i>=MAX)
                    break;
                }

                in.close();
            }

            cout<<"已读取"<<i<<"个员工数据"<<endl;
            m_nCount = i;
            return i;
        }

        void Write()
        {
            ofstream o(m_strFileName);
            if (o.is_open())
            {
                for(int i=0;i<m_nCount; ++i)
                {
                    Employee* p = m_arrEmp[i];
                    o<<p->GetName()<<"\t"
                        <<p->GetLevel()<<"\t"
                        <<p->GetYear()<<endl;
                }
                o.close();
            }
        }

        int Input()
        {
            cout<<"请输入员工信息(名字 级别(1,2) 入职年份,exp:wanggang 1 1982" <<endl;
            cout<<"-1表示输入结束"<<endl;
            int i = m_nCount;
            for (;i<MAX; ++i)
            {
                cout<<"请输入"<<i<<"号员工的信息"<<endl;
                string strName = "";
                int nL = 0;
                int nY= 0;
                cin>>strName>>nL>>nY;
                if(!cin)  
                {
                    cout<<"输入错误，请重新输入." <<endl;
                    cin.clear();
                    cin.sync();
                    --i;
                    continue;
                }else
                {
                    if("-1" == strName)
                    {
                        break;
                    }
                    // 根据输入的数据，创建具体的员工对象并保存到数组
                    if(enumOfficer == nL)
                        m_arrEmp[i] = new Officer(strName, nY);
                    else if(enumStaff == nL)
                        m_arrEmp[i] = new Staff(strName, nY);
                    else
                    {
                        cout<<"错误的员工级别，请重新输入" <<endl; 
                        --i;
                        cin.clear();
                        cin.sync();
                        continue;
                    }
                    
                }
            }
            // 输入完毕，调整当前数组中的数据量
            m_nCount = i;
            return m_nCount;
        }    


        // 获得最高工资员工的对象
        Employee* GetMax()
        {
            Employee* pMax = nullptr;
            int nMax = INT_MIN;
            for (int i=0;i < m_nCount; ++i)
            {
                if (m_arrEmp[i]->GetSalary()> nMax)
                {
                    pMax = m_arrEmp[i];
                    nMax =pMax->GetSalary();
                }
            }
            return pMax;
        }

        void Find()
        {
            // 构造无线循环进行查询
            while(true)
            {
                string strName = "";
                cout<<"请输入要查询的员工名字(-1表示结束查询):" <<endl;
                cin>>strName;
                if(!cin)
                {
                    cout<<"输入错误请重新输入"<<endl;
                    cin.clear();
                    cin.sync();
                    continue;
                }else if ("-1" == strName)
                {
                    // 查询结束用break结束查询训话
                    cout<<"查询完毕，感谢使用!" <<endl;
                    break;
                }
                // 记录是否找到查询的员工
                bool bFind = false;
                for(int i = 0;i < m_nCount; ++i)
                {
                    Employee* p = m_arrEmp[i];

                    if (strName == p->GetName())
                    {
                        // 输出符合查询条件的员工信息
                        cout<<"员工姓名:"<<p->GetName()<<endl;
                        cout<<"员工工资:"<<p->GetSalary()<<endl;
                        bFind = true;
                        break;
                    }
                }
                if(!bFind)
                {
                    cout<<"无法找到名字为"<<strName<<"的员工."<<endl;
                    cout<<"请核对姓名，重新输入"<<endl;
                }
            }
        }
    // SalarySys类的属性
    // 因为这些属性都只是提供SalarySys类访问
    // 所以其访问级别设定为private
    private:
        // 数据文件名， 为了防止被错误修改，所以使用const关键字修饰
        // 使用const 修饰的成员变量，必须在类构造函数的初始化列表中进行初始化
        // 在C++11中，也可以在定义时直接赋值初始化
        const string m_strFileName;
        Employee* m_arrEmp[MAX]; //保存员工对象指针的数组 
        int m_nCount; // 数组中已有员工对象数
};

// 单例模式实现的SalarySys类

class SalarySysSingle
{
    private:
        SalarySysSingle():m_nCount(0),m_strFileName("SalaryData.txt")
        {
        }

    public:
        static SalarySysSingle* getInstance()
        {
            if(nullptr == m_pInstance)
                m_pInstance = new SalarySysSingle();
            return m_pInstance;
        }
    private:    
        const string m_strFileName;
        Employee* m_arrEmp[MAX]; //保存员工对象指针的数组 
        int m_nCount; // 数组中已有员工对象数
        // FIXME 这里有问题的
        // static SalarySysSingle* m_pInstance = nullptr;
        static SalarySysSingle* m_pInstance;
};
