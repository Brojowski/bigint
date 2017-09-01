#include <iostream>
#include "bigint.hpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    bigint b = bigint(4865);
    b.debugPrint(std::cout);

    bigint c = bigint();
    b.debugPrint(std::cout);

    bigint d = bigint("4865548655486554865548655486554865548655486554865548655;");
    d.debugPrint(std::cout);
    std::cout << d << std::endl;

    std::cout << (b == c);

    return 0;
}