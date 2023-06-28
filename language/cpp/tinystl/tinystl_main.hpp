#include <string>
#include <iostream>

#include "Alloc.hpp"
#include "Allocator.hpp"
#include "Functional.hpp"

#include "Vector.hpp"

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

    return 0;
}

