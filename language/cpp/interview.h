
#include<cstring>
#include<cstdio>
#include<pthread.h>
#include<stdexcept>

using namespace std;
void Test7_1();
void Test7_5();
void Test8_15();
void Test8_7();
int AddFrom1ToN_recursive(int n);
int get_fib(int n);
// 重载操作符
class CMyString
{
    public:
        CMyString(char* pData = nullptr);
        CMyString(const CMyString& str);
        ~CMyString(void);

        CMyString& operator= (const CMyString& str);
        void Print();
    private:
        char* m_pData;
};
void Test1();

// 单例模式
// 非线程安全模式
class Singleton{
    public:
        static Singleton* instance();
    protected:
        Singleton(){}
    private:
        static Singleton *p;
};
// 线程安全模式，懒汉
class SingletonSafe{
    public:
        static SingletonSafe* instance();
        static pthread_mutex_t mutex;
    protected:
        SingletonSafe(){}
    private:
        static SingletonSafe* p;
};
// 饿汉模式,最方面，上来就初始化
class SingletonHungry{
    protected:
        SingletonHungry(){}
    private:
        static SingletonHungry* p;
    public:
        static SingletonHungry *instance();
};

// 链表定义
struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};



