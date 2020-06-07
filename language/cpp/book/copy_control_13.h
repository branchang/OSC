
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

struct XXX {
	XXX(int i=0):No(i) {
		std::cout << "XXX():" << No<<std::endl;
	}

	XXX(const XXX& cpy) {
		No = cpy.No;
		std::cout << "XXX(const XXX&):" << No << std::endl;
	}

	XXX& operator=(const XXX& cpy) {
		No = cpy.No;
		std::cout << "XXX& operator=(const XXX&):" << No<< std::endl;
		return *this;
	}
	~XXX() {
		std::cout << "~XXX()" << No<<std::endl;
	}

	unsigned No;
};

class numbered {
public:
	numbered() {
		srand(time(0));
		mysn = (unsigned)rand();
		cout << "init mysn:" << mysn << endl;
	}
	numbered(const numbered& cpy) {
		srand(time(0)+cpy.mysn);
		mysn = (unsigned)rand();
		cout << "copy mysn:" << mysn << endl;
	}

	unsigned get_mysn() const {
		return mysn;
	}

private:
	unsigned mysn;
};


class Employee {
public:
	Employee(){
		_no++;
		no = _no;
	}
	Employee(string n):name(n){
		_no++;
		no = _no;
	}
	Employee(const Employee& cpy) {
		name = cpy.name;
		_no++;
		no = _no;
	}

private:
	string name;
	unsigned no;
	static unsigned _no;
};

unsigned Employee::_no = 0;


class LikeValHasPtr {

public:
	LikeValHasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}

	LikeValHasPtr(const LikeValHasPtr& hp) :
		ps(new std::string(*(hp.ps))), i(hp.i) {}

	LikeValHasPtr& operator=(const LikeValHasPtr&);
	~LikeValHasPtr() {
		delete ps;

	}
private:
	std::string* ps;
	int i;
};

LikeValHasPtr& LikeValHasPtr::operator=(const LikeValHasPtr& rhs)
{
	auto newps = new std::string(*(rhs.ps));
	delete ps;
	ps = newps;
	i = rhs.i;
	return *this;
}

void test_copy_control();
