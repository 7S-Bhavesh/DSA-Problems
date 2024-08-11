#include <stdio.h>

struct SearchinBST
{
    int data;
    struct SearchinBST *left;
    struct SearchinBST *right;
};

struct SearchinBST *createNode(int data){
    struct SearchinBST *p=(struct SearchinBST *)malloc(sizeof(struct SearchinBST));
    p->data=data;
    p->right=NULL;
    p->left=NULL;
    return p;
}

struct SearchSearchinBST *SearchNode(struct SearchinBST *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data<key){
        SearchNode(root->right,key);
    }
    else{
        SearchNode(root->left,key);
    }
    
}
struct SearchinBST *Searchitr(struct SearchinBST *root,int key){
    while(root!=NULL){
    if(root->data==key){
        return root;
    }
    if(key>root->data){
        root=root->right;
    }
    else{
        root=root->left;
    }
   
    }
    
    return NULL;
}
int main(){
    struct SearchinBST *p=createNode(5); 
    struct SearchinBST *p1=createNode(3); 
    struct SearchinBST *p2=createNode(2); 
    struct SearchinBST *p3=createNode(1); 
    struct SearchinBST *p4=createNode(4); 

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    
    struct SearchinBST *q = Searchitr(p, 7);
    if (q != NULL) {
        printf("%d", q->data);
    }
    else {
        printf("Key not found in the tree.");
    }

    return 0;
    
}