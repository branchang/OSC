//
// Created by Bran on 8/18/18.
//
#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int* find1(const vector<int> &vec, int value){
    for (int ix = 0;ix<vec.size();++ix){
        if (vec[ix] == value){
            return &vec[ix];
        }
    }
    return 0;
}

template  <typename elemType>
elemType* find2(const vector<elemType> &vec, const elemType &value){
    for (int ix = 0; ix < vec.size(); ++ix){
        if (vec[ix] == value){
            return &vec[ix];
        }
    }
    return 0;
}

template <typename elemType>
elemType* find3(const elemType *array, int size, const elemType &value){
    if (!array || size < 1 )
        return 0;

//    ++array会令array指向下一个元素
    for (int ix=0; ix < size; ++ix, ++array)
        if(*array ==value)
            return array;
    return 0;
}


template <typename elemType>
const elemType* find4(const elemType *first, const elemType *last, const elemType &value){
    if (!first || !last)
        return 0;

    for (; first != last; ++first)
        if (*first ==value)
            return  first;
    return 0;
}

template <typename IteratorType, typename elemType>
IteratorType
find5(IteratorType first, IteratorType last, const elemType &value)
{
    for(;first!=last;++first) {
        if(value == *first)
            return first;
    }
    return last;
}

template  <typename elemType>
inline const elemType* t_begin(const vector<elemType> &vec){
    return vec.empty()? 0:&vec[0];
}
template  <typename  elemType>
inline const elemType* t_end(const vector<elemType> &vec){
    return vec.empty()?0:&vec[vec.size()-1];
}


int find_test(){
//    int ia[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//    double ia[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    string ia[4] = {"pooh", "piglet", "eeyore", "tigger"};
    vector<string> svec(ia, ia+4);

    vector<string>::iterator iter = svec.begin();
    for (; iter != svec.end(); ++iter)
        cout << *iter << " ";

//    const string *pi = find4(&svec[0], &(svec[svec.size()]), svec[0]);
//    const string *pi = find4(t_begin(svec), t_end(svec), svec[3]);
//    cout << "pi is:"<<*pi;
    const int asize = 8;
    int ib[asize] = {1,1,2,3,5,8,13,21};

    vector<int> ivec(ib, ib+asize);
    list<int> ilist(ib, ib+asize);

    int *pia = find5(ib, ib+asize, 21);

    if (pia != ib+asize){
        cout<<"one find it:"<<*pia<<endl;
    }

    vector<int>::iterator it;
    it = find5(ivec.begin(), ivec.end(), 13);
    if(it != ivec.end()) {
        cout<<"two find it:"<<*it<<endl;
    }

    list<int>::iterator iterr;
    iterr = find5(ilist.begin(), ilist.end(), 5);
    if(iterr != ilist.end())
        cout<<"third find it:"<<*iterr<<endl;

    return 0;
}
