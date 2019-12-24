
#include ""

ConcreateBuilder::ConcreateBuilder(){

}

ConcreateBuilder::~ConcreateBuilder(){

}

void ConcreateBuilder::buildPartA(){
    m_prod->setA("A Style ");
}

void ConcreateBuilder::buildPartB(){
    m_prod->setA("B Style ");

}

void ConcreateBuilder::buildPartC(){
    m_prod->setA("C Style ");
}