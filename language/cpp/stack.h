
#include <iostream>
#include <vector>
using namespace std;

class Stack {
    public:
    bool push(const string &);
    bool pop(string &elem);
    bool peek(string &elem);

    bool empty();
    bool full();

    bool find(const string &);
    int count(const string &);

    int size(){
        return _stack.size();
    }

    // 测试
    int test();
    
    private:
        vector<string> _stack;
};