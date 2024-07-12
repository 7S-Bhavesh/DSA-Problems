#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node *insertAtBeginning(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
   ptr->data=data;
    return ptr;
}
struct Node *insertAtIndex(struct Node *head,int data,int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    int i=0;
    struct Node * p=head;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node * insertAtEnd(struct Node *head,int data){
    struct Node* ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node *insertAfterNode(struct Node *head,struct Node *prevNode,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
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

//Link 2nd and 3rd Node
     second->data=8;
    second->next=third;

//terminate
     third->data=9;
    third->next=NULL;

    LinkedListTraversal(head);
    // head=insertAtBeginning(head,34);
    // LinkedListTraversal(head);
    // insertAtIndex(head,34,2);
    
    // insertAtEnd(head,7);
    insertAfterNode(head,second,24);
    LinkedListTraversal(head);

}