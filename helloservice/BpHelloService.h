#pragma once

#include <IHelloService.h>

using namespace android;

class BpHelloService : public BpInterface<IHelloService>
{   
public:
    BpHelloService(const sp<IBinder>& impl) : BpInterface<IHelloService>(impl){}
        
    virtual String8 sayhello(void);
    virtual String8 sayhello_to(String8 name);
    virtual int32_t sumCal(uint32_t val1, uint32_t val2);
}; 
