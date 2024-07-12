#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *head){
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node * deleteFirst(struct Node * head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head,int index){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct Node *deleteAtEnd(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
    
}
struct Node *deleteAGivenNode(struct Node *head,int data){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=data){
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
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

    // head=deleteFirst(head);
    head=deleteAGivenNode(head,8);
    LinkedListTraversal(head);
}