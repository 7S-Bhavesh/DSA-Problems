#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};
void LinkedListTraverse(struct Node *head){
    struct Node *ptr=head;
    do
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    
}
struct Node * InsertAtfront(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

int main(){
struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

//Allocating Memory to 3 pointers
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    //Link 1st and 2nd Node
    head->data=7;
    head->next=second;

//Link 2nd and 3rd Node
     second->data=8;
    second->next=third;

//terminate
     third->data=9;
    third->next=fourth;

    fourth->data=10;
    fourth->next=head;

    head=InsertAtfront(head,4);
    LinkedListTraverse(head);
}