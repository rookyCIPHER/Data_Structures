#ifndef Linked_list_H
#define Linked_list_H



class Node{
    private:
        int value;
        Node* next;
        Node* prev;
    public:
        Node(int element, Node* ptr);
        Node(int element);
    friend class Linked_list;
    friend class Stack;
    friend class Queue;
};

class Linked_list{
    private:
        Node* head; 
        Node* tail;
    public:
       void addFront(int element);
       void addBack(int element);
       int length();
       int search(int element);
       void printList();
       void removeFront();
       void removeBack();


       Linked_list();        //in our original class implementation if the constructor function implementation was inside the class then here also it should be specified too we cannot simple leave it at the signature. Because everything written in the classs needs to be implemented here only properties of class defined outside the class can be left to siganture.s that is why its a good practice to only write signatures inside adn rest of the thigns outsude.
    friend class Stack;
    friend class Queue;
};

#endif