#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"
#include "queue.h"

/*-------------------------------------------------------
 * Number Class
 * Private Member Variables: A character for face value
 * and value of precendence
 * Purpose: It is a derived class of Token
 --------------------------------------------------------*/
class Operator:public Token
{
private:
    char face;
    int prec;

public:
    Operator();
    Operator(char f);
    int Type()const;
    int Prec()const;
    char Face()const;
    void Print()const;
    friend ostream& operator <<(ostream &out, const Operator &o);

};

/*============Operator Default Constructors==========*/
Operator::Operator(){
    cout<<"Operator Default Ctor"<<endl;
}

/* ---------------------------------------------------
/* Operator();
 * This default constructor is automatically called
 * when we insert a token pointer into a Queue
 * The switch statement will recognize which
 * character I entered in to store in the Queue and
 * will assign the respective precedence
 ----------------------------------------------------*/
Operator::Operator(char f){
    face=f;
    switch(f){
    case '+':
    case '-':
        prec=1;
        break;
    case '/':
    case '*':
        prec=2;
        break;
    case '^':
        prec=3;
        break;
    case 's': //sin cos tan
    case 'S':
    case 'c':
    case 'C':
    case 't':
    case 'T':
        prec=4;
        break;
    case ')':
    case '(':
        prec=5;
        break;
    case '#':
        prec=6;
        break;
    default:
        cout<<"Operator Switch: default"<<endl;
        break;
    }
}

/*============Operator Member Functions==========*/
/* ---------------------------------------------------
 * Prec(); Print(); Type(); Face();
 * Each function must be virtual here or there is no way
 * the parent class can have access to these values when
 * we are pushing token pointers into the queue
 ----------------------------------------------------*/
ostream &operator<<(ostream &out, const Operator &o){
    o.Print();
    return out;
}

int Operator::Prec()const{
    return prec;
}

void Operator::Print()const{
    cout<<face;
}

int Operator::Type()const{
    return 1; //returning value 1 means token pointer is an operator
}

char Operator::Face()const{
    return face;
}


#endif // OPERATOR_H
