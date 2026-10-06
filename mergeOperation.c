#include<stdio.h>
int main(){
float array1[5] = {98,93.5,89,87,95.6};
float array2[5] = {87.5,82,95.3,99,94.2};

int size1 = sizeof(array1)/sizeof(array1[0]);
int size2 = sizeof(array2)/sizeof(array2[0]);

float mergedArray[10];
int i;
for (i=0; i<size1;i++){
    mergedArray[i] = array1[i];
}

for (i=0;i<size2; i++){
    mergedArray[i+5] = array2[i];
}

printf("Merged array:");
for (i=0; i<10; i++){
    printf("%.2f ", mergedArray[i]);
}

return 0;
}