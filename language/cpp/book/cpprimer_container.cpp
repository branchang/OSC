#include "cpprimer_container.h"

// 顺序容器
int test_sequential_container() {
  vector<int> ivec;
  vector<int> ivec2(ivec);
  //   适用迭代器在不同容器之前进行复制
  vector<string> svec;
  list<string> slist(svec.begin(), svec.end());
  vector<string>::iterator mid = svec.begin() + svec.size() / 2;
  deque<string> front(svec.begin(), mid);
  deque<string> back(mid, svec.end());
  // 通过指针进行复制
  char* words[] = {"stately", "plump", "buck", "mulligan"};
  size_t words_size = sizeof(words) / sizeof(char*);
  list<string> words2(words, words + words_size);
  //  分配与初始化指定数目的元素
  const list<int>::size_type list_size = 64;
  list<string> slist2(list_size, "eh?");

  // 容器的容器
  vector<vector<string>> lines;
  // 理解insert的向前插入
  list<string> lst;
  list<string>::iterator iter = lst.begin();
  string word;
  while (std::cin >> word) {
    iter = lst.insert(iter, word);
  }

  return 1;
}

string greet(string form, string lastname, string title, string::size_type pos,
             int length) {
  form.replace(form.find("Daisy"), 5, lastname);
  string t1(title, pos, length);
  form.replace(form.find("Ms"), 2, t1);
  return form;
}
int test_cstring() {
  string s("hello world");

  string::iterator ite = s.begin();
  cout << s << endl;

  for (; ite != s.end(); ++ite) {
    *ite = toupper(*ite);
  }

  cout << s << endl;

  string s1("Hello World!");
  cout << s1 << endl;
  for (string::iterator it = s1.begin(); it != s1.end(); ++it) {
    if ((bool)isupper(*it) == true) {
      s1.erase(it);
      it--;
      continue;
    }
  }
  cout << s1 << endl;

  vector<char> vc;
  vc.push_back('a');
  vc.push_back('b');
  vc.push_back('c');
  vc.push_back('d');
  vc.push_back('e');
  string s3(vc.begin(), vc.end());
  cout << s3 << endl;

  string name("AnnaBelle");
  string::size_type pos1 = name.find("Anna");
  cout << "pos1:" << pos1 << endl;

  string numerics("0123456789");
  string name1("r2d2");

  string::size_type pos = name1.find_first_of(numerics);
  cout << "found number at index:" << pos << "element is " << name[pos] << endl;

  string q1("When lilacs last in the dooryard bloom'd");
  string q2("The Child is father of the man");
  string sentence;
  sentence.assign(q2, 0, 13);
  sentence.append(q1, 17, 23);
  cout << sentence << endl;

  string g1("Dear Ms Daisy:");
  string g2("MrsMsMissPeople");
  string lastName("AnnaP");
  string salute = greet(g1, lastName, g2, 5, 4);
  cout << salute << endl;

  return 0;
}

void container_adaptor() {
  stack<string> words;
  string w;
  while (cin >> w) words.push(w);

  while (words.empty() == false) {
    cout << words.top() << endl;
    words.pop();
  }
}

void test_pair() {
  pair<string, string> anon;
  pair<string, int> word_count;
  pair<string, vector<int>> line;
  typedef pair<string, string> Author;
  Author proust("Marcel", "Proust");
  cout << proust.first << proust.second << endl;

  pair<string, string> next_auth, next_auth2;
  string first, last;
  // while (cin >> first >> last) {
  //     next_auth = make_pair(first, last);
  //     next_auth2 = pair<string, string>(first, last);
  // }
  pair<string, int> tp;
  vector<pair<string, int>> vp;
  string s1;
  int i1;
  while (cin >> s1 >> i1) {
    // 第一种
    tp = make_pair(s1, i1);
    // 第二种
    pair<string, int> tmp1;
    tmp1.first = s1;
    tmp1.second = i1;
    // 第三种
    pair<string, int> tmp2(s1, i1);
    vp.push_back(tp);
  }
}

void cpp_map() {
  int occurs = 0;
  map<string, list<int>> word_lines;
  map<string, int> words;
  string w;
  while (cin >> w) {
    pair<map<string, int>::iterator, bool> ret = words.insert(make_pair(w, 1));
    if (!ret.second) {
      ++ret.first->second;
    }
  }
  map<string, int>::iterator it = words.find("foobar");
  if (it != words.end()) occurs = it->second;

  while (cin >> w) {
    ++words[w];
  }
  for (map<string, int>::iterator it = words.begin(); it != words.end(); ++it) {
    cout << it->first << " is " << it->second << endl;
  }

  words.insert(map<string, int>::value_type("Anna", 1));
  words.insert(make_pair("Annaa", 1));
  typedef map<string, int>::value_type valType;
  words.insert(valType("Annab", 2));
}

