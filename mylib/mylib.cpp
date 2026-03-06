#include "mylib.h"

extern "C" void sayHello(int num)
{
    while(true)
	{
	    std::cout << "Hello from my shared library! " << num << std::endl;
	    std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
