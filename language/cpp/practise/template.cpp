#include <iostream>
using namespace std;

template <typename T>

const T& mymax(const T& a, const T& b )
{

    return a > b ? a : b ;

}

// 利用模板特化，实现特定的string类型的模板函数

template <>   // 类型参数留空

// 使用实际类型string代替类型参数T

string mymax<string>( const string a, const string b )

{

    // 通过长度比较决定字符串大小

    return a.length() > b.length() ? a : b ;

}

// 定义一个用于比较两个数据大小的类模板
template <typename T>  // T是类模板的类型参数

class compare
{
public:
    // 构造函数，使用T做参数类型，实际上它相当于一个函数模板
    compare(T a, T b)
        :m_a(a),m_b(b)
    {}

	// 比较类的接口函数
public:
    // 返回两个数中的较小值，使用T作返回值类型
    T min()
    {
        return m_a > m_b ? m_b : m_a;
    }

    // 返回两个数中的较大值
    T max()
    {
        return m_a > m_b ? m_a : m_b;
    }
    // 类模板的成员变量，使用T作为其数据类型
private:
    T m_a;
    T m_b;
};
int main()
{
    // 两个int类型数据
    int a = 4;
    int b = 5;
    cout<<a<<"和"<<b<<"之间较大的是"
        <<mymax<int>(a,b)<<endl;// 调用int版本的mymax()处理int类型数据
    // 两个string类型数据
   
    string strA = "good";
    string strB = "afternoon";
    cout<<strA<<"和"<<strB<<"之间较大的是"
        // 调用string版本的mymax()处理string类型数据
       <<mymax<string>(strA,strB)<<endl;
    
    // 要比较两个整型数的大小，
    // 所以使用int作为类模板的实际类型参数
    compare<int> cmpint(2,3); // 定义用于比较两个int数据的compare对象
    // 使用compare<T>的成员函数进行比较
    cout<<cmpint.max()<<"大于"<<cmpint.min()<<endl;

    // 要比较两个字符串的大小，
    // 所以使用string作为类模板的实际类型参数   
    compare<string> cmpstr("good","afternoon");
    cout<<cmpstr.max()<<"大于"<<cmpstr.min()<<endl;

    return 0;
}
