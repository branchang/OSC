#include <stdio.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <string>
#include <iostream>
#include <vector>

// 内联 inline函数,内联对编译器只是建议，它不一定会这么做
#define min(x,y) ((x)<(y)?(x):(y))

inline int min_best(int x, int y){
    return x < y ? x : y;

}

class Mutex {
    public:
        // 构造函数和析构函数没有返回值，不能在函数名前面加void
        // 构造函数在内部是匿名的,不能直接调用
        // C++ 类内部定义的函数，默认是内联的， 经过编译器优化后，不会有任何额外的函数调用开销
        Mutex() {
                pthread_mutex_init(&_mutex, NULL);
        }
        // 析构函数不带参数
        ~Mutex(){
                pthread_mutex_destroy(&_mutex);
        }
        void lock() {
            pthread_mutex_lock(&_mutex);
        }
        void unlock() {
            pthread_mutex_unlock(&_mutex);
        }

        int print_mutex(std::string s);
    private:
        pthread_mutex_t _mutex;

};

// 类函数的成员也可以在类外定义
// 如果希望编译器内联它，必须显示声明为inline
inline int Mutex::print_mutex(std::string s){
    std::cout<<s<<std::endl;
    return 0;
}

// 函数的重载只与函数的参数有关，而与函数的返回值无关
/*
 在C中函数是全局唯一的,因此可以用函数名标志函数地址,在c++中引入函数重载后,
 函数名的全局唯一性被破坏了,不可能用不同一个名字,标志多个重载函数的地址
 才用了name mangling机制, 重载的同名函数
*/
int test_mutex(){
    Mutex mutex;
    mutex.lock();
    printf("%s", "hello");
    mutex.unlock();
    return 0;
}


void f(const int& v){

}

void g(int& v){

}

void test_reference(){
    // 引用的本质上就是给一块内存绑定一个新的名字
    int x = 3;
    int& y = x;
    int* z = &x;
    y = 7;
    *z = 10;
/* 指针也是变量，本质上也是一块内存，只不过内存中存储的是某个变量的地址.
现在再来看引用。考虑上面的代码 int& y = x; ，编译器在这里并没有分配内存，
它只是将名字 y 也绑定到变量 x 所表 示的内存上，所以通过名字 y 也可以操作 x 所表示的内存
引用并不是一种类型,引用只是给某块内存绑定了一个新的名字 */

/*
C++中定义引用时，必须初始化，并且初始化后，没办法更改，不可能再让它引用别的变量
*/
    // int& a;  没有初始化
    // int& b=7; 引用必须绑定一块内存
    const int xx = 3;
    // int& yy = xx; // 通过 y 可以修改 x 在内存中的值，但 x 是常量，编译器报
    int ii = 3;
    // double& d = i; // double& 不能引用int类型的变量

    // const 引用
    // 引用可以用const修饰， const引用对外宣称它引用的是const对象，不能通过它改变这个对象
    //const 引用可以引用变量、常量，甚至像 7 这样的字面常量，只是不能通过它修改所引用的变量或对象。
    int a = 3;
    const int b = 3;
    const int& xxx = a; //ok.x是a的一个引用，但不能通过x修改a
    const int& yyy = b; // ok
    const int& zzz =7; // ok. 编译器生成一个临时变量保存 7 这个值，z 引用的是临时变量
    // xxx = 7;  // // ko. 不能通过 const 引用修改变量的值
    // 函数参数中传递引用
    f(3); // ok. 参数名 v 被绑定到临时变量所对应的那块内存
    f(ii); // ok. 参数名 v 被绑定到变量 ii 所对应的那块内存
    f(xx); // ok. 参数名 v 被绑定到常量 xx 所对应的那块内存

    // g(3); // ko. 非 const 引用不能引用字面常量
    g(ii); // ok. 参数名 v 被绑定到变量 x 所对应的那块内存
    // g(xx); // ko. 非 const 引用不能引用常量
}


