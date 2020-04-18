#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int test_cstring();
void container_adaptor();
void cpp_map();

int transcode_words(int argc, char** argv);

void testmap2();
void testmap3();

void testset1();
int t_10_25();

void t_multi();

class TextQuery {
 public:
  typedef std::vector<string>::size_type line_no;
  void read_file(std::ifstream& is);
  std::set<line_no> run_query(const std::string&) const;

  std::string text_line(line_no) const;

 private:
  void store_file(std::ifstream&);
  void build_map();
  std::vector<std::string> lines_of_texts;
  std::map<std::string, std::set<line_no>> word_map;
};

int t_text_query(int argc, char** argv);
