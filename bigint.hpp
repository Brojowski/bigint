#ifndef CS2_BIGINT_H
#define CS2_BIGINT_H

#include <ostream>

class intplace
{
public:
    intplace* higher = nullptr;
    intplace* lower = nullptr;

    intplace();
    intplace(char);
    void setDigit(char);
    char getDigit();
private:
    char value;
};

class bigint
{
public:
    bigint();
    bigint(int);
    bigint(const char[]);
    bigint(const bigint&);
    ~bigint();

    void debugPrint(std::ostream&);
    friend std::ostream& operator<<(std::ostream&, bigint&);
    bool operator==(int);
    bool operator==(const char[]);
    bool operator==(bigint&);

    /* Part 2
    void operator>>();
    void operator+();
    int operator[](int i);
    */

    /* Part 3
    bigint timesDigit(int);
    bigint timesTen(int);
    bigint operator*();
    */

private:
    int length;
    intplace* head = nullptr;
    intplace* tail = nullptr;
    intplace* lastReferencedPos = nullptr;
    int lastReference;
    void addDigit(char);
};

#endif //BIGINT_BIGINT_H
