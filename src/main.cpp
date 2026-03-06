#include "main.h"
#include <dlfcn.h>
#include <iostream>

int main()
{
    // Load library
    void* handle = dlopen("./libmylib.so", RTLD_LAZY);

    if (!handle)
    {
        std::cerr << "dlopen failed: " << dlerror() << std::endl;
        return 1;
    }

    // Function pointer type
    using HelloFunc = void (*)(int);

    // Load the symbol
    HelloFunc hello = (HelloFunc)dlsym(handle, "sayHello");

    const char* err = dlerror();
    if (err)
    {
        std::cerr << "dlsym failed: " << err << std::endl;
        dlclose(handle);
        return 1;
    }

	std::thread t1 (hello, 1);
	std::thread t2 (hello, 2);
	t1.join();
	t2.join();

    dlclose(handle);

    return 0;
}
