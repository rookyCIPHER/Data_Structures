/*
Refer: https://youtu.be/HqPJF2L5h9U
2.6.3 Heap - Heap Sort - Heapify - Priority Queues by Abdul Bari
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}

class MaxHeap{
    
    public:
    int* header;
    int heap_size;
    int heap_capacity;

    MaxHeap(int );

    int left(int );
    int right(int );
    int parent(int );

    void insert(int );
    int del();
   

    void maxheapify(int );   

    void printHeap(int ); 
};

MaxHeap::MaxHeap(int cap){
    heap_size=0;
    heap_capacity=cap;
    header= new int[cap];
}

int MaxHeap::left(int i){

    return 2*i+1;
}

int MaxHeap::right(int i){
    return ((2*i)+2);
}

int MaxHeap::parent(int i){
    return (i-1)/2;
}

void MaxHeap:: insert(int val){
    if(heap_size==heap_capacity){
        printf("Overflow\n");
        return;
    }

    heap_size++;
 //   printf("heap size=%d\n",heap_size);
    header[heap_size-1]=val;
  //  printf("header[%d]=%d\n",heap_size-1,header[heap_size-1]);
    maxheapify(heap_size-1);

}

int MaxHeap::del(){
    if(heap_size==0){
        return INT_MIN;
    }

    swap(header[heap_size-1],header[0]);
    int max=header[heap_size-1];

    heap_size--;
    int index=0;

    while(true){//Actually this method of checking in the downward direction is called heapify method, the other one which we marked as heapify is not called heapify. It's just another method to check from bottom to top. 
        int largest;
        int l;
        int r;
        if(left(index)<heap_size && right(index)<heap_size){
            l=left(index);
            r=right(index);
            if(header[l]>header[r]){
             largest=l;
            } else {
                largest=r;
            }
        
            
        }else if(left(index)<heap_size){
            largest=left(index);
        } else {
            break;
        }



        if(header[largest]>header[index]){
            swap(header[largest],header[index]);
            index=largest;
        } else{break;}


    }
    return max;


}

MaxHeap create(int arr[], int size){
    MaxHeap heap(size);
    for(int i=0; i<size;i++){
        heap.insert(arr[i]);
    }
    return heap;
}

void MaxHeap::maxheapify(int i){  //this is not actually heapify method check the comment of del() function to understandd
   // printf("Index received=%d\n",i);
    if(i<=0){
        return;
    }
    int par=parent(i);
   // printf("Parent=%d\n",par);

  //  printf("Values to be compared are header[%d]=%d and header[%d]=%d\n",i,header[i],par,header[par]);
    if(header[par]<header[i]){
        swap(header[i],header[par]);
    }
    
  //  printf("After the swap header[%d]=%d and header[%d]=%d\n",i,header[i],par,header[par]);

  //  printf("i=%d\n",i);
    // while(header[i]>header[parent(i)]){
    //     printf("In while loop if condition.\n");
    //     printf("Values to be compared are header[%d]=%d and header[%d]=%d\n",i,header[i],parent(i),header[parent(i)]);       
    //     swap(header[i],header[parent(i)]);

    // }
  //  printf("\n");
    maxheapify(par);
    

}

void MaxHeap::printHeap(int size){
    for(int i=0;i<size;i++){
        printf("%d ",header[i]);
    }
    printf("\n");
}

void Heap_Sort(int arr[],int size){
    MaxHeap h1=create(arr,size);
    for(int i=0;i<size;i++){
        h1.del();
    }
    h1.printHeap(size);
}




int main(){
    int arr[]={1,-10,3,3,5,6,7,8,9,10};
    Heap_Sort(arr,10);

    return 0;
}

