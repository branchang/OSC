#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <forward_list>
#include <typeinfo>
#include <list>


// ����Ĭ�Ϲ��캯��
class DefaultConstructorTest {

public:
	DefaultConstructorTest() = default;

	DefaultConstructorTest(std::string name) {
		name = name;
	}

private:
	std::string name;
};


// ί�й��캯��
class Sales_data_delegating {
public:
	Sales_data_delegating(std::string s, unsigned cnt, double price):
						bookNo(s), units_sold(cnt), revenue(cnt*price) {}

	//���๹�캯��ȫ��ί�и���һ�����캯��

	Sales_data_delegating() : Sales_data_delegating("", 0, 0) {}

	Sales_data_delegating(std::string s): Sales_data_delegating(s, 0, 0){}

	Sales_data_delegating(std::istream& is) : Sales_data_delegating() {
		//read(is, *this);
	}


private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};


class DebugConstexpr {

public:
	constexpr DebugConstexpr(bool b=true): hw(b), io(b), other(b) {}
	constexpr DebugConstexpr(bool h, bool i, bool o):
		hw(h), io(i), other(o) {}


	constexpr bool any() {
		return hw || io || other;
	}

	void set_io(bool b) {
		io = b;

	}

	void set_hw(bool b) {
		hw = b;
	}

	void set_other(bool b) {
		other = b;
	}
	
private:
	bool hw;
	bool io;
	bool other;
};

int t_std11();
