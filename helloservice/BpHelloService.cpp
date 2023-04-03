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

int32_t BpHelloService::sumCal(uint32_t val1, uint32_t val2) {
    Parcel data, reply;

    data.writeInt32(val1);
    data.writeInt32(val2);

    remote()->transact(TEST, data, &reply);

    return reply.readInt32();
}