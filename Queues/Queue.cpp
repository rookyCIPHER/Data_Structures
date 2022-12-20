#include<stdio.h>
#include<stdlib.h>
#include"Doubly_linked_list.h"


class Queue{
private:
    Linked_list lst;
public:
    void enqueue(int element);
    void dequeue();
    int isEmpty();
    int first();
    void printQueue();

};

int Queue::isEmpty(){
    if(lst.head==NULL){return 1;}
    return 0;    
}

void Queue::enqueue(int element){
    lst.addBack(element);
}

void Queue:: dequeue(){
    lst.removeFront();

}

int Queue:: first(){

    int x=lst.head->value;
    return x;
}

void Queue::printQueue(){
    lst.printList();
}

int main(){

    Queue q;
    q.enqueue(10);
    q.printQueue();

    q.enqueue(20);
    q.printQueue();

    q.enqueue(30);
    q.printQueue();

    q.dequeue();
    q.printQueue();
    return 0;
}
