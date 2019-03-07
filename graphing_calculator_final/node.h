#ifndef NODE_H
#define NODE_H

/*-------------------------------------------------------
 * Node Structure
 --------------------------------------------------------*/
template <typename T>
struct node{ //STRUCTURE
    node();
    node(T value);

    T item;
    node* next;
};

template <typename T>
node<T>::node(){
    //cout<<endl<<"default"<<endl;
    next=NULL;
}

template <typename T>
node<T>::node(T value){
    //cout<<endl<<"2nd default"<<endl;
    item=value;
    next=NULL;
}

#endif // NODE_H
