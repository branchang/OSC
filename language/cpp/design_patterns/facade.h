#if !defined(FACADE_H)
#define FACADE_H

#include "SystemC.h"
#include "SystemA.h"
#include "SystemB.h"

class Facade{
    public:
        Facade();
        virtual ~Facade();
        void wrapOpration();
    private:
        SystemC *m_systemC();
        SystemA *m_systemA();
        SystemB *m_systemB();
};



#endif