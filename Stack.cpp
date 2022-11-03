#include<stdio.h>
#include<stdlib.h>
#include"Doubly_linked_list.h"


class Stack{
    private:
       Linked_list lst;
    public: 
       int pop();
       void push(int x);
       void printStack();
       int isEmpty();
};

int Stack::isEmpty(){
    if(lst.head==NULL){return 1;}
    return 0;
}
int Stack::pop(){
   Node* ptr=lst.tail;
   int x = ptr->value; //we cannot simply fetch the "value" because its private in Node and its friend class is linked list and not stack and lst.tail->value doesn't make it look like its being accessed via Linkedlist it is still accessed through Node and hence will throw an error so a way to fetch this is by writing friend class Stack in the Node
   lst.removeBack();
   return x;

}

void Stack::push(int x){
    lst.addBack(x);
}

void Stack:: printStack(){
    lst.printList();
    
}
