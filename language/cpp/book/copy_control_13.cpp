#include "copy_control_13.h"

unsigned Employee::_no = 0;

LikeValHasPtr& LikeValHasPtr::operator=(const LikeValHasPtr& rhs)
{
	auto newps = new std::string(*(rhs.ps));
	delete ps;
	ps = newps;
	i = rhs.i;

	return *this;
}

int parameter_xxx(XXX p1, XXX& p2) {
	std::cout << "paramerter" << std::endl;
	return 0;
}

int container_xxx() {
	std::vector<XXX> v1;
	XXX x1(8);
	v1.push_back(x1);
	std::cout << "-----end for vector------" << std::endl;
	std::map<int, XXX> m1;
	m1.insert(std::make_pair(1, x1));
	std::cout << "------ end for container------" << std::endl;
	return 0;
}

void f1(XXX x) {

}
void f2(XXX& x) {

}

int ex_13_13() {
	std::cout << "ex 13 13 --------------------" << std::endl;
	XXX a0;
	std::cout << std::endl;
	XXX a1(1);
	cout << endl;

	a0.No = 2;
	XXX a2(a0);
	cout << endl;

	a2.No = 3;
	XXX a3 = a2;
	cout << endl;

	a3 = XXX(4);
	cout << endl;
	
	f1(a0);
	f2(a0);

	return 0;
}

void f_numbered(numbered s) {
	cout << "f numbered mysn:" <<s.get_mysn() << endl;
}

void t_numbered()
{
	numbered a, b = a, c = b;
	f_numbered(a);
	f_numbered(b);
	f_numbered(c);
}

void t_rand_t()
{
	
	std::cout << "--------rand()------------" << std::endl;
	int i;
	srand(time(nullptr));
	for (i = 0; i < 10; i++) printf("->%d\n", rand());
}

void test_copy_control() {
	XXX t1(9);
	std::cout << "--------------------" << std::endl;
	XXX t2 = t1;
	t2 = t1;
	std::cout << "--------------------" << std::endl;
	parameter_xxx(t1, t2);
	std::cout << "---test container------" << std::endl;
	container_xxx();

	ex_13_13();
	
	t_rand_t();
	t_numbered();


}