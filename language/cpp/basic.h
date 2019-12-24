#ifndef BASIC_H
#define BASIC_H

#include<random>
#include<iostream>
#include <cstring>
#include<exception>
#include<sstream>
#include<string>
#include<initializer_list>

using namespace std;

int t_random();
int t_const();

// 常量
#define PI 3.14159
const double PI_ = 3.14159;

// 数值数据类型
// int,4字节
// short,short int,短整型,2字节
// long,long int, 长整型,64位系统8字节,32位系统4字节
// long long, 8字节
// signed 有符号, unsigned无符号
// float ,单精度, 4字节
// double, 双精度, 8字节
// long double, 长双精度, 12字节

// bool 布尔类型

// 字符和字符串
// char, 1字节
// wchar_t, 2字节
// string
// wstring

// auto
// auto x = 7; // x被推断为int类型
// auto y = 1.982; // y被推断为double类型

// 数组
// int arrSalary[10000];
// int nArray[5] = {1,2,3,4,5};
// int nBigArray[100] = {0};

// 枚举类型
enum TrafficLight2{
    RED,
    GREEN,
    YELLOW
};
// 带作用域的枚举, 使用char比int节省资源
enum class TrafficLight : char
{
    RED = 1, // 红
    GERRN,  // 绿
    YELLOW  // 黄
};

// 定义结构体Human描述人这个复杂事物
struct Human
{
    string   m_strName;          // 姓名
    bool     m_bMale;            // 性别
    int      m_nAge;             // 年龄
    int      m_nHeight;          // 身高
    float    m_fWeight;         // 体重
};


// 空指针 nullptr
// int* pN;
// if (nullptr != pN){

// }

// * 指针运算符，解析运算符


// 异常

class interator_overflow:public exception{
    public:
        interator_overflow(int index, int max)
                        :_index(index), _max(max)
                        {}
        int index(){
            return _index;
        }
        int max(){
            return _max;
        }

        const char* what() const throw();
    private:
        int _index;
        int _max;

};

void test_textblock();

class Teacher
{

    // 友元
    // 友元关系不能被继承
    // 声明TaxationDep类为友元类
    friend class TaxationDep;
    // 声明AdjustSalary()函数为友元函数
    friend int AdjustSalary(Teacher* teacher);

    // 当一个使用定义变量的形式创建的对象使用完毕离开其作用域之后，这个对象会被自动销毁。
    // 而对于使用new关键字创建的对象，则需要在使用完毕后，通过delete关键字主动销毁对象

    public:
        // Teacher(string strName){
        //     m_strName = strName;
        // }
        Teacher(string strName, int iAge):m_strName(strName), m_age(iAge){

        }

        Teacher(int x)
        {
            // 判断参数是否合理，决定赋值与否
            if (0 < x && x <= 100)
                m_age = x;
            else
                cout<<"错误的年龄参数"<<endl;
        }

        // 构造函数Teacher()委托调用构造函数Teacher(int x)
        // 这里我们错误地把出生年份当作年龄参数委托调用构造函数Teacher(int x)，
        // 直接实现了参数合法性验证并赋值的功能, 仅在C++11 中支持
        Teacher():Teacher(1982)
        {
            // 完成特有的创建工作
        }

        // 拷贝构造函数


        void GiveLesson();

    protected:
    // 保护类型成员
// 不能被外界访问，但是可以被自身访问，也可以遗传给下一级子类，
// 供下一级子类访问
// 只有自己备课，子类也需要备课，所以设置为保护类型
    void PrepareLesson()
    {
        cout<<"老师备课。"<<endl;
    }
    string m_strName = "ChenLiangqiao";
    int m_age = 0;

    private:
   int m_nWallet; // 钱包只有自己可以访问，所以设置为私有类型
   int m_nSalary; // 保护类型的成员

};
class TaxationDep
{
// 类的其他定义…
public:
    void CheckSalary( Teacher* teacher )
    {
        // 在Teacher类的友元类中访问它的保护类型成员m_nSalary
        if(teacher != nullptr && teacher->m_nSalary > 1000)
        {
            cout<<"这位老师应该交税"<<endl;
      }
    }
};

struct Rect
{
    // 默认是公用属性public类型

    int GetArea()
    {
        return m_nW * m_nH;
    }
    int m_nW;
    int m_nH;
};
// Rect rect1;
// rect1.m_nH = 0;
// rect1.m_nW = 0;
// rect1.GetArea();
// new 关键字创建的对象无法在其生命周期结束后自动销毁,所以我们必须在对象使用完毕后,用delete关键字人为地销毁这个对象,释放其占用的内存

class Sheep
{
    // 禁用类的默认赋值操作符
    Sheep& operator = (const Sheep&) = delete;
    // 禁用类的默认拷贝构造函数
    Sheep(const Sheep&) = delete;
};

