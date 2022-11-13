#include<stdio.h>
#include<stdlib.h>


//Assuming all elements are distinct in the tree

class TreeNode{
   public:
        int element;
        TreeNode* head;
        TreeNode* left;
        TreeNode* right;
        TreeNode();
        TreeNode(int value);
   
   friend class Tree;

};
//
TreeNode::TreeNode(){
    head=NULL;
    left=NULL;
    right=NULL;
}
//
TreeNode::TreeNode(int value){
    head=NULL;
    left=NULL;
    right=NULL;
    element=value;

}
//





class Tree{
   
   public:
      TreeNode* root;
      Tree();
      void addChild(int value, int pos);
      void addChild(int value);
      int height(TreeNode* ptr);
      int depth(TreeNode* ptr);
      TreeNode* preorderTraversal(TreeNode* ptr, int pos);
      void PrintTree(TreeNode* ptr);
   
};



Tree:: Tree(){
    root = NULL;
}



TreeNode* Tree:: preorderTraversal(TreeNode* ptr, int pos){
     if(ptr==NULL){return NULL;}
     if(pos==ptr->element){return ptr;}

     if(ptr->left==NULL && ptr->right==NULL && ptr->element==pos){
      //  TreeNode* ptr1=preorderTraversal((ptr->children),pos);
        return ptr;  //to carry out of recursive calls in case no children are there 

     }else if(ptr->left==NULL && ptr->right==NULL && ptr->element!=pos){
        return NULL;
     }

    TreeNode* ptr1=preorderTraversal(ptr->left,pos);
    if(ptr1!=NULL){return ptr1;}  //added to carry it out of all the recursive calls 

    TreeNode* ptr2=preorderTraversal(ptr->right,pos);
    if(ptr2!=NULL){return ptr2;}

}



void Tree:: PrintTree(TreeNode* ptr){
    if(ptr==NULL){return ;}

    //Preorder Printing 
    printf("%d ", ptr->element);
    PrintTree(ptr->left);
    PrintTree(ptr->right);
}



void Tree:: addChild(int value){
    TreeNode* tn= new TreeNode(value);
    root=tn;
}



void Tree:: addChild(int value,int pos){
    TreeNode* ptr=preorderTraversal(root, pos);  
    if(ptr->left==NULL){
        TreeNode* tn= new TreeNode(value);
        tn->head =ptr;
        ptr->left=tn;
        if(ptr->left==NULL){printf("Yes\n");}
    }


    else if(ptr->right==NULL){
        TreeNode* tn= new TreeNode(value);
        tn->head=ptr;
        ptr->right=tn;       
    }
    else{
        printf("No more chidlren can be added to this node. \n");
    }
}



int max(int a, int b){
    if(a>b){return a;}
    else{return b;}
}



int Tree:: depth(TreeNode* ptr){
    if(ptr==root){return 0;}
    return (depth(ptr->head)+1);
}



int Tree:: height(TreeNode* ptr){
    // if(ptr->left==NULL && ptr->right==NULL){
    //    return 0;
    //}

    // else{
    int x1=0;
    int x2=0;
    if(ptr->left!=NULL){
        x1=height(ptr->left)+1;
     } 
    //else {
    //     x1=0;
    // }

    if(ptr->right!=NULL){
        x1=height(ptr->right)+1;
    } 

    //else {
    //     x2=0;
    // }
    return max(x1,x2);  
    

}


 


int main(){
   
    Tree tr;
    printf("\n");
    tr.addChild(20);
    tr.addChild(10,20);
    tr.addChild(30,20);
    tr.addChild(60,30);
    tr.addChild(80,30);
    tr.addChild(90,30);

    tr.PrintTree(tr.root);
     printf("\n");
     printf("%d\n", tr.height(tr.preorderTraversal(tr.root,30)));
     return 0;

}