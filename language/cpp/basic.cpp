#include "basic.h"

// cpp的一些基本用法

// 定义表示英寸数据标示 inch
constexpr double operator"" _inch(const long double in) {
  return in * 0.0245;
  // double tvsize = 54.0_inch;
}

// 常量
// 随机数
int t_random() {
  default_random_engine reng;
  // 0~25的分布
  uniform_int_distribution<int> uni_dist(0, 25);

  random_device rnd_device;
  reng.seed(rnd_device());

  const int n = 4;
  char code[n];
  cout << "input code:" << endl;
  for (int i = 0; i < n; i++) {
    code[i] = 'a' + uni_dist(reng);
    cout << code[i];
  }
  cout << endl;
  return 0;
}

int t_const() {
  const int LENGTH = 10;
  const int WIDTH = 5;
  const char NEWLINE = '\n';

  int area = LENGTH * WIDTH;
  printf("values of area :%d", area);
  printf("%c", NEWLINE);
}

const char *interator_overflow::what() const throw() {
  ostringstream ex_msg;
  static string msg;

  ex_msg << "Internal error: current index" << _index
         << "exceeds maximum bound:" << _max;
  msg = ex_msg.str();
  return msg.c_str();
}

// 基于范围的for循环

void t_for() {
  int my_array[5] = {1, 2, 3, 4, 5};

  for (auto &x : my_array) {
    x *= 2;
    cout << x << endl;
  }

  string str("some string");
  for (auto &c : str) {
    c = toupper(c);
  }
  cout << str << endl;
}
// const
class TextBlock {
public:
  // const
  const char &operator[](int pos) const { return text[pos]; }
  // non-const
  char &operator[](int pos) { return text[pos]; }
  TextBlock(char *st) { strncpy(text, st, strlen(text)); }

private:
  char text[1024];
};

void test_textblock() {
  char h[10] = "Hello";
  char w[10] = "World";
  TextBlock tb(h);
  cout << tb[0];
  const TextBlock ctb(w);
  cout << ctb[0];
  tb[0] = 'A';
  // error, modify const obj
  // ctb[0] = 'B';
}

// copy构造函数 与 copy assignment函数
class Person {
public:
  Person(int age, string &name);

private:
  const int m_age;
  string &m_name;
  Person(const Person &);
  Person &operator=(const Person &);
  string &m_inlcude;
};

void Teacher::GiveLesson() { cout << "老师上课" << endl; }

// Teacher* p = new Teacher("zhangran");
// delete p;
// p = nullptr;

// 友元函数
// 在类的外部定义的友元函数
int AdjustSalary(Teacher *teacher) {
  // 在Teacher类的友元函数中访问它的保护类型的成员m_nSalary
  if (teacher != nullptr && teacher->m_nSalary < 1000) {
    teacher->m_nSalary += 500; // 涨工资
    return teacher->m_nSalary;
  }

  return 0;
}

int test_overload() {
  HumanNew MrChen;
  // 根据参数的不同来决定具体调用的重载函数，在编译时刻决定
  MrChen.Talk();         // 调用无参数的Talk()
  MrChen.Talk("Balala"); // 调用以string为参数的Talk(string)

  HumanNew *pBaby = new BabyNew();
  // 根据指针指向的实际对象的不同来决定具体调用的重写函数，在运行时刻决定
  pBaby->Talk(); // 调用Baby类的Talk()函数

  delete pBaby;
  pBaby = nullptr;

  return 0;
}

void show_capacity(std::string const &s) {
  std::cout << "'" << s << "' has capacity " << s.capacity() << ".\n";
}
int test_string2() {
  std::string str("hello world.");

  unsigned int location = str.find("ll", 0);
  unsigned int l2 = str.rfind("d.");

  std::cout << str.find_first_of("lo") << std::endl;
  std::cout << str.find_last_of("rl") << std::endl;
  std::cout << str.append(" ZHR!") << std::endl;
  std::cout << str.at(3) << std::endl;
  std::cout << str.compare("hello world,") << std::endl;
  std::cout << str.empty() << std::endl;
  std::cout << str.insert(2, "ZHRIDIDI") << std::endl;
  std::cout << str.replace(2, 4, "ZHRIDIDI") << std::endl;
  show_capacity(str);
  std::cout << "size:" << str.size() << std::endl;
  return 0;
}

int temp_string() {
  string one("One test string!");

  cout << one << endl; // One test string!

  string two(20, '#');
  cout << two << endl; //####################

  string three(one);
  cout << three << endl; // One test string!

  one += "+str";
  cout << one << endl; // One test string!+str

  two = "Hello new str";
  three[0] = 'T';

  string four;
  four = two + three;

  cout << four << endl; // Hello new strTne test string!

  char chFive[20] = "five string!test";
  string five(chFive, 12);
  cout << five << "!\n"; // five string!!

  string six(chFive + 5, chFive + 12);
  cout << six << ","; // string!,

  string seven(&five[5], &five[11]);
  cout << seven << "...\n"; // string...

  string eight(four, 6, 15);
  cout << eight << "endl" << endl; // new strTne testendl

  return 0;
}

