#include <string>
#include <iostream>

#include "Alloc.hpp"
#include "Allocator.hpp"
#include "Functional.hpp"

#include "Vector.hpp"
#include "List.hpp"
#include "Stack.hpp"

class TTTeacher {
public:
    TTTeacher() {
        name = "ZHR11111111111111111111";
    }
    TTTeacher(std::string n){
        name = n;
    }
    ~TTTeacher(){
        std::cout<<"TTTeacher destory"<< std::endl;
    }
private:
    std::string name;
    int age;
};

template<class T>
void print_list(TinySTL::list<T> &l)
{
    typename TinySTL::list<T>::iterator const_iterator = l.begin();
    for (;const_iterator!=l.end();const_iterator++)
    {
        std::cout<<const_iterator.p->data<<std::endl;
    }
}

bool compare_int(int &a, int &b)
{
    return a > b;
}

int use_list() {
    std::cout << "start use list~~~~~" << std::endl;

    TinySTL::list<int> l;
    l.push_back(9999);
    l.push_back(4999);
    l.push_back(3999);
    l.push_back(1999);

    std::cout << l.front()<< std::endl;
    std::cout << l.back()<< std::endl;
    std::cout << l.size() << std::endl;

    // list::l.begin();
    // l.pop_front();
    // l.pop_back();
    TinySTL::list<int>::iterator const_iterator = l.begin();
    for (;const_iterator!=l.end();)
    {
        std::cout<<const_iterator.p->data<<std::endl;
        if (const_iterator.p->data == 2999) {
            // l.erase(const_iterator);
            // ++const_iterator;
            l.insert(const_iterator, 3, 3000);
        }else {
            // ++const_iterator;
        }
        ++const_iterator;
    }

    std::cout << l.size() << std::endl;
    // swap
    TinySTL::list<int> l2;
    l2.push_back(11);
    l2.push_back(11);
    l2.push_back(22);
    l2.push_back(33);
    l2.push_back(44);
    l.swap(l2);
    // merge
    l.merge(l2);
    l.reverse();
    l.unique();
    print_list(l);
    // error
    // l.sort(compare_int);
    // l.sort();
    // print_list(l2);
    l.clear();
    std::cout<<l.empty() << std::endl;
    std::cout<<l2.empty() << std::endl;
    std::cout << "end use list~~~~~" << std::endl;

}

void use_stack()
{
    std::cout << "start use stack ~~~~~" << std::endl;
    TinySTL::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty()){
        int i = s.top();
        s.pop();
        std::cout << "stack node:"<< i << std::endl;
    }

    std::cout << "end use stack ~~~~~" << std::endl;
}



int tstl_case() {
    // alloc
    TinySTL::alloc* a = new TinySTL::alloc();
    a->allocate(50);
    a->allocate(50);
    // a->allocate(5);
    // a->allocate(5);
    a->allocate(119);
    a->allocate(127);
    // a->allocate(127);
    int *ii = TinySTL::allocator<int>::allocate();
    char *cc = TinySTL::allocator<char>::allocate(100);
    cc[99] = 'v';
    cc[10] = 'o';
    cc[1] = 'h';
    TinySTL::allocator<char>::deallocate(cc, 100);
    cc = TinySTL::allocator<char>::allocate(100);
    int x = 10;
    int y = 20;
    TinySTL::equal_to<int> equal;
    TinySTL::less<int> les;
    std::cout << equal(x,y) <<std::endl;
    std::cout << les(x,y) <<std::endl;

    // TinySTL::vector<int> vec_i(10);
    // int jjj = int();
    // TinySTL::vector<char> vec_c(10);
    TinySTL::vector<TTTeacher> vec_d(10);
    std::cout<< "sizeof TTT:"<< sizeof(TTTeacher) << std::endl;
    // TinySTL::vector<int> vec_i(10);

    // vec_i.push_back(111);
    // vec_i.push_back(222);
    // vec_i.push_back(322);
    // vec_i.push_back(422);
    // vec_i.push_back(522);
    // vec_i.push_back(622);
    // vec_i.push_back(722);
    // vec_i.push_back(822);
    // vec_i.push_back(922);
    // vec_i.push_back(102);
    // vec_i.push_back(112);

    // std::cout<<"~~~~~~~~~~~"<<std::endl;
    // auto b = vec_i.begin();
    // for (; b != vec_i.end(); b++)
    // {
    //     std::cout<<*b<<std::endl;
    // }
    // std::cout<<"~~~~~~~~~~~"<<std::endl;
    use_list();
    use_stack();

    return 0;
}

