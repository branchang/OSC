#if !defined(ADAPTER_H)
#define ADAPTER_H

#include "Target.h"
#include "Adaptee.h"
class Adapter:public Target {
    public:
        Adapter(Adaptee *adaptee);
        virtual ~Adapter();
        virtual void request();
    private:
        Adaptee *m_pAdaptee;
};
#endif