int test_string_3() {
  std::string one("One test string!");
  std::cout << "hellos" << std::endl;
  cout << one << endl;
  string two(20, '#');
  cout << two << endl;
  string three(one);
  cout << three << endl;
  one += "+str";
  cout << one << endl;
  two = "Hello new str";
  three[0] = 'T';
  string four;
  four = two + three;
  cout << four << endl;
  char chFive[20] = "five string!test";
  string five(chFive, 12);
  cout << five << "!\n";

  string six(chFive + 5, chFive + 12);
  cout << six << ",";
  string seven(&five[5], &five[11]);
  cout << seven << "....\n";
  string eight(four, 6, 15);
  cout << eight << "endl" << endl;
  return 0;
}

const int NUM = 3;
const string word[NUM] = {"apple", "orange", "where"};

int temp_string_4() {
  srand(time(0)); //以当前时间为随机数种子
  char play;
  cout << "开始游戏吗？<y or n>" << endl;
  cin >> play;
  play = tolower(play); //把字符转换为小写

  while (play == 'y') {
    string target = word[rand() % NUM]; //随机选取数组中的单词
    int length = target.length();       //获取字符串长度
    string attempt(length, '-');        //依次显示猜对的字符
    string badchars;                    //记录猜错的字符
    int guesses = 6;                    //限制猜测次数为6
    cout << "猜一个单词,它有" << length << "个字母\n"
         << "每次猜一个字母，你有" << guesses << "次机会" << endl;
    cout << "你猜的字母:" << attempt << endl;

    //猜测次数大于0，并且猜测的单词不等于目标单词的时候循环
    while (guesses > 0 && attempt != target) {
      char letter;
      cout << "开始猜一个字母：";
      cin >> letter;

      //猜错的字符不能重复
      if (badchars.find(letter) != string::npos ||
          attempt.find(letter) != string::npos) {
        cout << "请重新输入" << endl;
        continue;
      }

      int loc = target.find(letter); //在目标单词中查找字符
      if (loc == string::npos) {
        cout << "猜错了\n";
        --guesses;
        badchars += letter; //记录猜错的字符
      } else {
        cout << "猜对了\n";
        attempt[loc] = letter; //记录猜对的字符

        //判断下面的符字是否和第一个字符相同，相同则直接显示
        loc = target.find(letter, loc + 1);
        while (loc != string::npos) {
          attempt[loc] = letter;
          loc = target.find(letter, loc + 1);
        }
      }

      cout << "你猜的是" << attempt << endl;
      if (attempt != target) {
        //显示猜错的字符
        if (badchars.length() > 0)
          cout << "错误的猜测" << badchars << endl;
        cout << "你还有" << guesses << "次猜错机会" << endl;
      }
    }

    if (guesses > 0) {
      cout << "太棒了!\n";
    } else {
      cout << "这个单词是其实是：" << target << ".\n" << endl;
    }

    cout << "你想再来一次吗？<y or n>";
    cin >> play;
    play = tolower(play);
  }

  return 0;
}

// const int NUM = 3;
// const string word[NUM] = { "apple", "orange", "where" };
int test_string_4() {
  srand(time(0)); // 已当前时间为随机数种子
  char play;
  cout << "start game?<y or n>" << endl;

  cin >> play;
  while (play == 'y') {
    string target = word[rand() % NUM];

    int length = target.length();
    string attempt(length, '-'); // 依次显示猜对的字符
    string badchars;             // 记录猜错的字符
    int guesses = 6;
    cout << "guess word ,it has" << length << " chars\n"
         << "every char ,you have " << guesses << " chances " << endl;
    cout << "you guesses chars is:" << attempt << endl;
    while (guesses > 0 && attempt != target) {
      char letter;
      cout << "first char:";
      cin >> letter;

      if (badchars.find(letter) != string::npos ||
          attempt.find(letter) != string::npos) {
        cout << "repeat input" << endl;
        continue;
      }

      int loc = target.find(letter); // 在目标单词中查找字符
      if (loc == string::npos) {
        cout << "guesses error\n";
        --guesses;
        badchars += letter;
      } else {
        cout << "success \n";
        attempt[loc] = letter;
        loc = target.find(letter, loc + 1);
        while (loc != string::npos) {
          attempt[loc] = letter;
          loc = target.find(letter, loc + 1);
        }
      }

      cout << "u guesses" << attempt << endl;
      if (attempt != target) {
        // 显示猜错的字符
        if (badchars.length() > 0)
          cout << " error guesses is " << badchars << endl;
        cout << "u have " << guesses << "chances" << endl;
      }
    }
    if (guesses > 0) {
      cout << "great!!\n";
    } else {
      cout << "this word is " << target << ".\n" << endl;
    }
    cout << "u want try again?<y or n>";
    cin >> play;
    play = tolower(play);
  }
  return 0;
}
