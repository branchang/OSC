// 简单工厂模式
#include "factory.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"

Product* Factory::createProduct(string proname){
    if ("A" == proname)
    {
        return new ConcreteProductA();
    }else if ("B" == proname)
    {
        return new ConcreateProductB();
    }
    return NULL;
}
