#include "dynamically_mem_12.h"

void dynamicall_mem_12_test() {
	// ָ��һ��ֵΪ42��int��shared_ptr
	shared_ptr<int> p3 = make_shared<int>(42);

	shared_ptr<string> p4 = make_shared<string>(10, "9");

	// ָ��һ����ʼ��ֵ
	shared_ptr<int> p5 = make_shared<int>();

	// p6 ָ��һ����̬����յ�vector<string>

	auto p6 = make_shared<vector<string>>();

	// q6 p6 ָ����ͬ���󣬴˶��������������� 
	auto q6(p6);

	
}