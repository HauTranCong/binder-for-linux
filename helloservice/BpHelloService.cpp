#include <iostream>
#include <BpHelloService.h>

       
String8 BpHelloService::sayhello(void)
{
    Parcel data, reply;
    data.writeInt32(0);
    std::cout << "client: request to say hello\n";
    remote()->transact(SAYHELLO, data, &reply);

    return reply.readString8();
}


String8 BpHelloService::sayhello_to(String8 name)
{
    Parcel data, reply;
    data.writeString8(name);

    std::cout << "client: request to say hello to " << name << "\n";
    remote()->transact(SAYHELLO_TO, data, &reply);

    return reply.readString8();
}

uint8_t BpHelloService::test(uint8_t val) {
    Parcel data, reply;
    data.write(val);

    remote()->transact(TEST, data, &reply);

    return reply.read();
}