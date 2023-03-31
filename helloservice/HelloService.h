#pragma once

#include <binder/BinderService.h>
#include <BnHelloService.h>

class HelloService: public BnHelloService {
public:
    virtual ~HelloService();

    static void publish(void);
    static void publishAndJoinThreadPool(); 

    virtual String8 sayhello();
    virtual String8 sayhello_to(String8 name);
    virtual uint8_t test(uint8_t)
private:
    static void joinThreadPool();
};
