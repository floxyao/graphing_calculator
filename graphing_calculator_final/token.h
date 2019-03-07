#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

/*-------------------------------------------------------
 * Token Class
 * Private Member Variables: -
 * Purpose: It is the parent class of operator and number
 * Acts as a "connector" to all of the derived classes
 --------------------------------------------------------*/
class Token
{
public:
    Token();

    virtual void Print()const;
    virtual int Type()const; //number or operator
    virtual int Prec()const; //precedence of op
    virtual char Face()const; //face of operator
    virtual double Value()const; //value of number

    bool isLeftP()const;
    bool isRightP()const;
    bool isNum()const;
    bool isTrig()const;
    bool isVariable()const;

    friend bool operator > (const Token &left, const Token &right);
    friend bool operator < (const Token &left, const Token &right);
    friend ostream &operator <<(ostream &out, const Token &t);
    friend istream &operator >>(istream &in, const Token &t);
};

/*================Token Default Constructor=================*/
Token::Token(){
    //cout<<"Token Default Ctor"<<endl;
}

/*================Token Member Functions=================*/
/* ---------------------------------------------------
 * Face();
 * Virtuality allows this parent class to access the
 * child's Face function which returns the char
 * of the operator (operator class)
 ----------------------------------------------------*/
char Token::Face()const{
    //empty
}

/* ---------------------------------------------------
 * Value();
 * Virtuality allows this parent class to access the
 * child's Value function which returns the value
 * of the number (for number class)
 ----------------------------------------------------*/
double Token::Value()const{
    //empty
}

/* ---------------------------------------------------
 * Type();
 * Virtuality allows this parent class to access the
 * child's Type() function. The outside functions will
 * call this in order to know what Type of token pointer
 * it is
 ----------------------------------------------------*/
int Token::Type()const{
    //empty
}

/* ---------------------------------------------------
 * Prec();
 * Virtuality allows this parent class to access the
 * child's Prec() function in respect to operator class
 ----------------------------------------------------*/
int Token::Prec() const{
    //empty
}

/* ---------------------------------------------------
 * isNum();
 * Returns true or false if the Type in the children
 * is a certain number. This function evaluates to be
 * true when it gets the Type value from its child
 * 0 means it is a number
 ----------------------------------------------------*/
bool Token::isNum()const{
    if(Type()==0){
        return true;
    }
    return false;
}

/* ---------------------------------------------------
 * Print();
 * This is virtual so it will, by default, call the
 * child's print function if they have one
 ----------------------------------------------------*/
void Token::Print()const{
    //empty
}

/* ---------------------------------------------------
 * Extraction operator
 * Calls Print();
 ----------------------------------------------------*/
ostream &operator <<(ostream &out, const Token &t){
    t.Print();
    return out;
}

istream &operator >>(istream &in, const Token &t){
//    if(t.Type() == 0){ //num
//        in >> t.Value();

//    }
//    else if(t.Type() == 1){ //op
//        in >> t.Face();
//    }
}

/* ---------------------------------------------------
 * isVariable();
 * Returns true if the face of the operator is 'x'
 ----------------------------------------------------*/
bool Token::isVariable()const{
    if(Face()=='x'){
        return true;
    }
    else{
        return false;
    }
}

/* ---------------------------------------------------
 * isTrig();
 * Returns true if the precedence of the operator is 4
 * aka it is a trig function. Outside handles trig functions
 * differently in the calculations
 ----------------------------------------------------*/
bool Token::isTrig()const{
    if(Prec()==4){
        return true;
    }
    else{
        return false;
    }
}

/* ---------------------------------------------------
 * Boolean Operators
 * Compares the precendence of each token and
 * returns true/false accordingly
 ----------------------------------------------------*/
bool operator > (const Token &left, const Token &right){
    cout<<endl<<"entered > operator"<<endl;
    if(left.Prec() > right.Prec()){
        return true;
    }
    else{
        return false;
    }
}

bool operator < (const Token &left, const Token &right){
    cout<<endl<<"entered < operator"<<endl;
    if(left.Prec() < right.Prec()){
        return true;
    }
    else{
        return false;
    }
}

/* ---------------------------------------------------
 * isRightP(); isLeftP();
 * This is for shunting yard to know what kind of
 * parenthesis it is.
 ----------------------------------------------------*/
bool Token::isRightP()const{
    if(Face()==')'){
        return true;
    }
    else{
        return false;
    }
}
bool Token::isLeftP()const{
    if(Face()=='('){
        //cout<<endl<<"returning true left p";
        return true;
    }
    else{
        //cout<<endl<<"returning false left p";
        return false;
    }
}

#endif // TOKEN_H
