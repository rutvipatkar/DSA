#include<stdio.h>
#include<stdlib.h>

int *stack;
int top = -1;
int size;

int demo(int stackSize){
    stack = (int*) malloc(sizeof(int)*stackSize);
    if(stack == NULL){
        return -1;
    }
    size = stackSize;
    top = -1;
    return 0;
}

int push(int data){
    printf("Enter data:");
    scanf("%d", &data);
    if(top == size-1){
        printf("Stack overflow\n");
    }
    else{
        top++;
        stack[top] = data;
    }
}

int pop(){
    int temp;
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        temp = stack[top];
        printf("Popped value:%d\n", temp);
        top--;
    }
}

int peek(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("%d\n", stack[top]);
    }
}

void display(){
    int i = 0;
    printf("Stack:");
    while(i<=top){
        printf("%d->", stack[i]);
        i++;
    }
    printf("NULL\n");
}

int main(){
    int a;
    int data;
    int size;
    printf("Enter size of stack:\n");
    scanf("%d",&size);
    demo(size);
    do{
    printf("Operations:\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.Display\n");
    scanf("%d", &a);

    switch(a){

        case 1:
        push(data);
        break;

        case 2:
        pop();
        break;

        case 3:
        peek();
        break;

        case 4:
        display();
        break;

        case 5:
        printf("Exit");

        default:
        printf("Invalid choice.Please try again\n");
    }
    }
    while(a != 5);
    return 0;
}