#include<stdio.h>
int binarySearch(int arr[], int size, int key){
    int left,right,mid;
    left=0, right=size-1;

    while (left<=right){
        mid = left +(right-left)/2;

        if (key > arr[mid]){
            left = mid+1; 
        } else if (key < arr[mid]){
            right = mid-1;
        } else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[] = {22, 24, 30, 35, 40, 45};
    int key = 40;
    int size = 6;
    int idx = binarySearch (arr,size,key);
    printf("Value at %d", idx);
    return 0;
}