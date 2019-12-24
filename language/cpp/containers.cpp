//
// Created by Bran on 8/18/18.
//
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

list<string> slist;
vector<int> ivec;

list<int> ilist(1024);
vector<string> svec(32);

vector<int> ivec2(10, -1);
list<string> slist2(16, "unassigned");

int containers_test(){
    deque<int> a_line;
    int ival;
    while(cin>>ival){
        a_line.push_back(ival);
        int curr_value = a_line.front();
        cout <<"front find:"<<curr_value<<endl;
        a_line.pop_front();
    }
}

int test_insert(){
    int ia1[7] = {1,1,2,3,5,55,89};
    int ia2[4] = {8, 13, 21, 34};
    list<int> elems(ia1, ia1+7);

    list<int>::iterator it = find(elems.begin(), elems.end(), 55);
    elems.insert(it, ia2, ia2 + 4);

    list<int>::const_iterator i = elems.begin();
    for (;i!=elems.end();++i){
        cout<< "elems:"<< *i <<endl;

    }
    return 0;
}