// 键盘类
struct KeyBoard
{
    // 键盘类型
    string m_strModel;
};

class Computer
{
    public:
        // 默认构造函数
        Computer():m_pKeyboard(nullptr), m_strModel("")
        {

        }
        // 拷贝构造函数，参数是const修饰的Computer类的引用

        Computer(const Computer& com):m_strModel(com.m_strModel){
            // 直接使用初始化列表完成对象类型成员变量m_strModel的复制
            KeyBoard* pOldKeyboard = com.GetKeyboard();
            // 以pOldKeyboard所指向的Keyboard对象为蓝本，
            // 创建一个新的Keyboard对象，并让m_Keyboard指向这个对象
            if (nullptr != pOldKeyboard)
            {
                //
                m_pKeyboard = new KeyBoard(*(pOldKeyboard));
            }else
                m_pKeyboard = nullptr;
        }

        // 自定义的赋值操作符
        Computer& operator=(const Computer& com)
        {
            // 判断是否是自己给自己赋值
            // 如果是自赋值，则直接返回自己本身
            //
            if (this==&com) return *this;
            m_strModel = com.m_strModel;
            m_pKeyboard = new KeyBoard(*(com.GetKeyboard()));
        }

        // 析构函数
        // 对于对象类型的成员变量m_strModel,会自动被销毁，无需在析构函数中进行处理
        // 对于指针类型的成员变量m_pKeyboard, 则需要在析构函数中主动销毁
        ~Computer()
        {
            delete m_pKeyboard;
            m_pKeyboard = nullptr;
        }

        // 成员函数，设置或获得键盘对象指针
        void SetKeyborad(KeyBoard* pKeyboard){
            m_pKeyboard = pKeyboard;
        }

        KeyBoard* GetKeyboard() const{
            return m_pKeyboard;
        }
    private:
        KeyBoard* m_pKeyboard;
        string m_strModel;
};

class Salary
{
    public:
        Salary(initializer_list<int> s){
            for(int i:s)
                m_vecSalary.push_back(i);
        }
        int GetSalary()
        {
            int nTotal = 0;
            for (int i:m_vecSalary)
                nTotal += i;
            return nTotal;
        }
        // 以初始化列表为参数的普通函数
        void AddSalary(initializer_list<int> s)
        {
            for (int i:s)
                m_vecSalary.push_back(i);
        }


    private:
        vector<int> m_vecSalary;
};
// "{}" 表示初始化列表
// Salary sWang{5000,9500,1003};
// sWang.AddSalary({8200,6500});

class Mother{

};

class Baby{
    public:
        Baby(string strName):m_strName(strName){

        }
    private:
        string m_strName;
};

class Father{
    public:
        Baby operator+ (const Mother){
            return Baby("miaomiao");
        }
};

// 用Teacher类封装老师的属性和行为
class TeacherNew
{
// 构造函数
public:
    // 根据名字构造老师对象
    TeacherNew(string strName)
    {
            m_strName = strName;
    };

// 用成员函数描述老师的行为
public:
    void PrepareLesson();      // 备课
    void GiveLesson();          // 上课
    void ReviewHomework();     // 批改作业
    // 其它成员函数…
    // 用成员变量描述老师的属性
protected:
    string    m_strName;        // 姓名
    int        m_nAge;            // 年龄
    bool       m_bMale;           // 性别
    int        m_nDuty;           // 职务
private:
};


// 定义基类Human
class Human2
{
// 人类共有的行为，可以被外界访问，
// 访问级别设置为public级别
public:
    void Walk();               // 走路
    void Talk();               // 说话
    // 人类共有的属性
    // 因为需要遗传给派生类同时又防止外界的访问，
    // 所以将其访问级别设置为protected类型
protected:
    string   m_strName;         // 姓名
    int      m_nAge;            // 年龄
    bool     m_bMale;           // 性别
private:   // 没有私有成员
};

// Teacher跟Human是“is-a”的关系，
// 所以Teacher采用public继承方式继承Human
class Teacher2 : public Human2
{
    // 在子类中添加老师特有的行为
public:
    void PrepareLesson();      // 备课
    void GiveLesson();          // 上课
    void ReviewHomework();     // 批改作业
// 在子类中添加老师特有的属性
protected:
    int    m_nDuty;             // 职务
private:
};

// 学生同样是人类，public继承方式继承Human类
class Student : public Human
{
// 在子类中添加学生特有的行为
public:
    void AttendClass();        // 上课
    void DoHomework();         // 做家庭作业
   // 在子类中添加学生特有的属性
protected:
    int m_nScore;                // 考试成绩
private:
};

