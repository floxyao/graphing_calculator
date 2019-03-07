#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include "node.h"
using namespace std;

//===========array functions==========
template <typename T>
void _Init(T src[], int size);

template <typename T>
void _Init(T src[], int size){
    for(int i=0; i<size; i++){
        src[i]=NULL;
    }
    //cout<<endl<<"Initialized"<<endl;
}

template <typename T>
void _Delete(T src[], int size);

template <typename T>
void _Delete(T src[], int size){
    //cout<<endl<<"entered delete"<<endl;
    for(int i=0; i<size; i++){
        //cout<<endl<<"enetered loop in delete"<<endl;
        delete[] src[i];
        //cout<<"deleted: "<<*src[i]<<endl;
    }
    //cout<<endl<<"exitting delete"<<endl;
}

template <typename T>
void _Copy(T dest[], T src[], int size);

template <typename T>
void _Copy(T dest[], T src[], int size){
    for(int i=0; i<size; i++){
        dest[i]=src[i];
        //cout<<endl<<"Copying"<<endl;
    }
}

template <typename T>
void _ShiftHere(T src[], int numUsed, int shiftHere);

template <typename T>
void _ShiftHere(T src[], int numUsed, int shiftHere){
    int i=0;
    for(i=0; i<numUsed-2; i++){
        src[shiftHere-1]=src[shiftHere];
        shiftHere++;
    }
}

template <typename T>
void _ShiftLeft(T src[], int numUsed);

template <typename T>
void _ShiftLeft(T src[], int numUsed){
    int i=0;
    for(i=0; i<numUsed; i++){
        src[i]=src[i+1];
    }
}

template <typename T>
void _ShiftRight(T src[], int numUsed);

template <typename T>
void _ShiftRight(T src[], int numUsed){
    int i=0;
    for(i=numUsed-1; i>0; i--){
        src[i]=src[i-1];
    }
}

//=======linked list functions========
template <typename T>
void _Clear(node<T>* &head);

template <typename T>
void _Clear(node<T>* &head){
    if(head!=NULL){
        node<T>* deleteNode=head;
        while(head){
            deleteNode=deleteNode->next;
            delete head;
            head=deleteNode;
        }
    }
    else{
        cout<<endl<<"(_ClearList) List is empty already"<<endl;
        //return NULL;
    }
    head=NULL;
}


template <typename T>
node<T>* _CopyList(node<T>* head);

template <typename T>
node<T>* _CopyList(node<T>* head){
    node<T>* newList=new node<T>;
    node<T>* hold=newList;

    if(head!=NULL){
        newList->item=head->item;
        while(head->next!=NULL){
            head=head->next;
            newList->next=new node<T>(head->item);
            newList=newList->next;
        }
    }
    return hold;
}


#endif // UTIL_H
