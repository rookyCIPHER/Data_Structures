#include<stdio.h>
#include<stdlib.h>

int size=0;

class Node{
    private:
        int value;
        Node* next;
        Node* prev;
    public:
        Node(int element, Node* ptr){
            size++;
            value=element;
            next=ptr;
        }
        Node(int element){
            size++;
            value=element;
            next=NULL;
        }
    friend class Linked_list;
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
       int isEmpty();


       Linked_list();

};

    Linked_list::Linked_list(){
        
        head=NULL;
        tail=NULL;
       
    }

    void Linked_list::addFront(int element){
        Node* n1=new Node(element);
        n1->next=head;
        n1->prev=NULL;
        if(size==1){tail=n1;}
        head = n1;
    }

    int Linked_list::length(){
        return size;
    }

    void Linked_list::printList(){
        Node* iter=head;
        do{
            printf("%d ",iter->value);
            iter=iter->next;
        }while(iter!=NULL);
        printf("\n");
    }

    int Linked_list:: isEmpty(){
        if(head==NULL){return 1;}
        return 0;
    }

    void Linked_list::addBack(int element){
        //Node* n2=new Node(element);
        if(this->isEmpty()==1){
           addFront(element);
        } else {
            Node* n2=new Node(element);  //we cannot write it earlier because if the list is empty and the node n2 would be created before and size would become 1 but if the list was empty then it would go to addfront function(and n2 would not be used at all as its used in only addback) where it will create another node n1 and size would become 2 (because my size is increased in constructotr of node), which is not the case because we never used n2 we are still adding the first element. And due to size 2 the size==1 condition would never be met in the addfront condition and hence adding the first element using addback would throw an error overall
            tail->next=n2;
            n2->prev=tail;
            tail=n2;
        }

    }

    int Linked_list::search(int element){
        Node* iter=head;
        while(iter!=NULL){
            if(iter->value==element){
                return 1;
            }else{
                iter=iter->next;
            }
        }
        return 0;

    }

    void Linked_list::removeFront(){
        Node* iter=head->next;
        free(head);
        head=iter;
        iter->prev=NULL;
        size--;
    }

    void Linked_list::removeBack(){
        Node* iter=tail->prev;
        free(tail);
        iter->next=NULL;
        tail=iter;
        size--;
    }

