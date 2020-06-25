#include "dynamically_mem_12.h"

void dynamicall_mem_12_test() {
	// 指向一个值为42的int的shared_ptr
	shared_ptr<int> p3 = make_shared<int>(42);

	shared_ptr<string> p4 = make_shared<string>(10, "9");

	// 指向一个初始化值
	shared_ptr<int> p5 = make_shared<int>();

	// p6 指向一个动态分配空的vector<string>

	auto p6 = make_shared<vector<string>>();

	// q6 p6 指向相同对象，此对象有两个引用者 
	auto q6(p6);

	
}