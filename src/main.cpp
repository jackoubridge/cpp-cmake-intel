#include "main.hpp"

int main()
{
    // Regaular for
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < 2; i++)
    {
        do_something();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Regular for: " << elapsed.count() << "ms" << std::endl;

    // Parallel for
    start = std::chrono::high_resolution_clock::now();

    oneapi::tbb::parallel_for(0, 2, [&](size_t i)
    {
        do_something();
    });

    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Parallel for: " << elapsed.count() << "ms" << std::endl;

    return 0;
}

void do_something()
{
    volatile size_t j{};
    for (size_t i = 0; i < 1'000'000; i++)
    {
        j = i;
    }
}
