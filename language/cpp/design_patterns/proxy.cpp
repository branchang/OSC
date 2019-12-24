#include "proxy.h"
#include <iostream>
using namespace std;

Proxy::Proxy(){
    m_pRealSubject = new RealSubject();
}

Proxy::~Proxy(){
    delete m_pRealSubject;
}

void Proxy::afterRequest(){
    cout << "Proxy::afterRequest" << endl;
}

void Proxy::preRequest(){
    cout << "Proxy::preRequest" << endl;
}
void Proxy::request(){
    preRequest();
    m_pRealSubject->request();
    afterRequest();
}

class Teacher
{
    public:
        void GiveLesson();
    protected:
        string m_strName;
    private:

};
