#include <stdio.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
int isFull(struct stack *top){
    struct stack *ptr=(char *)malloc(sizeof(char));
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *sp,int data){
    if(isFull(sp)){
        printf("stack is full");
    }
    sp->top++;
    sp->arr[sp->top]=data;
}
int pop(struct stack *sp){
    if(isEmpty(sp)){
     return -1;
    }
    sp->top--;

    int x=sp->arr[sp->top];
    return x;
}

int Parenthesis(char *exp){
    struct stack *sp;
    sp->size=10;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));

    for (int i = 0; i < exp[i]!='\0'; i++){
        if(exp[i]=='('){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
           pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    return 0;   
}
int main(){
    char *a="8*3+(3*4)";
    if(Parenthesis(a)){
        printf("parenthesis is matching");
    }
    else{
        printf("parenthesis is Not matching");
    }
}