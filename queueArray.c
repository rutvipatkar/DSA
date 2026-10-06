#include <stdio.h>

int front = -1;
int rear = -1;
int size;

void enqueue(int arr[]){
    int data;
    printf("Enter data:");
    scanf("%d", &data);

    if(rear == size-1){
        printf("Queue Overflow\n");
    }

    else if(front == -1 && rear == -1){
        arr[++rear] = data;
        front ++;
    }

    else{
        arr[++rear] = data;
    }
}

void dequeue(int arr[]){
    if(front == -1 && rear == -1){
        printf("Queue Underflow\n");
    }

    else if(front == rear && rear == size-1){
        front = -1;
        rear = -1;
    }

    else{
        front++;
    }
}

void peek(int arr[]){
    if(front == -1 && rear == -1){
        printf("Queue Underflow\n");
    }
    else{
        printf("%d\n" , arr[front]);
    }
}

void display(int arr[]){
    int i;
    if(front == -1 && rear == -1){
        printf("Queue is empty");
    }
    else{
        for (i=front;i<=rear;i++){
        printf("%d \n", arr[i]);
        }
    }
}

int main(){
    printf("Enter the size of queue:");
    scanf("%d", &size);
    int arr[size];
    int a;
    int front = -1;
    int rear = -1;
    do{
    printf("Operations\n");
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. peek\n");
    printf("4. exit\n");
    printf("Enter choice:");
    scanf("%d", &a);
    switch(a){

        case 1:
        enqueue(arr);
        display(arr);
        break;

        case 2:
        dequeue(arr);
        display(arr);
        break;

        case 3: 
        peek(arr);
        break;

        case 4: 
        printf("Exit");

    }
    }
    while(a!=4);
}