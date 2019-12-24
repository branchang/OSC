#include "cpprimer.h"
void init_multiple_var(){
    double salary = 99999.9;
    int interval, month=8, day = 7, year = 1955;
    std::string title("CPP PRIMER"), publisher = "A-W";
}

void init_const_var(){
    const int bufSize = 512;
    const std::string hi = "hello";
    // 错误const定义的不能修改
    // bufSize = 19;
    // i未初始化
    // const int i, j = 10;
    //
}
// 可以被全局访问，不是当前文件的程序也可以通过 extern const int bufSize2;声明使用
// 非 const 变量默认为 extern。要使 const 变量能够在其他的文件中访问，必须地指定它为 extern。
extern const int bufSize2 = 1024;
int bufSize3 = 256;


// 引用

void reference_test(){
    int ival = 1024;
    int &refVal = ival;
    // 错误 引用必须初始化
    // int &refVal2;
    // 错误，引用初始化必须是一个对象
    // int &refVal3 = 10;
    refVal += 1;
    int ii = refVal;
    int jj = 102;
    refVal = jj;
    std::cout<< "ival:"<<ival<<"refval:"<<refVal<<"ii:"<<ii<<std::endl;

    // defining multiple reference
    int i = 1024, i2= 2048;
    int &r = i, r2 = i2; // r is ref, r2 is an int
    int i3 = 1024, &ri = i3; // defines one object and one reference
    int &r3 = i3, &r4 = i2; // defines two reference
    // const reference is a reference that may refer to a const object
    const int inval = 100;
    const int &refcval = inval;
    // int &refval2 = inval;  // error
    // refcval = 199;
    // const 引用可以初始化为不同类型的对象或者初始化为右值
    int i31 = 42;
    const int &r33 =42;
    // 编译器会转码成如下形式
    int temp3 = 42;
    const int &r35 = temp3;
    //
    const int &r34 = r33+1;
    int t1 , &rt1 = t1;
    t1 = 5; rt1=10;
    std::cout<< t1 <<" "<<rt1<<std::endl;
}

void typedef_test(){
    // a typedef lets us define a synonym for a type
    // typedef 定义以关键字 typedef 开始，后面是数据类型和标识符
    typedef double wages;
    typedef int exam_score;
    typedef wages salery;
    wages hourly, weekly;
    exam_score test_results;
}
//  enumerations
void enum_test(){
    enum open_modes {
        input,
        output,
        append
    };

    // 枚举成员值可以是不唯一的
    enum Points {
        point2d = 2,
        point2w,
        point3d = 3,
        point4w
    };

    Points p1 = point2d;
    Points p2 = p1;
    open_modes om = input;
}

int cpp_primer_test(){
    reference_test();
    return 0;
}