// 拷贝构造函数与赋值操作
class Apple {
    public:
        Apple() {
            _v = 0;
        }
        Apple(int v){
            _v = v;
        }
        Apple(const Apple& another){
            if (this == &another) return ; //防止自我拷贝
            _v = another._v;
        }

        Apple& operator=(const Apple& another) {
            if (this == &another) return *this; //防止自我拷贝
            _v = another._v;
            return *this;
        }

    private:
        int _v;
};

// 模板

// 函数模板
template<typename T>
inline T add(T x, T y){
    return x+y;
}
// 上面定义了一个函数模板，调用   时，编译器会生成实际的代码:
inline int add(int x, int y){
    return x + y;
}
// 同理，调用 add(1.0, 2.3) 时，编译器则会生成 double 版的代码。

// 类模板
template <typename T>
class unique_ptr {
    public:
        unique_ptr(T* ptr=0){
            _ptr = ptr;
        }

        ~unique_ptr(){
            delete _ptr;  //释放内存,delete NULL 不会有问题
        }

        T* get() const { // const 成员函数表示不修改类中的数据
            return _ptr;
        }

        // 重载操作符->与*使得unique_ptr的行为更像指针
        T* operator->() const {
            return _ptr;
        }

        T& operator*() const{
            return *_ptr;
        }

        void reset(T* ptr=0){
            delete _ptr;
            ptr = _ptr;
        }

        // 交出指针的所有权
        T* release() {
            T* ptr = _ptr;
            _ptr = 0;
            return ptr;
        }

    private:
        T* _ptr;
};

void test_unique_ptr(){
    unique_ptr<int> pi(new int(7));
    std::cout<<"*pi = "<<*pi<<std::endl; // *pi 等价于pi.operator*()

    unique_ptr<Apple> pa(new Apple);
    // pa->turn_red(); // 假设 apple类有一个turn_red的方法
    // pa.operator->()->turn_red(); // 等价于上面的调用方式

}

// 命名空间
// 在namespace str 中声明 split 函数
namespace str_t{
    std::vector<std::string> split(const std::string& s, char sep);
}


namespace  xx=::std; // 给std取别名，::表示全局空间
using namespace std; // 将std中的名字全部引入当前命名空间，不推荐
using std::cout;
using std::endl;

void test_namespace(){
    // str_t::split("hello world", ' ');
}

// 策略模式
class Date{
    public:
        virtual void dateAGirl() = 0;
};


class DateAGirlInThePark:public Date{
    public:
        void dateAGirl(){
            std::cout<<"I hooked up with a girl in the park";
            std::cout<<std::endl;
        }
};

class DateAGirlInTheBar:public Date{
    public:
        void dateAGirl(){
            std::cout<<"I hooked up with a girl in the bar";
            std::cout<<std::endl;
        }
};

// 适配器模式
class AdapteeDate{
    public:
        void concreteFindAGirl(){
            cout << "I find a girl"<<endl;
            cout << "I say hi to her to ask for her wechat.";
            cout << endl;
            cout << "I often chated with her throght wechat.";
            cout << endl;
        }
};

class Date1{
    public:
        virtual void findAGirl(){};
};

class AdapterDate:public AdapteeDate,public Date1{
    public:
        void findAGirl(){
            this->concreteFindAGirl();
        }
};
void test_apater(){
    Date1 *date = new AdapterDate();
    date->findAGirl();
}

// 继承
// 单继承
// 多继承
// 继承级别public, protected, private
// virtual 继承
/*
public 继承最常用，基类成员的访问权限在子类中保持不变.
protected继承很少用，基类public成员在子类中都变成protected成员.
private 继承偶尔会用到，基类的所有成员再子类中都变成private成员.
而引入virtual继承，则是为了解决多继承中的菱形继承问题,实际代码中很少遇到这种问题.
用继承写出的代码，可读性比较差，不容易理解，再实际项目中的建议：
1.尽量用组合取代继承
2.尽量避免使用多继承
3.尽量避免三层以上的继承关系
*/
class A{

};
//继承
class B:public A{

};
// 组合
class B2{
    A _a;
};

