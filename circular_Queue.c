#include <stdio.h>
#include <stdlib.h>

struct circular_Queue{
    int *arr;
    int f;
    int r;
    int size;
};
int isEmpty(struct circular_Queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int isFull(struct circular_Queue *q){
    if((q->r+1)% q->size==q->f){ 
        return 1;
    }
    return 0;
}
void enqueue(struct circular_Queue *q,int val){
    if (isFull(&q))
    {
       printf("queuue full");
    }
    q->r=(q->r + 1) % q->size;
    q->arr[q->r]=val;
}
int dequeue(struct circular_Queue *q){
    if (isEmpty(q))
    {
        printf("cannot dequeue");
    }
    q->f=(q->f+1)%q->size;
    int x=q->arr[q->f];
    return x;
}
int main(){
    struct circular_Queue q;
    q.size=4;
    q.arr=(int *)malloc(q.size*sizeof(int));
    q.f=-1;
    q.r=-1;

    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    printf("popped out %d",dequeue(&q));
    return 0;
}