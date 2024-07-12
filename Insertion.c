#include <stdio.h>

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
}
int insertion(int arr[],int size,int capacity,int element,int index){
    if(size>=capacity){
        return -1;
    }
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
        arr[index]=element;
        return 1;
}
void deletion(int arr[],int size,int capacity,int index){
    if(index>=capacity){
        printf("index out of range");
    }
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }

}
int main(){
    int arr[10]={7,8,12,27,88};
    int index=3,element=45,size=5;
    // insertion(arr,size,10,element,index);
    // size++;
    deletion(arr,5,10,2);
    size--;
    display(arr,size);

}