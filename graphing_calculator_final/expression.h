#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "queue.h"
#include "mystack.h"
#include "operator.h"
#include "number.h"
#include <cmath>

/*-------------------------------------------------------
 * Expression Class
 * Private Members: Infix and Postfix expressions
 * Purpose: This class handles all the shunting yard
 * calculations and evaluates the expression given a
 * specified variable
 --------------------------------------------------------*/
class Expression
{
private:
    Queue<Token*> infix;
    Queue<Token*> postfix;

public:
    Expression();
    Expression(Queue<Token*> ifx);
    Queue<Token*> expression; //this temporarily holds the
                              //postfix expression with 'x'
                              //variable already substituted
                              //because i want Eval(); to
                              //take no arguments

    int Length();
    bool isSin();
    bool isCos();
    bool isTan();
    void Print();
    void ShowPostfix();
    void Shunt(Queue<Token*> &ifx);
    void PushRemainingOps(Stack<Token*> s, Queue<Token*> &q);
    void checkUnary(Queue<Token*> &ifx);
    double Eval();
    double EvalVariable(double xVal);
    double TrigCalc(Token* num1, Token* op);
    double Calculate(Token* num1, Token* num2, Token* op);
};

/*============Expression Default Constructors==========*/
Expression::Expression(){
    //cout<<endl<<"Exp default"<<endl;
}

/* ---------------------------------------------------
/* Default Constructor
 * Takes an infix expression
 * Calls Shunting Yard and stores postfix expression
--------------------------------------------------------*/
Expression::Expression(Queue<Token*> ifx){
    //cout<<"Exp 2nd default"<<endl;
    checkUnary(ifx);
    infix=ifx;

    //    cout<<endl<<"after Unary check"<<endl;
    //    cout<<"printing input: "; ifx.Print();
    //    cout<<endl<<"printing infix: "; infix.Print();

    Shunt(ifx);

    //cout<<endl<<"after shunting yard"<<endl;
    //ifx.Print();

    postfix=ifx;
}


/*============Expression Member Functions==========*/
/*-------------------------------------------------------
 * checkUnary();
 * Goes through the array of tokens
 * Finds the negative operator, replaces it with
 * a pound sign, and then input it into the exp
 --------------------------------------------------------*/
void Expression::checkUnary(Queue<Token *> &ifx){
    //cout<<endl<<"CheckUnary Entered"<<endl;
    int length = ifx.Length();

    //cout<<"CheckUnary: Printing ifx: "; ifx.Print();
    //cout<<"CheckUnary: Length is: "<<length;

    //checks if the first item is unary minus
    if(ifx[0]->Face()=='-'){
        ifx.Remove();
        ifx.Remove();
        ifx.AddHead(new Operator('#'));
    }
    else{
        for(int i=0; i<length-2; i++){
            cout<<endl<<"CheckUnary: ENTERED LOOP"<<endl;
            if(!ifx[i]->isNum() && ifx[i+1]->Face()=='-'){
                cout<<endl<<"CheckUnary: i see a neg"<<endl;
                Token* key=ifx.RemoveUnary(i+2);
                cout<<endl<<"key removed: ";
                cout<<key->Face();
                ifx[i+1]=new Operator('#');
                cout<<endl<<"After removing: ";
                ifx.Print();
            }
        }
    }

    //cout<<endl<<"Printing Unary: "<<endl;
    //ifx.Print();
}

/* ---------------------------------------------------
/* EvalVariable();
 * Takes a postfix expression
 * Evaluates based on variable entered by user
 * Replaces 'x' char with value entered
 * Calls evaluate and returns the result
--------------------------------------------------------*/
double Expression::EvalVariable(double xVal){
    //cout<<endl<<"postfix before fucking stuff: "; postfix.Print();
    //cout<<endl<<"postfix print:"<<endl;
    //postfix.Print();
    //checkUnary(infix);
    Queue<Token*> e=postfix;

    int length=e.Length();
    //cout<<endl<<"e print: "; e.Print();

    //cout<<endl<<"EvalVariable: after checkUnary print: ";
   // e.Print();

    for(int i=0; i<length; i++){
        if(e[i]->Face()=='x'){
            //cout<<endl<<endl<<"xVal coming in is: "<<xVal<<endl;
            e[i]=new Number(xVal);
        }
        if(e[i]->Face()=='#'){
            e[i]=new Number(xVal*-1);
        }
    }
    expression=e;
    return Eval();
}

/* ---------------------------------------------------
/* Eval();
 * Takes an infix expression to evaluate
 * Checks if token that is popped is a number or operator
 * If it's a number, push into number stack
 * If it's an operator, push into operator stack
 * Pops the first two tokens if it's a non-trig operator
 * Pops only one token if it's a trig operator
--------------------------------------------------------*/
double Expression::Eval(){
    Stack<Token*> numStack;
    Queue<Token*> evalMe=expression;

    bool empty=evalMe.isEmpty();
    double result=0;
    while(!empty){
        Token* head = evalMe.Remove();
        if(head->isNum()){
            numStack.Push(head);
        }
        else if(head->isTrig()){
            //cout<<endl<<"entered is trig"<<endl;
            Token* x = numStack.Pop();
            result=TrigCalc(x, head);
            numStack.Push(new Number(result));
        }
        else{
            //cout<<endl<<"entered is not trig"<<endl;
            Token* x = numStack.Pop();
            Token* y = numStack.Pop();
            result=Calculate(x, y, head);
            numStack.Push(new Number(result));
        }
        empty=evalMe.isEmpty();
    }
    return result;
}

