
#include "stack.h"

inline bool 
Stack::empty(){
    return _stack.empty();
}

bool Stack::pop(string &elem){
    if (empty())
        return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

inline bool Stack::full(){
    return _stack.size() == _stack.max_size();
}

bool Stack::peek(string &elem){
    if (empty())
        return false;
    elem = _stack.back();
    return true;
}
bool Stack::push(const string &elem){
    if (full())
        return false;

    _stack.push_back(elem);
    return true;
}

bool Stack::find(const string &elem){
    if (empty())
        return false;
    
    vector<string>::iterator iter = _stack.begin();
    for (;iter != _stack.end(); iter++){
        if (*iter == elem){
            return true;
        }
    }
    return false;
}

int Stack::count(const string &elem){
    if (empty())
        return 0;
    int i = 0; 
    vector<string>::iterator iter = _stack.begin();
    for (;iter != _stack.end(); iter++){
        if (*iter == elem)
            i+=1;
    }
    return i;
}

int Stack::test(){
    cout<<"hello world, stack.";
}
