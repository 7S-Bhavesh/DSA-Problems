#include <stdio.h>
struct Queue{
    int size;
    int *arr;
    int f;
    int r;
};
int isEmpty(struct Queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int isFull(struct Queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q,int val){
    if(isFull(q)){
        printf("queue overflow");
    }
    else{
        q->r=q->r + 1;
        q->arr[q->r]=val;
    }
}
int dequeue(struct Queue *q){
    if(isEmpty(&q)){
        printf("queue underflwo");
    }
    q->f++;
    int x=q->arr[q->f];
    return x;
}
int main(){
    struct Queue q;
    q.size=10;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size * sizeof(int));

    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    printf("Popped out %d",dequeue(&q));
    printf("Popped out %d",dequeue(&q));
}