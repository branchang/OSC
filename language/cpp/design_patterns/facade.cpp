

#include "facade.h"

Facade::Facade(){
    m_systemA = new SystemA();
    m_systemB = new SystemB();
    m_systemC = new SystemC();
}

Facade::~Facade(){
    delete m_systemA;
    delete m_systemB;
    delete m_systemC;
}

void Facade::wrapOpration(){
    m_systemA->operationA();
    m_systemB->operationB();
    m_systemC->operationC();
}