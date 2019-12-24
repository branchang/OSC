#include "cpprimer.h"

extern const int bufSize2;
extern int bufSize3;

void test_const_var(){
    std::cout<<"extern const var:"<< bufSize2<<std::endl;
    std::cout<<"extern int var:"<< bufSize3<<std::endl;
}
