#ifndef MYSTACK_H
#define MYSTACK_H
#include "node.h"
#include "util.h"

/*-------------------------------------------------------
 * Stack Class
 --------------------------------------------------------*/
template <typename T>
class Stack
{
private:
    node<T>* head;

public:
    Stack();

    ~Stack<T>();
    Stack<T>(const Stack &other);
    Stack<T> &operator =(const Stack &rhs);

    node<T>* Push(const T &item);
    T Pop();
    void Print();
    void PrintP()const;
    bool isEmpty();
    int Length();

    node<T>* Head(); //accessor

};


/*============Stack Default Constructors==========*/
template <typename T>
Stack<T>::Stack(){
    //cout<<endl<<"Stack Default Ctor"<<endl;
    head=NULL;
}

/*================Stack Big Three==============*/
template <typename T>
Stack<T>::~Stack(){
    //cout<<endl<<"Stack Dtor"<<endl;
    if(head!=NULL){
        _Clear(head);
    }
    head=NULL;
}

template <typename T>
void Stack<T>::PrintP()const{
    if(head!=NULL){
        node<T>* walker=head;
        while(walker){
            cout<<walker->item<<" ";
            walker=walker->next;
        }
    }
    else{
        cout<<endl<<"Stack print error"<<endl;
    }
}

template <typename T>
Stack<T>::Stack(const Stack &other){
    head=_CopyList(other.head);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &rhs){
    if(head!=NULL){
        _Clear(head);
    }
    head=NULL;
    if(rhs.head!=NULL){
        head=_CopyList(rhs.head);
    }
}

/*============Stack Member Functions==========*/
template <typename T>
int Stack<T>::Length(){
    int length=0;
    node<T>* walker=head;
    while(walker){
        walker=walker->next;
        length++;
    }
    return length;
}


template <typename T>
node<T> *Stack<T>::Push(const T &item){
    node<T>* temp=new node<T>(item);
    temp->next=head;
    head=temp;
    return head;
}

template <typename T>
T Stack<T>::Pop(){
    T item;
    if(head!=NULL){
        item=head->item;
        node<T>* temp=head->next;
        head=NULL;
        head=temp;
    }
    return item;
}

template <typename T>
bool Stack<T>::isEmpty(){
    if(head==NULL){
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::Print(){
    if(head!=NULL){
        node<T>* walker=head;
        while(walker){
            cout<<*walker->item<<" ";
            walker=walker->next;
        }
    }
    else{
        cout<<endl<<"Stack print error"<<endl;
    }
}

template <typename T>
node<T>* Stack<T>::Head(){
    return head;
}





#endif // MYSTACK_H
