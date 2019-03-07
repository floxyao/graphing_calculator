#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"
#include <iostream>
using namespace std;

/*-------------------------------------------------------
 * Number Class
 * Private Member Variables: A number
 * Purpose: It is a derived class of Token
 --------------------------------------------------------*/
class Number:public Token
{
private:
    double num;

public:
    //Default Constructors
    Number(){num=0.0;}
    Number(double n):num(n){}

    int Type()const;
    double Value()const;
    void Print()const;
};

/*============Number Member Functions==========*/
/* ---------------------------------------------------
 * Value();
 * Returns the value of the number
 * Virtual because on the outside, when you
 * pop the token pointers, the token parent
 * needs to be able to access its child
 ----------------------------------------------------*/
double Number::Value()const{
    return num;
}

/* ---------------------------------------------------
 * Type();
 * Returns the type of token pointer (0 means it's a number)
 * Virtuality also applies here
 ----------------------------------------------------*/
int Number::Type()const{
    return 0;
}

/* ---------------------------------------------------
 * Print();
 * prints
 ----------------------------------------------------*/
void Number::Print()const{
    cout<<num;
}




#endif // NUMBER_H
