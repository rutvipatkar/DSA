#include<stdio.h>

void createArray(int array[], int size){
    int i;
    printf("Enter elements to be sorted:");
    for(i=0;i<size;i++){
        scanf("%d", &array[i]);
    }
};

void merge(int array[], int l, int m, int r){
    int i = l;
    int j = m + 1;
    int k = l;
    int temp[r + 1];
    while(i <= m && j <= r)
    {
        if(array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    while(i <= m)
    {
        temp[k] = array[i];
        i++;
        k++;
    }
    while(j <= r)
    {
        temp[k] = array[j];
        j++;
        k++;
    }
    for(i = l; i <= r; i++)
    {
        array[i] = temp[i];
    }
}

void divideArray(int array[],int l,int r){
    int m;
    if(l<r){
    int m = l+(r-l)/2;
    divideArray(array, l, m);
    divideArray(array,m+1,r);
    merge(array,l,m,r);
    }
};

int main(){
    int size;
    printf("Enter no of elements to be sorted:");
    scanf("%d", &size);
    int i;
    int array[size];
    createArray(array, size);
    divideArray(array,0,size-1);
    printf("Sorted array:");
    for(i=0;i<size;i++){
        printf("%d ",array[i]);
    }
}