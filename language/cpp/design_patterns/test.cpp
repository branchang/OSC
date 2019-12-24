
#include <iostream>
#include "facade.h"
#include "adapter.h"
using namespace std;

int facade_test(){
    Facade fa;
    fa.wrapOpration();
    return 0;
}

int adapter_test(){
    Adaptee* adaptee = new Adaptee();
    Target *tar = new Adapter(adaptee);
    tar->request();
    return 0;
}