bool open_file(ifstream& handle, char* file_name) {
  handle.open(file_name, std::ios::in);
  if (!handle.is_open()) {
    return false;
  }
  return true;
}
int transcode_words(int argc, char** argv) {
  map<string, string> trans_map;
  string key, value;
  if (argc != 3) throw runtime_error("wrong number of arguments");
  ifstream map_file;
  if (!open_file(map_file, argv[1])) {
    throw runtime_error("no transformation file.");
  }

  while (map_file >> key >> value) {
    trans_map.insert(make_pair(key, value));
  }
  ifstream input;
  if (!open_file(input, argv[2])) {
    throw runtime_error("no input file");
  }

  string line;
  while (getline(input, line)) {
    istringstream stream(line);
    string word;
    bool firstword = true;
    while (stream >> word) {
      map<string, string>::const_iterator map_it = trans_map.find(word);
      if (map_it != trans_map.end()) {
        word = map_it->second;
      }

      if (firstword)
        firstword = false;
      else
        cout << " ";
      cout << word;
    }

    cout << endl;
  }
  return 0;
}

void testmap2() {
  map<string, vector<string>> name;
  vector<string> vs1;
  vs1.push_back("ran");
  vs1.push_back("yang");
  vs1.push_back("wen");
  name.insert(make_pair("zhang", vs1));
  map<string, vector<string>>::const_iterator ci = name.begin();
  cout << "testmap2" << endl;
  while (ci != name.end()) {
    cout << ci->first << endl;
    for (vector<string>::const_iterator it = ci->second.begin();
         it != ci->second.end(); ++it)
      cout << *it << " ";
    ++ci;
    cout << endl;
  }
}

void testmap3() {
  map<string, vector<pair<string, string>>> name;
  vector<pair<string, string>> vs1;
  vs1.push_back(make_pair("ran", "19880803"));
  vs1.push_back(make_pair("yang", "19880718"));
  vs1.push_back(make_pair("wen", "202093083"));
  name.insert(make_pair("zhang", vs1));
  map<string, vector<pair<string, string>>>::const_iterator ci = name.begin();
  cout << "testmap2" << endl;
  while (ci != name.end()) {
    cout << ci->first << endl;
    for (vector<pair<string, string>>::const_iterator it = ci->second.begin();
         it != ci->second.end(); ++it)
      cout << it->first << "->" << it->second << endl;
    ++ci;
    cout << endl;
  }
}

void testset1() {
  vector<int> ivec;
  for (vector<int>::size_type i = 0; i != 10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i);
  }

  set<int> iset(ivec.begin(), ivec.end());
  cout << ivec.size() << endl;
  cout << iset.size() << endl;

  set<string> set1;
  set1.insert("the");
  set1.insert("and");
}

int t_10_25() {
  vector<string> strVecBook;
  string bName;
  cout << "Input books'name you wanna read (ctrl+z to end):\n";
  while (cin >> bName) {
    strVecBook.push_back(bName);
    if (strVecBook.size() > 3) {
      break;
    }
  }

  size_t NumOfBooks = strVecBook.size();  // record number of books

  // 2 create set
  set<string> strSetReadedBook;
  string strChoice, bookName;
  bool _6MonthLater = false;
  srand((unsigned)time(NULL));

  while (!_6MonthLater && !strVecBook.empty()) {
    std::cin.clear();
    cout << "\n==>>Do you wanna read a book?(Yes/No):";
    std::cin >> strChoice;
    cout << "strChoice:" << strChoice << ";" << endl;
    if (strChoice[0] == 'Y' || strChoice[0] == 'y') {
      int i = rand() % strVecBook.size();
      bookName = strVecBook[i];
      cout << "=>>We choose this book for you" << bookName << endl;
      strSetReadedBook.insert(bookName);
      strVecBook.erase(strVecBook.begin() + i);

      cout << "\t One month later...." << endl
           << "Did you read this book?(Yes/No):";
      cin >> strChoice;
      if (strChoice[0] == 'n' || strChoice[0] == 'N') {
        strSetReadedBook.erase(bookName);
        strVecBook.push_back(bookName);
      }
    }

    cout << " 6 monthlater? (Yes/No):";
    cin >> strChoice;
    if (strChoice[0] == 'Y' || strChoice[0] == 'y') _6MonthLater = true;
    if (_6MonthLater) {
      if (!strSetReadedBook.empty()) {
        cout << "\n == >>> During the latest 6 months, you read:\n\t";
        for (set<string>::iterator iter = strSetReadedBook.begin();
             iter != strSetReadedBook.end(); ++iter) {
          cout << *iter << " ";
        }
      }

      if (!strVecBook.empty()) {
        cout << "\n ==>>>> The books you have not read:\n\t";
        for (vector<string>::iterator it = strVecBook.begin();
             it != strVecBook.end(); ++it) {
          cout << *it << " ";
        }
      }
      cout << endl;
    }
  }

  if (strSetReadedBook.size() == NumOfBooks)
    cout << "\t GOod, you read all the books" << endl;
  system("pause");
  return 0;
}

