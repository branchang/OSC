//
// Created by Bran on 10/3/18.
//

#ifndef HELLO_ALGO_H
#define HELLO_ALGO_H
//
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include <iterator>
using namespace std;

vector<int> less_than_10(const vector<int> &vec);
int count_occurs(const vector<int> &vec, int val);
//vector<int> filter(const vector<int> &vec, int filter_value, bool (*pred)(int, int));

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred);
int test_filter();
int test_m();

#endif //HELLO_ALGO_H
