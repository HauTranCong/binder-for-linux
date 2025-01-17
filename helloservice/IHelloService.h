#pragma once
#include <utils/String8.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

class IHelloService: public IInterface
{
    public:
    DECLARE_META_INTERFACE(HelloService);

    enum command {
        SAYHELLO = 0x11,
        SAYHELLO_TO = 0x12,
        TEST = 0x13
    };

    virtual String8 sayhello(void) =0;
    virtual String8 sayhello_to(String8 name) = 0;
    virtual int32_t sumCal(uint32_t val1, uint32_t val2) = 0;
};
