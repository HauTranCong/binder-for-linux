#include <iostream>
#include <unistd.h>
#include <BpHelloService.h>
#include <binder/IServiceManager.h>

using namespace std;
using namespace android;

String16 serviceName("helloservice");

int main(int argc, char *argv[]) {
    // create a binder 
    sp<IBinder> binder;    
    sp<IServiceManager> sm = defaultServiceManager();

    do {
        binder = sm->getService(serviceName);
        if (binder != 0) break;
        cout << "client: server is not published, waiting..." << endl;
        usleep(5000); // 5 ms
    } while(true);

    cout << "client: connected to server\n";

    sp<IHelloService> service = interface_cast<IHelloService>(binder);

    cout << "client: recv from server: " << service->sayhello() << endl;

    cout << "client: recv from server: " << service->sayhello_to(String8("Jackson")) << endl;

    cout << service->test(String8(100)) << end;
}

