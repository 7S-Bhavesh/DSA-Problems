#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->right=NULL;
    p->left=NULL;
    return p;
}

struct node *insert(struct node *root,int data){
    struct node *new=createNode(data);
    struct node *prev=NULL;
    while(root!=NULL){
        prev=root;
        if(root->data==data){
            printf("cannot insert");
            return;
        }
        if(root->data>data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
        if(prev->data>data){
            prev->left=new;
        }
        else{
            prev->right=new;
        }
    
}
void inOrderTraversal(struct node *root){
    if(root==NULL){
        return NULL;
    }
 inOrderTraversal(root->left);
    printf("%d\n",root->data);
 inOrderTraversal(root->right);
}

int main(){
    struct node *p=createNode(5);
    struct node *p1=createNode(3);
    struct node *p2=createNode(2);
    struct node *p3=createNode(1);
    struct node *p4=createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("Before insertion:\n");
    inOrderTraversal(p);
    
    printf("After inserion:\n");
    insert(p,7);
    inOrderTraversal(p);


    
}