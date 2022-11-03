#include<stdio.h>
#include<stdlib.h>

int size=0;

class Node{
    private:
        int value;
        Node* next;
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
    public:
       void addFront(int element);
       void addBack(int element);
       int length();
       int search(int element);
       void printList();
       void removeFront();
       void removeBack();
       int isEmpty();


       Linked_list(){
        head=NULL;
       }

};
    int Linked_list:: isEmpty(){
        if(head==NULL){return 1;}
        return 0;
    }



    void Linked_list::addFront(int element){
        Node* n1=new Node(element);
        n1->next=head;
        head = n1;
    }

    int Linked_list::length(){
        return size;
    }

    void Linked_list::printList(){
        Node* iter=head;
        do{
            printf("%d\n",iter->value);
            iter=iter->next;
        }while(iter!=NULL);
    }

    void Linked_list::addBack(int element){
        Node* iter=head;
        //Node* n2=new Node(element);
        if(this->isEmpty()==1){
            addFront(element);
        }
        else{
        while(iter!=NULL){
            if(iter->next==NULL){
                break;
            }else{
                iter=iter->next;
            }
        }
        Node* n2=new Node(element);
        iter->next=n2;

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
    }

    void Linked_list::removeBack(){
        Node* iter=head;
        while(iter!=NULL){
            if((iter->next)->next==NULL){
                break;
            }else{
                iter=iter->next;
            }
        }
        free(iter->next);
        iter->next=NULL;

    }

int main(){


    Linked_list* list1=new Linked_list;

    
    list1->addBack(300);
    list1->addBack(400);


    list1->printList();
    printf("\n");
    list1->removeBack();

    list1->printList();

    
    
    return 0;
}