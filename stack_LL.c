#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack*next;
};

struct stack* createNode(int data){
    struct stack*newNode;
    newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

void display(struct stack* top){
    struct stack* temp = top;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
        }
    printf("NULL\n");
    }
};

struct stack* push(struct stack* top,int data){
    struct stack* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    return top;
}

struct stack* pop(struct stack* top){
    struct stack*temp;
    if(top == NULL){
        printf("Stack Underflow");
        return top;
    }
    else{
       temp = top;
       top = top->next;
       free(temp);
       return top;
    }
    display(top);
}

struct stack* peek(struct stack* top){
    if(top == NULL){
        printf("Stack Underflow");
        return top;
    }
    else{
        printf("%d\n", top->data);
        return top;
    }
}

int main(){
    struct stack* top = NULL;
    int choice;
    do{
        printf("Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        scanf("%d", &choice);

        switch(choice){
            int data;
            
            case 1:
            printf("Enter an element:");
            scanf("%d", &data);
            top = push(top,data);
            display(top);
            break;

            case 2:
            top = pop(top);
            break;

            case 3:
            peek(top);
            break;

            case 4:
            display(top);
            break;

            case 5:
            printf("Exit");

            default:
            printf("Invalid choice.Please try again");
        }
    }
    while(choice!=5);
}