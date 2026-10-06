#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low,int high){
    int pivot = arr[high];
   
    int i = low-1;
    int j;

    for(j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap (&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low<high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    int arr[] = {0,3,7,6,1,9,2};
    int size = sizeof(arr)/sizeof(int);
    int t;

    quickSort(arr,0,size-1);

    for(t=0; t<size; t++){
        printf("%d ", arr[t]);
    }

    return 0;
}