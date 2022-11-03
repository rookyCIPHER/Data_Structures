#include<stdio.h>
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


