#ifndef NDEBUG
#include <iostream>
#define LOG(x) { std::cout << x; }
#else
#define LOG(x)
#endif