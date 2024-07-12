#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int * arr;
    int size;
};
int isEmpty(struct Stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct Stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct Stack *ptr,int data){
    if(isFull(ptr)){
        printf("cannot push stack is full");
    }
    ptr->top++;
    ptr->arr[ptr->top]=data;
}
int pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("No element present in the array");
        return -1;
    }
    int val=ptr->arr[ptr->top];
   ptr->top--;
   return val;
}

int peek(struct Stack *ptr){
    if (isEmpty(ptr))
    {
       printf("No element present in the array");
       return -1;
    }
    return ptr->arr[ptr->top];
}
int main(){
    struct Stack *s=(struct Stack *)malloc(sizeof(struct Stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));

    push(s,23);
    push(s,4);
    push(s,5);
    push(s,93);
    push(s,21);
    push(s,76);
    push(s,34);
    push(s,12);
    push(s,99);
    push(s,232);
    printf("Popped %d from stack",pop(s));
    printf("Popped %d from stack",peek(s));
}