#include <iostream>
#include "bigint.hpp"

// Magic Numbers
#define OUTPUT_LETTERS_PER_LINE 50
#define ASCII_SHIFT 48

char asciiToDigit(int);

bigint::bigint()
{
    head = lastReferencedPos = tail = new intplace(0);
    length = 1;
}

bigint::bigint(const int initValue)
{
    int i = initValue;
    head = lastReferencedPos = tail = new intplace(i % 10);
    length = 1;
    do
    {
        i /= 10;
        char digit = i % 10;
        addDigit(digit);
    } while (i > 10);
}

bigint::bigint(const char *str)
{
    int letterIndex = 0;
    char digit;
    // Find out how long this string is.
    while (str[letterIndex] != ';')
    {
        letterIndex++;
    }
    // Last letter will be ';' start with the letter before that
    head = lastReferencedPos = tail = new intplace(asciiToDigit(str[--letterIndex]));
    length = 1;
    // and loop forwards to the beginning of the number.
    for (--letterIndex; letterIndex >= 0; letterIndex--)
    {
        digit = asciiToDigit(str[letterIndex]);
        if (0 <= digit && digit <= 9 )
        addDigit(digit);
    }
}

bigint::bigint(const bigint &oldInt)
{

};

char asciiToDigit(int c)
{
    // ASCII char numbers are 48=0 49=1 ... 57=9 so subt 48 to
    // put it in the valid range.
    return c - ASCII_SHIFT;
}

void bigint::addDigit(char c)
{
    head->higher = new intplace(c);
    head->higher->lower = head;
    head = head->higher;
    length++;
}

void bigint::debugPrint(std::ostream &out)
{
    for (intplace *i = head; i != nullptr; i = i->lower)
    {
        out << (int) i->getDigit() << "|";
    }
    out << std::endl;
}

std::ostream& operator<<(std::ostream& out, bigint& data)
{
    int lettersOnLine = 0;
    intplace* digit;
    // Start at the highest digit and move down.
    for (digit = data.head; digit != nullptr; digit = digit->lower)
    {
        if (lettersOnLine >= OUTPUT_LETTERS_PER_LINE)
        {
            // Move to a new line;
            out << std::endl;
            lettersOnLine = 0;
        }
        // Print digit
        out << (int)digit->getDigit();
        lettersOnLine++;
    }
    return out;
}

bool bigint::operator==(bigint& other)
{
    // must be same # of digits
    if (length != other.length)
    {
        return false;
    }

    // each digit should match
    intplace* mePtr = tail;
    intplace* otherPtr = other.tail;
    bool areSame = true;
    while (areSame && mePtr != nullptr && otherPtr != nullptr)
    {
        if (mePtr->getDigit() != otherPtr->getDigit())
        {
            areSame = false;
        }
        mePtr = mePtr->higher;
        otherPtr = otherPtr->higher;
    }
    return areSame;
}

bigint::~bigint()
{
    intplace* ptr = head;
    intplace* temp;
    // Erase all of the digits for this number;
    while (ptr != nullptr)
    {
        temp = ptr->lower;
        delete ptr;
        ptr = temp;
    }
}
