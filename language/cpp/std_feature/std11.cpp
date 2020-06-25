#include "std11.hpp"

using namespace std;


int t_decltype() {
	int a = 10;
	decltype(a) b;
	b = 1;
	return b;
}

string t_auto() {
	auto c = t_decltype();
	auto s1 = "1234";
	return s1;
}

int t_range_for() {
	string str("some string");
	for (auto& c : str)
	{
		c = toupper(c);
	}
	for (auto c : str)
	{
		cout << c << endl;
	}
	return 0;
}

int t_vector() {
	vector<vector<int> > vvi;
	// 新标准版本
	vector<vector<int>> vvi_11;
	// 列表初始化方式
	vector<string> v1{ "a", "an", "the" };

	// v3 有10个元素，每个值都是1
	vector<int> v3(10, 1);
	
	// v4 有2个元素，值分别时10和1
	vector<int> v4{ 10, 1 };
	
	return 0;
}

int t_begin_end() {
	vector<string> v1{ "a", "an", "the" };
	auto b1 = begin(v1);
	auto e1 = end(v1);
	cout << "b1:" << *b1 << "e1:" << *(--e1) << endl;
	return 0;
}

void t_sizeof() {
	// c++11新标准允许我们使用作用域运算符来获取类成员的大小
}

void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
}

vector<string> process(int i) {
	//列表初始化返回值
	if (i > 5) {
		return { "functionX", "okay" };
	}
	else {
		return { "functionX", "123", "test" };
	}
}

int process2() {
	return { 10 };
}

// 尾置返回类型
auto func1(int i) -> int(*)[10];

// 使用decltype简化返回类型定义
int odd[] = { 1, 3, 5, 7, 9 };
int even[] = { 0,2,4,6,8 };

decltype(odd)* arrPtr(int i)
{
	return (i % 2) ? &odd : &even;
}

// constexpr 函数

constexpr int new_sz() {
	return 42;
}
// array
void test_array() {
	std::array<string, 3> a3 = {string("a"), string("b"), string("c")};
	for (const auto& i : a3) {
		cout << "i:" << i << endl;
	}
}

void test_forward_list(){
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2)
			curr = flst.erase_after(prev);
		else {
			prev = curr;
			++curr;
		}
	}

	for (auto& i : flst) {
		cout << i << " ";
	}

	cout << endl;
}

void test_begin_end() {
	list<string> a = { "Milton", "Shakespeare", "Austen" };
	auto it1 = a.begin();
	auto it2 = a.rbegin();
	auto it3 = a.cbegin();
	auto it4 = a.crbegin();
	auto it5 = a.end();
}

void test_swap() {
	list<string> a = { "abc", "123" };
	list<string> b = { "198", "kfdsi" };
	std:swap(a, b);
	cout << "a is:" << endl;
	for (auto& s : a) {
		cout << s << " ";
	}
	cout << endl;
	cout << "b is:" << endl;

	for (auto& s : b) {
		cout << s << " ";
	}
	cout << endl;
}

void test_insert() {
	list<string> lst;
	auto iter = lst.begin();
	string word;
	while (cin >> word) {
		iter = lst.insert(iter, word);
	}

	for (auto& w : lst) {
		cout << w << " ";
	}
	cout << endl;
}

// lambda 表达式

void test_lambda() {

	auto f = [] {return 42; };
	cout << "lambda:" << f() << endl;
	// 向lambda传递参数
	auto cmp = [](const string& a, const string& b) {
		return a.size() < b.size();
	};
	cout << "cmp:" << cmp("123", "456") << endl;
	cout << "cmp:" << cmp("bbb", "aaaa") << endl;

	// 使用捕获列表
	string sz = "sasa";
	auto l1 = [sz](const string& a) -> int {
		return a.size() >= sz.size();
	};
	cout << "l1:" << l1("hello world!!!!") << endl;
}

int t_std11() {
	auto t1 = t_decltype();
	auto t2 = t_auto();
	std::cout << "t1:" << typeid(t1).name() << " "<< "t2:" << typeid(t2).name() << std::endl;
	t_range_for();
	t_begin_end();
	// 大括号赋值
	float k = { 3.214 };
	vector<int> v1;
	v1 = { 0, 1,2, 3,4,5, 6 };
	error_msg({ "functionX", "expected", "actual" });
	error_msg({ "functionX", "okay" });
	int p2 = process2();
	cout << "p2:" << p2 << endl;
	test_array();
	test_forward_list();
	test_swap();
	// test_insert();
	test_lambda();
	return 0;
}
