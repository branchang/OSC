#include <string>
#include <iostream>

#include "Alloc.hpp"
#include "Allocator.hpp"
#include "Functional.hpp"

using namespace  std;

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


    return 0;
}

