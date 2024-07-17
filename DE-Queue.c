#include <stdio.h>
struct Array
{
   int *arr;
   int f;
   int r;
   int size;
};
int isEmpty(struct Array *q){
    if(q->f==-1){
        return 1;
    }
    return 0;
}
int isFull(struct Array *q){
    if(q->f==0 && q->r==q->size-1 || (q->f == q->r + 1)){
        return 1;
    }
    return 0;
}
void frontenqueue(struct Array *q,int val){
    if(isFull(q)){
        printf("queue is Full");
        return;
    }
    else{
       if(q->f==-1){
        q->f=q->r=0;
       }
       else if (q->f == 0) {
        q->f = q->size - 1;
    } 
       else{
        q->f--;
       }
         q->arr[q->f]=val;
    }
}
void Rearenqueue(struct Array *q,int val){
    if(isFull(q)){
        printf("queue is Full");
        return;
    }
    else{
         if(q->f==-1){
        q->f=q->r=0;
       }
       else if (q->f == q->size-1) {
        q->r =0;
    } 
       else{
        q->r++;
       }
        q->arr[q->r]=val;
    }
}
int rearDequeue(struct Array *q){
    int x=-1;
    if(isEmpty(q)){
        printf("no elements to deleted");
        return -1;
    }
    else{
    x=q->arr[q->r];
    if(q->f==q->r){
        q->f=q->r=-1;
       }
       else if (q->r == 0) {
        q->r = q->size - 1;
    }
       else{
            q->r--;
       }
    }
    return x;
}
int FrontDequeue(struct Array *q){
    int a=-1;
    if(isEmpty(q)){
        printf("no elements to deleted");
        return -1;
    }
    else{
   a= q->arr[q->f];
    if(q->f==q->r){
        q->f=q->r=-1;
       }
       else if (q->r == q->size-1) {
        q->f = 0;
    }
    else
    {
         q->f++;
    }
    
   return a;
    }
   
}

int main(){
    struct Array q;
    q.arr=(int *)malloc(q.size*sizeof(int));
    q.size=10;
    q.f=q.r=-1;
     
       frontenqueue(&q, 2);
    frontenqueue(&q, 7);
    Rearenqueue(&q, 4);
    Rearenqueue(&q, 9);

    printf("Front element: %d\n", q.arr[q.f]);
    printf("Rear element: %d\n", q.arr[q.r]);

        printf("Front dequeue: %d\n", FrontDequeue(&q));
    printf("Rear dequeue: %d\n", rearDequeue(&q));


}