/* ---------------------------------------------------
/* TrigCalc();
 * Evaluates an expression with a trig operator in it
 * Will calculate according to the switch statements
--------------------------------------------------------*/
double Expression::TrigCalc(Token* num1, Token* op){
    switch(op->Face()){
    case 's':
    case 'S':
        //cout<<"sin op"<<endl;
        return (sin(num1->Value()));
        break;
    case 'c':
    case 'C':
        //cout<<"cos op"<<endl;
        return (cos(num1->Value()));
        break;
    case 't':
    case 'T':
        //cout<<"tan op"<<endl;
        return (tan(num1->Value()));
        break;
    default:
        //cout<<"Default"<<endl;
        return 0;
        break;
    }
}

/* ---------------------------------------------------
/* Calculate();
 * Takes the top two token pointers popped from outside
 * Evaluates an expression normally if no trig operators are popped
--------------------------------------------------------*/
double Expression::Calculate(Token* num1, Token* num2, Token* op){
    switch(op->Face()){
    case '+':
        return (num2->Value()+num1->Value());
        break;
    case '-':
        return (num2->Value()-num1->Value());
        break;
    case '/':
        return (num2->Value()/num1->Value());
        break;
    case '*':
        return (num2->Value()*num1->Value());
        break;
    case '^':
        return (pow(num2->Value(), num1->Value()));
        break;
    default:
        //cout<<"Default"<<endl;
        return 0;
        break;
    }
}

/* ---------------------------------------------------
/* Shunt();
 * Takes an infix expression to convert into postfix
 * Pops the front of token, checks if it is a variable, number, or operator
 * Pushes it in either operator stack or number stack according to what is popped
 * Checks if the infix expression is empty at the end of each loop
--------------------------------------------------------*/
void Expression::Shunt(Queue<Token*> &ifx){
    //cout<<endl<<"Shunt Fired"<<endl;
    Stack<Token*> opStack;
    Queue<Token*> outputQ;
    bool empty=ifx.isEmpty();
    while(!empty){
        Token* qHead = ifx.Remove();
        if(qHead->isNum() || qHead->isVariable()){
            outputQ.Add(qHead);
        }
        else{ //empty or left parenth
            if(opStack.isEmpty() || opStack.Head()->item->isLeftP()){
                opStack.Push(qHead);
            }
            else{ //not empty -> compare prec unless it's a right parenth
                if((qHead->isLeftP())){
                    opStack.Push(qHead);
                }
                else if (qHead->Prec() > opStack.Head()->item->Prec() && !qHead->isRightP()){
                    //cout<<endl<<"qHead is greater prec"<<endl;
                    opStack.Push(qHead);
                }
                else if (qHead->Prec() < opStack.Head()->item->Prec() && !qHead->isRightP()){
                    //cout<<endl<<"qHead is lower prec"<<endl;
                    Token* lowerPrec = opStack.Pop();
                    outputQ.Add(lowerPrec);
                    opStack.Push(qHead);
                }
                else if(qHead->isRightP()){
                    while(!opStack.Head()->item->isLeftP()){
                        Token* popThis = opStack.Pop(); //pop until '('
                        outputQ.Add(popThis);
                    }
                    opStack.Pop(); //removes '('
                }
            }
        }
        empty=ifx.isEmpty();
    }
    PushRemainingOps(opStack, outputQ);
    //cout<<"Copying outputQ to ifx..."<<endl;
    ifx=outputQ;
}

/* ---------------------------------------------------
/* isTan(); isCos(); isSin();
 * Returns true if tan/cos/sin function
 * This is for showing the domain in my graph class
--------------------------------------------------------*/
bool Expression::isTan(){
    int length = infix.Length();
    for(int i=0; i<length; i++){
        if (infix[i]->Face()=='t'){
            return true;
        }
    }
    return false;
}

bool Expression::isCos(){
    int length = infix.Length();
    for(int i=0; i<length; i++){
        if (infix[i]->Face()=='c'){
            return true;
        }
    }
    return false;
}

bool Expression::isSin(){
    int length = infix.Length();
    for(int i=0; i<length; i++){
        if (infix[i]->Face()=='s'){
            return true;
        }
    }
    return false;
}

/* ---------------------------------------------------
/* PushRemainingOps();
 * Pushes whatever operators that are left in the op stack
 * at the end when the numbers all have been pushed
--------------------------------------------------------*/
void Expression::PushRemainingOps(Stack<Token*> s, Queue<Token*> &q){
    int length=s.Length();
    for(int i=0; i<length; i++){
        Token* op=s.Pop();
        q.Add(op);
    }
}

/* ---------------------------------------------------
/* Length();
 * Returns the length of the infix expression
--------------------------------------------------------*/
int Expression::Length(){
    int length=infix.Length();
    for(int i=0; i<length; i++)
        return i;
}

/* ---------------------------------------------------
/* Print() and ShowPostFix();
 * Both are printing functions
*/
void Expression::Print(){
    infix.Print();
}

void Expression::ShowPostfix(){
    postfix.Print();
}




#endif // EXPRESSION_H
