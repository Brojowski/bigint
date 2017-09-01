//
// Created by alex on 8/31/17.
//

#ifndef BIGINT_INTPLACE_H
#define BIGINT_INTPLACE_H


class intplace
{
public:
    intplace* higher;
    intplace* lower;

    intplace();
    intplace(char);
    void setDigit(char);
    char getDigit();
private:
    char value;
};


#endif //BIGINT_INTPLACE_H