void t_multi() {
  multimap<string, string> authors;
  authors.insert(make_pair(string("Barth, John"), string("Sot-Weed Factor")));
  authors.insert(
      make_pair(string("Barth, John"), string("Lost in thr Funhouse")));

  string search_item("Kazuo Ishiguro");
  multimap<string, string>::size_type cnt = authors.erase(search_item);

  // use count find
  string search("Barth, John");
  typedef multimap<string, string>::size_type sz_type;
  sz_type entries = authors.count(search);
  multimap<string, string>::iterator iter = authors.find(search);

  for (sz_type cnt = 0; cnt != entries; ++cnt, ++iter) {
    cout << iter->second << endl;
  }

  // use lower bound upper
  typedef multimap<string, string>::iterator authors_it;
  authors_it beg = authors.lower_bound(search),
             end = authors.upper_bound(search);

  while (beg != end) {
    cout << beg->second << endl;
    ++beg;
  }

  // use equal_range
  pair<authors_it, authors_it> pos = authors.equal_range(search);
  while (pos.first != pos.second) {
    cout << pos.first->second << endl;
    ++pos.first;
  }

  typedef multimap<string, string>::iterator iter_type;

  multimap<string, string> author_books;
  string a, b;
  while (cin >> a >> b) {
    if (a == "*") break;
    author_books.insert(make_pair(a, b));
  }
  for (iter_type b = author_books.begin(); b != author_books.end(); ++b) {
    cout << b->first << "-->" << b->second << endl;
  }

  cout << "while delete authors:" << endl;
  string auth;
  if (cin.ios_base::fail()) {
    cout << "error for cin" << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear(std::istream::eofbit);
  }
  cin >> auth;
  typedef multimap<string, string>::size_type sz_type2;
  sz_type2 cnt2 = author_books.count(auth);
  for (sz_type2 i = 0; i != cnt2; ++i) {
    author_books.erase(author_books.find(auth));
  }

  for (iter_type b = author_books.begin(); b != author_books.end(); ++b) {
    cout << b->first << " " << b->second << endl;
  }
  cout << endl;
}

void TextQuery::read_file(std::ifstream& is) {
  store_file(is);
  build_map();
}

std::set<TextQuery::line_no> TextQuery::run_query(
    const std::string& word) const {
  std::map<string, std::set<TextQuery::line_no>>::const_iterator it;
  it = word_map.find(word);
  if (it != word_map.end()) {
    return it->second;
  } else {
    return set<line_no>();
  }
}

std::string TextQuery::text_line(line_no ln) const {
  if (ln > lines_of_texts.size()) {
    throw std::out_of_range("line number out of range");
  }
  return lines_of_texts[ln];
}

void TextQuery::store_file(std::ifstream& ifs) {
  for (std::string line; std::getline(ifs, line);) {
    lines_of_texts.push_back(line);
  }
}

void TextQuery::build_map() {
  line_no l = 0;
  for (vector<string>::iterator it = lines_of_texts.begin();
       it != lines_of_texts.end(); ++it) {
    std::istringstream line(*it);
    string word;
    while (line >> word) {
      std::map<string, std::set<line_no>>::iterator it = word_map.find(word);
      if (it != word_map.end()) {
        it->second.insert(l);
      } else {
        set<line_no> ts;
        ts.insert(l);
        word_map.insert(make_pair(word, ts));
      }
    }
    ++l;
  }
}

void print_results(const set<TextQuery::line_no>& locs, const string& s,
                   const TextQuery& tq) {
  for (set<TextQuery::line_no>::iterator it = locs.begin(); it != locs.end();
       ++it) {
    string lines = tq.text_line(*it);
    cout << (*it + 1) << ":" << lines << endl;
  }
}

int t_text_query(int argc, char** argv) {
  ifstream ifs;
  if (argc < 2 || !open_file(ifs, argv[1])) {
    cerr << "No input file" << endl;
    return -1;
  }
  TextQuery tq;
  tq.read_file(ifs);
  while (true) {
    cout << "enter word to look for , or q to quit: ";
    string s;
    cin >> s;
    if (!cin || s == "q") break;
    set<TextQuery::line_no> locs = tq.run_query(s);
    print_results(locs, s, tq);
  }
  return 0;
}
