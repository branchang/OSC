#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void test_const_var();
int cpp_primer_test();

class person {
 public:
  person(string n, string a) : name(n), address(a) {}

  string get_name() const { return name; }
  string get_address() const { return address; }

 private:
  string name;
  string address;
};

class Screen {
 public:
  typedef std::string::size_type index;
  Screen(std::string c, index ht, index wd):contents(c), height(ht), width(wd) {}
  char get() const {}
  char get(index ht, index wd) const;

  Screen& move(index ht, index wd);

  Screen& set(char c);

  Screen& display(std::ostream &os);

  const Screen& display(std::ostream &os) const;

 private:
  std::string contents;
  index cursor;
  index height, width;
};

class Foo{
  public:
    int f;
};

class Bar{
  public:
  static int j;
  static Foo f;
  static Foo FooVal(){
    ++j;
    return f;
  }
  static int callsFooVal(){
    return j;
  }
};

// class tX;

// class tY{
//   private:
//   // 只要类名一出现就可以认为该类已声明，因此，类的数据成员可以是指向自身类型的指针或引用
//   tX *x;
// };

// class tX{
//   tY y;
// }xxx,yyyyy;
