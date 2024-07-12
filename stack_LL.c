#include <stdio.h>
struct Node
{
  int data;
  struct Node *next;
};
int isEmpty(struct Node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct Node *top){
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Node *push(struct Node *top,int data){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->next=top;
    top=n;
    return top;
}
int pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return -1; // Or another value to indicate error
    } else {
        struct Node *n = *top;
        int x = n->data;
        *top = (*top)->next;
        free(n); // Free the memory of the removed node
        return x;
    }
}
void LinkedListTraversal(struct Node *ptr){
    struct Node *p=ptr;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}

int main(){
    struct Node *top=NULL;
    top=push(top,23);
    top=push(top,21);
    top=push(top,7);
    int element=pop(&top);
    printf("popped out %d",element);
    LinkedListTraversal(top);
}