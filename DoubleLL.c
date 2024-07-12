#include <stdio.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
 
 void *Traverse(struct Node *head){
    struct Node *p=head;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }

 }
  void *reverseTraverse(struct Node *third){
    struct Node *p=third;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->prev;
    }
    
 }
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

//Allocating Memory to 3 pointers
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));

    //Link 1st and 2nd Node
    head->data=7;
    head->next=second;
    head->prev=NULL;

//Link 2nd and 3rd Node
     second->data=8;
    second->next=third;
    second->prev=head;

//terminate
     third->data=9;
    third->next=NULL;
    third->prev=second;
  Traverse(head);
  printf("\n");
  reverseTraverse(third);

    
}