//组合比继承更灵活，可以只保存对象的指针，以减轻代码的耦合性
class B3{
    A* _a;
};

/* 虚函数 */
//C++引入虚函数virtual function的目的很简单，就是为了解决用基类指针或引用调用子类房的问题

class VA{
    public:
        VA(){

            std::cout << "A() is called" << std::endl;
        }

        // ~VA(){
        virtual ~VA(){
            std::cout << "~A() is called" <<std::endl;
        }

        void fun(){
            std::cout<<"A:func() is called" <<std::endl;
        }
        virtual void vfun(){
            std::cout<<"A:vfunc() is called" << std::endl;
        }
};

class VB:public VA{
    public:
        VB(){

            std::cout << "B() is called" << std::endl;
        }

        // ~VB(){
        virtual ~VB(){
            std::cout << "~B() is called" <<std::endl;
        }

        void fun(){
            std::cout<<"B::fun() is called" << std::endl;
        }
        void vfun() override{
            std::cout<<"B::vfun() is called"<<std::endl;
        }
};

int test_virtual_func(){
    VB b;
    VA* pa = &b;
    VA& ra = b;
    pa->fun();
    ra.fun();
    pa->vfun();
    ra.vfun();
    return 0;
    // 没有虚函数的机制，上述始终被静态绑定(编译期绑定)到基类A中的版本，而不会调用子类B中的
}

int destructor_virtual_test(){
    // 可以看到，尽管 pa 实际指向的是 B 类对象， delete pa 时调用的却是 A 的析构函数。因为 A 的析构函数不是 virtual 的，编译器执行的是静态绑定。
    // 类中含有虚函数时，其析构函数一般也是virtual的，不然delete指向子类对象的基类指针时，子类的析构函数不会被调用
    VA* pa = new VB;
    delete pa;
    return 0;
}
// 虚函数的内部实现
// 虚函数表 virtual table ,保存类中可以调用的虚函数地址,编译器会在类中，插入一个指针vptr,指向类的虚函数表

class VVA{
    public:
        virtual void f1(){}
        virtual void f2(){}
};

class VVB:public VVA{
    public:
        virtual void f1(){}
};

class VVC:public VVA {
    public:
        virtual void f2();
};
// VVA,VVB,VVC  三个类的vptr与vtbl分别如下
/*
A::_vptr  ->       vtbl_A
               --------------
                    vp1 -> A::f1
                    vp2 -> A::f2

B::_vptr -> vtbl_B
                --------------
                vp1 -> B::f1  // 覆盖 A::f1
                vp2 -> A::f2  // 继承 A::f2

C::_vptr ->  vtbl_C
                --------------
                vp1 -> A::f1  // 继承 A::f1
                vp2 -> C::f2  // 覆盖 A::f2


B b;   //_vptr -> vtbl_B
A* pa = &b;
pa->f1(); // (*pa->_vptr[0])() 实际调用的是 vtbl_B 中 vp1 指向的 B::f1
pa->f2();  // (*pa->_vptr[1])() 实际调用的是 vtbl_B 中 vp2 指向的 A::f2

/*
纯虚函数
含有纯虚函数的类，被称为抽象类，不允许实例化，既不能创建抽象类的对象。
不能创建对象的类，有什么用？对外提供统一的抽象接口，而由子类实现这些接口。
*/

class X {
    public:
        virtual void xx()=0;  // 函数声明后面加上=0,表示纯虚函数
};

class AbstractFs{
    public:
        virtual ~AbstractFs(){}

        virtual void create() = 0;
        virtual void open() = 0;
        virtual void read() = 0;
        virtual void write() = 0;
        virtual void close() = 0;
};


// 实现一种文件系统
class Ext4Fs:public AbstractFs{
    // 实现文件系统的操作
    public:
        void create(){
        }
};

// 给一种文件系统添加输入，输出日志
class DebugFs:public AbstractFs{
    public:
        virtual void created(){
            // 打印create 的输入参数
            _fs->create();
            // 打印create的输出结果
        }
    private:
        AbstractFs _fs; // 指向已经实现的一种文件系统

};
