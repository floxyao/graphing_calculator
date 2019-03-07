#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "operator.h"
#include "number.h"
#include "const.h"
#include "util.h"
using namespace std;

/*-------------------------------------------------------
 * Queue Class
 * Private Member Variables: A array of token pointers
 * Purpose: Container for the infixed expression
 * Templated because we can have different types of
 * things stored into Queue be it char, doubles, or strings
 --------------------------------------------------------*/
template <typename T>
class Queue
{
public:
    Queue();

    ~Queue<T>();
    Queue<T>(Queue<T> &other);
    Queue<T> &operator =(Queue<T> &rhs);

    Queue<Token*> Input(istream &in);

    T Remove();
    T RemoveUnary(int index);
    T& operator [](int i);
    int Length();
    bool isEmpty()const;
    void Print()const;
    void PrintP()const;
    void AddHead(const T &item);
    void Add(const T &item);
    void setSize(double s);
    //istream& Input(istream &in, Token *&item);

private:
    T q[MAX];
    int size;
};

/*============Queue Default Constructor==========*/
template <typename T>
Queue<T>::Queue(){
    //cout<<"Queue default"<<endl;
    size=0;
}

/*=================Queue Big Three===============*/
/*-------------------------------------------------------
 * ~Queue();
 * Destructor gets called because I'm creating new objects
 * out on the heap, must delete it before this destructor
 --------------------------------------------------------*/
template <typename T>
Queue<T>::~Queue(){
//    cout<<endl<<"Queue dtor"<<endl;
//    if(!isEmpty()){ //q!=NULL
//        cout<<endl<<"Dtor firing because main q is NOT EMPTY"<<endl;
//        _Delete(q, size);
//    }
//    cout<<endl<<"Queue dtor NULL reset"<<endl;

//    for(int i=0; i<size; i++){
//        if(q[i]!=NULL){
//            delete q[i];
//        }
//    }
}

/*-------------------------------------------------------
 * Queue Copy Constructor
 --------------------------------------------------------*/
template <typename T>
Queue<T>::Queue(Queue<T> &other){
    //cout<<endl<<"Queue Copy ctor"<<endl;
    size=other.size;
    _Copy(q, other.q, size);
}

/*-------------------------------------------------------
 * Queue Assignment Operator
 --------------------------------------------------------*/
template <typename T>
Queue<T> &Queue<T>::operator =(Queue<T> &rhs){
    //cout<<endl<<"Entered Queue = op"<<endl;
    if(!isEmpty()){
        //cout<<endl<<"not empty...deleting"<<endl;
        //_Delete(q, size);
    }
    size=rhs.size;
    _Copy(q, rhs.q, size);
    //cout<<endl<<"after copying"<<endl;
}


/*-------------------------------------------------------
 * AddHead();
 * Takes an item and adds it to the front of the queue
 --------------------------------------------------------*/
template <typename T>
void Queue<T>::AddHead(const T &item){
    if(size<MAX){
        size++;
        _ShiftRight(q, size);
        q[0]=item;
    }
}

/*-------------------------------------------------------
 * Remove Unary();
 * For cases like x*-2, this function will remove
 * both the negative and 2 and replace it with #
 --------------------------------------------------------*/
template <typename T>
T Queue<T>::RemoveUnary(int index){
    T removeMe=q[index];
    if(!isEmpty()){
        _ShiftHere(q, size, index);
        size--;
    }
    else{
        cout<<endl<<"(Queue Remove) Container is empty"<<endl;
    }
    return removeMe;
}

/*-------------------------------------------------------
 * Add();
 * Takes a an item type to be added into this queue
 * Checks if the array is not full already
 * Adds the item and updates the size
 --------------------------------------------------------*/
template <typename T>
void Queue<T>::Add(const T &item){
    if(size<MAX){
        //size++;
        q[size]=item;
        size++;
    }
    else{
        cout<<endl<<"(Queue Add) is full"<<endl;
    }
}

/*-------------------------------------------------------
 * Bracket operator
 * Allows the compiler to recognize that this item in this
 * index of the array is a token pointer so I can call the
 * token functions
 --------------------------------------------------------*/
template <typename T>
T &Queue<T>::operator [](int i){
    return q[i];
}

/*-------------------------------------------------------
 * setSize();
 * Mutator, changes the size
 --------------------------------------------------------*/
template <typename T>
void Queue<T>::setSize(double s){
    size=s;
}

/*-------------------------------------------------------
 * isEmpty();
 * Checks if the array is empty
 * Returns true if it's empty
 * Returns false if it's not empty
 --------------------------------------------------------*/
template <typename T>
bool Queue<T>::isEmpty()const{
    if(size<=0){
        //cout<<"(Queue isEmpty) Array is not empty"<<endl;
        return true;
    }
    else{
        return false;
    }
    //cout<<"(Queue isEmpty) Array is empty"<<endl;

}

/*-------------------------------------------------------
 * Remove();
 * Removes the first element in the array
 * Calls shift to shift elements one space to the left
 * Acts like a Pop function but with an array
 * Updates the size
 * Returns the item removed
 --------------------------------------------------------*/
template <typename T>
T Queue<T>::Remove(){
    T removeMe=q[0];
    if(!isEmpty()){
        _ShiftLeft(q, size);
        size--;
    }
    else{
        cout<<endl<<"(Queue Remove) Container is empty"<<endl;
    }
    return removeMe;
}

/*-------------------------------------------------------
 * Length();
 * Returns the length of the array
 --------------------------------------------------------*/
template <typename T>
int Queue<T>::Length(){
    return size;
}

/*-------------------------------------------------------
 * Print();
 * Prints the array
 * Must dereference the item in the index which is a token pointer
 --------------------------------------------------------*/
template <typename T>
void Queue<T>::Print()const{
    for(int i=0; i<size; i++){
        cout<<"["<<*q[i]<<"] ";
    }
}

/*-------------------------------------------------------
 * PrintP();
 * This is for when the object is not a pointer, no
 * need to dereference like the above Print();
 --------------------------------------------------------*/
template <typename T>
void Queue<T>::PrintP()const{
    for(int i=0; i<size; i++){
        cout<<q[i];
        cout<<endl;
    }
}

#endif // QUEUE_H
