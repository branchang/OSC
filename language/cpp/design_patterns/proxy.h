#if !defined _PROXY_H_
#define _PROXY_H_

#include "RealSubject.h"
#include "Subject.h"
class Proxy:public Subject{
    public:
        Proxy();
        virtual ~Proxy();
        void request();
    private:
        void afterRequest();
        void preRequest();
        RealSubject *m_pRealSubject;
};
#endif
