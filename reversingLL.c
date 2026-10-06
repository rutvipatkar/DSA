#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node* createNode(int data){
    struct node*newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

struct node* insertionAtTail(struct node* head,int data){
    struct node* newNode = createNode(data);
    struct node* temp = head;
    if(head == NULL){
        head = newNode;
        return head;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return head;
};    

void display(struct node* head){
    struct node* temp = head;
        while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
        }
    printf("NULL\n");
};

struct node * linkedlist(struct node*head){
    int i;
    int data;
    printf("Enter elements:");
    for (i=0;i<5;i++){
        head = insertionAtTail(head,data);  
    }
    printf("Input linked list:\n");
    display(head);
    return head;
};


struct node* reverse(struct node* head){

    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while(current!= NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(){
    struct node* head = NULL;
    head = linkedlist(head);
    head = reverse(head);
    printf("Reversed liked list:\n");
    display(head);
};