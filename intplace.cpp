//
// Created by alex on 8/31/17.
//

#include <iostream>
#include "intplace.h"

intplace::intplace()
{
    setDigit(0);
}

intplace::intplace(char c)
{
    setDigit(c);
}

void intplace::setDigit(char c)
{
    if (c > 9 || c < 0)
    {
        std::cout << "Digit is invalid: " << (int)c << std::endl;
        throw("Digit is invalid.");
    }
    value = c;
}

char intplace::getDigit()
{
    return value;
}



