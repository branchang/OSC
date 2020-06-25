#include "cpprimer_exercise.h"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// https://wenku.baidu.com/view/8a41e9c369eae009581becd7.html

void exer_3_13() {
  vector<int> input_i;
  int i = 0;
  while (cin >> i) {
    input_i.push_back(i);
  }

  vector<int>::const_iterator iter = input_i.begin();
  for (; iter != input_i.end();) {
    int t_sum = *iter;
    if (iter + 1 != input_i.end()) {
      t_sum += *(iter + 1);
      cout << "sum:" << t_sum << endl;
    } else {
      cout << "single:" << *iter << endl;
      break;
    }
    iter += 2;
  }

  vector<int>::const_iterator iter_begin = input_i.begin();
  vector<int>::const_iterator iter_end = input_i.end() - 1;

  for (; iter_begin != iter_end && iter_begin < iter_end;) {
    cout << "begin+end:" << (*iter_begin) + (*iter_end) << endl;
    iter_begin += 1;
    iter_end -= 1;
  }

  if (iter_begin == iter_end) {
    cout << "last:" << (*iter_begin) << endl;
  }

  vector<int> e316(10, 42);
}

void exer_3_14() {
  string s;
  vector<string> input_s;
  while (cin >> s) {
    input_s.push_back(s);
  }

  vector<string>::iterator iter;
  for (iter = input_s.begin(); iter != input_s.end(); ++iter) {
    // *iter = toupper(*iter);
    string::iterator s_iter = (*iter).begin();
    for (; s_iter != (*iter).end(); ++s_iter) {
      *s_iter = toupper(*s_iter);
    }
    cout << *iter << endl;
  }
}

void exer_3_18(){
    vector<int> v1;
    for (int i = 0;i!=10;++i){
        v1.push_back(i);
    }

    vector<int>::iterator beg = v1.begin();
    vector<int>::iterator end = v1.end();
    // vector<int>::iterator mid = (beg+end)/2;
    for (;beg!=end; ++beg){
        *beg *= 2;
    }

    beg = v1.begin();
    for (;beg!=end; ++beg){
        cout<<"nums:"<<*beg<<endl;
    }
    const int i1 = 10;
    const int *i1p = &i1;
    // *i1p = 20;
    int j1 = 20;
    int j2 = 20;
    int *const jcp = &j1;
    // jcp = &j2;
}

void exer_4_23(){
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while(*cp){
        cout<<*cp<<endl;
        ++cp;
    }
    int *pa = new int[10];
    delete [] pa;

    // 4.30
    char c_char[6] = {'h', 'e' ,'l', 'l', 'o'};
    char c_char2[7] = {'w', 'o', 'r', 'l', 'd', '!'};
    char c_char3[14];

    strncpy(c_char3, c_char, 5);
    strcat(c_char3, c_char2);
    cout<<c_char3<<endl;
    int i = 0;
    vector<int> array;
    while(cin>>i){
        array.push_back(i);
    }
    int *c_array = new int[array.size()];
    for(int j=0; j!= array.size(); ++j){
        c_array[j] = array[j];
        cout<<c_array[j]<<endl;
    }

    delete [] c_array;

}

void exer_4_31(){
    int input_len;
    cin>>input_len;
    cout<<"input_len:"<<input_len<<endl;
    int *input_array_init = new int[input_len];

    int *input_array = input_array_init;
    while(cin>>input_len){
        *input_array = input_len;
        input_array += 1;
    }

    for(int i=0;i!=10;++i){
        cout<<*(input_array_init+i)<<endl;
    }

    delete [] input_array_init;

    vector<int> vi;
    int ia[7] = {1,2,3,4,5,6,7};
    for (int i = 0;i !=7;++i){
        vi.push_back(ia[i]);
    }
}

void exer_4_34(){
    // 编写程序读入一组 string 类型的数据，并将它们存储在 vector 中。接着，把该 vector 对象复制给一个字符指针数组。
    // 为 vector 中的每个元素创建一个新的字符数组，并把该 vector 元素的数据复制到相应的字符数组中，最后把指向该数组的指针插入字符指针数组。
    vector<string> vs;
    string s1;
    while(cin>>s1){
        vs.push_back(s1);
    }

    vector<string>::const_iterator sci = vs.begin();
    vector<string>::const_iterator end = vs.end();
    // char *c_a[vs.size()];
    char *c_a[1000];
    int i = 0;
    for (;sci!=end;++sci){
        int length = (*sci).length();
        char *c = new char[length + 1];
        for (int i =0 ;i<length;++i){
            c[i] = (*sci)[i];
        }
        c_a[i++] = c;
    }

    for (vector<string>::const_iterator beg=vs.begin(); beg!=end; ++beg)
    {
        cout<<"vector:"<<*beg<<endl;
    }
    for(int i=0;i<vs.size();++i){
        cout<<"char *:"<<c_a[i]<<endl;
    }

}

void exer_5(){
    int i = 0;
    // while(cin>>i && i!=42){
    //     cout<<i<<endl;
    // }
    int j;
    double d;
    d = j = 3.5;
    cout<<"d:"<<d<<"j:"<<j<<endl;
    j = d= 3.5;
    cout<<"d:"<<d<<"j:"<<j<<endl;

}

int cpperimer_exer() {
//   exer_3_14();
    // exer_4_23();
    // exer_4_34();
    exer_5();

  return 0;
}
