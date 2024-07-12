#include <stdio.h>

int main(){
    int arr[12]={1,2,2,5,7};
    int size=5;
    int element=5;
   int start=0;
   int end=size-1;
   while(start<=end){
    int middle=(start+end)/2;
        if(arr[middle]==element){
            printf("element found at index:%d",middle);
            break;
        }
        else if(arr[middle]>element){
            end=middle-1;
        }
        else{
            start=middle+1;
        }
   }

}