// 小学生是学生，所以public继承方式继承Student类
class Pupil : public Student
{
// 在子类中添加小学生特有的行为
public:
    void PlayGame();           // 玩游戏
    void WatchTV();            // 看电视
public:
    // 对“做作业”的行为重新定义
    void DoHomework();
protected:
private:
};


// 键盘
class Keyboard
{
public:
    // 接收用户键盘输入
    void Input()
   {
         cout<<"键盘输入"<<endl;
    }
};

// 显示器
class Monitor
{
public:
    // 显示画面
    void Display()
    {
          cout<<"显示器输出"<<endl;
    }
};

// 电脑
class ComputerNew
{
public:
    // 用键盘、显示器组合一台电脑
    ComputerNew( Keyboard* pKeyboard,
                Monitor* pMonitor )
    {
        m_pKeyboard = pKeyboard;
        m_pMonitor = pMonitor;
    }
    // 电脑的行为
    // 其具体动作都交由其各个组成部分来完成
    // 键盘负责用户输入
    void Input()
    {
        m_pKeyboard->Input();
    }

    // 显示器负责显示画面
    void Display()
    {
        m_pMonitor->Display();
    }

// 电脑的各个组成部分
private:
    Keyboard*  m_pKeyboard = nullptr;  // 键盘
     Monitor*   m_pMonitor = nullptr;  // 显示器
// 其他组成部件对象
};

// int main()
// {
//      // 先创建键盘和显示器对象
//      Keyboard  keyboard;
//     Monitor monitor;

//     //  用键盘和显示器对象组合成电脑
//     Computer com(&keyboard,&monitor);

//     // 电脑的输入和输出，实际上最终是交由键盘和显示器去完成
//     com.Input();
//     com.Display();

//     return 0;
// }
// 虚函数virtual
// 像这种在派生类中利用虚函数对基类的成员函数进行重新定义，并在运行时刻根据实际的对象来决定调用哪一个函数的机制，被称为函数重写（override） 。
// 重载（overload）是一个编译时概念，它发生在代码的同一层级。它表示在代码的同一层级（同一名字空间或者同一个类）中，一个函数因参数类型与个数不同可以有多个不同的实现。在编译时刻，编译器会根据函数调用的实际参数类型和个数来决定调用哪一个重载函数版本。

// 重写（override）是一个运行时概念，它发生在代码的不同层级（基类和派生类之间）。它表示在派生类中对基类中的虚函数进行重新定义，两者的函数名、参数类型和个数都完全相同，只是具体实现不同。而在运行时刻，如果是通过基类指针调用虚函数，它会根据这个指针实际指向的具体对象类型来选择调用基类或是派生类的重写函数

// 同一层级的两个同名函数因参数不同而形成重载
// 同一层级的两个同名函数因参数不同而形成重载
class HumanNew
{
public:
    virtual void Talk()
    {
           cout<<"Ahaa"<<endl;
    }

    virtual void Talk(string msg)
    {
        cout<<msg<<endl;
    }
};

// 不同层级的两个同名且参数相同的函数形成重写
class BabyNew : public HumanNew
{
public:
    virtual void Talk()
    {
        cout<<"Ma-Ma"<<endl;
    }
};


// int test_overload()
// {
//     HumanNew MrChen;
//     // 根据参数的不同来决定具体调用的重载函数，在编译时刻决定
// MrChen.Talk();   // 调用无参数的Talk()
//     MrChen.Talk("Balala"); // 调用以string为参数的Talk(string)

// HumanNew* pBaby = new BabyNew();
// // 根据指针指向的实际对象的不同来决定具体调用的重写函数，在运行时刻决定
// pBaby->Talk(); // 调用Baby类的Talk()函数

//     delete pBaby;
//     pBaby = nullptr;

//     return 0;
// }

// 纯虚函数
// 使用纯虚函数BuyTicket()作为接口的Human类
class HumanPurity
{
// Human类的行为
public:
    // 声明BuyTicket()函数为纯虚函数
    // 在代码中，我们在函数声明后加上“= 0”来表示它是一个纯虚函数
    virtual void BuyTicket() = 0;
};
// 在基类构造或析构期间，虚函数是被禁止的。
// 为什么会有这么奇怪的行为？这是因为，在创建一个派生类的对象时，基类的构造函数是先于派生类的构造函数被执行的，如果我们在基类的构造函数中调用派生类重写的虚函数，而此时派生类对象尚未创建完成，其数据成员尚未被初始化，派生类的虚函数执行或多或少会涉及到它的数据成员，而对未初始化的数据成员进行访问，无疑是一场恶梦的开始
// 最好的方法就是，不要在基类的构造函数和析构函数中调用虚函数


// override
// final

int test_string2();
int test_string_3();
int test_string_4();

#endif
