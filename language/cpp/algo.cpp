//
// Created by Bran on 10/3/18.
//

#include "algo.h"

vector<int> less_than_10(const vector<int> &vec) {
  vector<int> nvec;

  for (int ix = 0; ix < vec.size(); ++ix) {
    if (vec[ix] < 10) {
      nvec.push_back(vec[ix]);
    }
  }
  return nvec;
}

bool less_than(int v1, int v2) { return v1 < v2 ? true : false; }

bool greater_than(int v1, int v2) { return v1 > v2 ? true : false; }

vector<int> filter(const vector<int> &vec, int filter_value,
                   bool (*pred)(int, int)) {
  vector<int> nvec;
  for (int ix = 0; ix < vec.size(); ++ix) {
    if (pred(vec[ix], filter_value))
      nvec.push_back(vec[ix]);
  }
  return nvec;
}

int count_occurs(const vector<int> &vec, int val) {
  vector<int>::const_iterator iter = vec.begin();
  int occurs_count = 0;
  while ((iter = find(iter, vec.end(), val)) != vec.end()) {
    ++occurs_count;
    ++iter;
  }

  return occurs_count;
}

template <typename InputIterator, typename OutputIterator, typename ElemType,
          typename Comp>
OutputIterator filter(InputIterator first, InputIterator last,
                      OutputIterator at, const ElemType &val, Comp pred) {

  while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
    cout << "found value:" << *first << endl;
    *at++ = *first++;
    string one("heloookdisfkd");
    // unsigned int ll =
  }
  return at;
}

int test_filter() {
  const int elem_size = 8;
  int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
  vector<int> ivec(ia, ia + elem_size);

  int ia2[elem_size];
  vector<int> ivec2(elem_size);

  cout << "filtering integer array for values less than 8\n";
  filter(ia, ia + elem_size, ia2, elem_size, less<int>());

  cout << "filtering integer array for values greater than 8\n";
  filter(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>());

  return 0;
}

vector<int> sub_vec(const vector<int> &vec, int val) {
  vector<int> local_vec(vec);
  sort(local_vec.begin(), local_vec.end());

  vector<int>::iterator iter =
      find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));
  local_vec.erase(iter, local_vec.end());
  return local_vec;
}

int test_iostream() {
  string word;
  vector<string> text;

  while (cin >> word)
    text.push_back(word);

  sort(text.begin(), text.end());

  for (int ix = 0; ix < text.size(); ++ix)
    cout << text[ix] << ' ';

  return 0;
}

int test_m() {
  istream_iterator<string> is(cin);
  istream_iterator<string> eof;

  vector<string> text;
  copy(is, eof, back_inserter(text));

  sort(text.begin(), text.end());

  ostream_iterator<string> os(cout, " ");
  copy(text.begin(), text.end(), os);
  return 0;
}
