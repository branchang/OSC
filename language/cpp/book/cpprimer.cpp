#include "cpprimer.h"
#include "copy_control_13.h"
void init_multiple_var() {
  double salary = 99999.9;
  int interval, month = 8, day = 7, year = 1955;
  std::string title("CPP PRIMER"), publisher = "A-W";
}

void init_const_var() {
  const int bufSize = 512;
  const std::string hi = "hello";
  // 错误const定义的不能修改
  // bufSize = 19;
  // i未初始化
  // const int i, j = 10;
  //
}
// 可以被全局访问，不是当前文件的程序也可以通过 extern const int
// bufSize2;声明使用 非 const 变量默认为 extern。要使 const
// 变量能够在其他的文件中访问，必须地指定它为 extern。
extern const int bufSize2 = 1024;
int bufSize3 = 256;

// 引用

void reference_test() {
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
  std::cout << "ival:" << ival << "refval:" << refVal << "ii:" << ii
            << std::endl;

  // defining multiple reference
  int i = 1024, i2 = 2048;
  int &r = i, r2 = i2;      // r is ref, r2 is an int
  int i3 = 1024, &ri = i3;  // defines one object and one reference
  int &r3 = i3, &r4 = i2;   // defines two reference
  // const reference is a reference that may refer to a const object
  const int inval = 100;
  const int &refcval = inval;
  // int &refval2 = inval;  // error
  // refcval = 199;
  // const 引用可以初始化为不同类型的对象或者初始化为右值
  int i31 = 42;
  const int &r33 = 42;
  // 编译器会转码成如下形式
  int temp3 = 42;
  const int &r35 = temp3;
  //
  const int &r34 = r33 + 1;
  int t1, &rt1 = t1;
  t1 = 5;
  rt1 = 10;
  std::cout << t1 << " " << rt1 << std::endl;
}

void typedef_test() {
  // a typedef lets us define a synonym for a type
  // typedef 定义以关键字 typedef 开始，后面是数据类型和标识符
  typedef double wages;
  typedef int exam_score;
  typedef wages salery;
  wages hourly, weekly;
  exam_score test_results;
}
//  enumerations
void enum_test() {
  enum open_modes { input, output, append };

  // 枚举成员值可以是不唯一的
  enum Points { point2d = 2, point2w, point3d = 3, point4w };

  Points p1 = point2d;
  Points p2 = p1;
  open_modes om = input;
}

// 泛型算法
void generic_algorithm() {
  int search_value = 42;
  int ia[6] = {27, 210, 42, 47, 109, 83};
  int *results = find(ia, ia + 6, search_value);
  cout << "the value " << search_value
       << (results == ia + 6 ? " is not present" : " is present") << endl;

  // std::vector<int>::const_iterator result = find()
  vector<int> l_i;
  int i;
  while (cin >> i && i != 0) l_i.push_back(i);
  int j;
  cout << "you will find: ";
  cin >> j;
  // int num = std::count(l_i.begin(), l_i.end(), j);
  int num = std::accumulate(l_i.begin(), l_i.end(), 0);
  cout << "find results num:" << num << endl;
  fill_n(l_i.begin(), l_i.size(), 0);
  for (vector<int>::size_type i = 0; i != l_i.size(); ++i) {
    cout << l_i[i] << endl;
  }
}

void t_iterator() {
  istream_iterator<int> cin_it(cin);
  istream_iterator<int> end_of_stream;
  vector<int> vec;
  while (cin_it != end_of_stream) {
    vec.push_back(*cin_it++);
  }

  ofstream outfile;
  istream_iterator<string> in_iter(cin), eof;
  ostream_iterator<string> output(cout, "\n");

  while (cin_it != end_of_stream) {
    *output++ = *in_iter++;
  }
}

void t_iterator_vec() {
  istream_iterator<int> cin_it(cin);
  istream_iterator<int> end_of_stream;

  vector<int> vec(cin_it, end_of_stream);
  sort(vec.begin(), vec.end());
  ostream_iterator<int> output(cout, " ");

  unique_copy(vec.begin(), vec.end(), output);
}

int iterator_main() {
  ofstream outfile_even, outfile_odd;
  outfile_even.open("outFile_event.txt");
  outfile_odd.open("outFile_odd.txt");

  if (!outfile_even || !outfile_odd) {
    cout << "File can't be open" << endl;
    return -1;
  }

  istream_iterator<int> in_iter(cin), end;

  ostream_iterator<int> out_odd_iter(outfile_odd, " ");
  ostream_iterator<int> out_event_iter(outfile_even, "\n");
  while (in_iter != end) {
    if (*in_iter % 2 == 0) {
      *out_event_iter++ = *in_iter++;
    } else {
      *out_odd_iter++ = *in_iter++;
    }
  }
  outfile_odd.close();
  outfile_even.close();
  cout << endl;
  return 0;
}

void reverse_iterator_t() {
  vector<int> i{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int>::reverse_iterator it = i.rbegin();
  for (; it != i.rend(); ++it) {
    cout << *it << endl;
  }

  cout<<"-----"<<endl;
  list<int> l1;
  it = i.rbegin();
  copy(it + 2, it + 7, back_inserter(l1));

  list<int>::iterator it2 = l1.begin();
  for (; it2 != l1.end(); ++it2) {
    cout << *it2 << endl;
  }
}

void t_class(){
  person p1("zhang", "lishuijiayuan");
  cout<<p1.get_name()<<endl;
  cout<<p1.get_address()<<endl;
}


Screen& Screen::set(char c) {
  contents[cursor] = c;
  return *this;

}

Screen& Screen::move(index r, index c){
  index row = r * width;
  cursor = row +c;
  return *this;
}

Screen& Screen::display(std::ostream &os){
  os<<contents<<endl;
  return *this;
}

const Screen& Screen::display(std::ostream &os) const {
  os<<contents<<"const"<<endl;;
  return *this;
}

void t_screen(){
  Screen s1("hello world!", 2, 6);
  s1.display(std::cout);
  s1.move(0, 3).set('Z').display(std::cout);
  const Screen s2("zhangran t", 2,6);
  s2.display(cout);

}

int cpp_primer_test() {
  //   reference_test();
  // generic_algorithm();
  // t_iterator_vec();

  // iterator_main();
  // reverse_iterator_t();
  // t_class();
  // t_screen();
    test_copy_control();
  return 0;
}
