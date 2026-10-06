#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*next;
};

int length(struct node* head){
    int count = 0;
    struct node* current = head;
    for (current = head;current != NULL;current = current->next){
        count++;
    }
    return count;
};

void display(struct node* head){
    struct node* temp = head;
    if(head == NULL){
        printf("Linked list is empty\n");
    }
    else{
        while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
        }
    printf("NULL\n");
    }
};

struct node* createNode(int data){
    struct node*newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter an element:");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};

struct node* insertionAtHead(struct node* head){
    printf("Insertion at head\n");
    int data;
    struct node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
        return head;
    }
    else{
        newNode->next = head;
        head = newNode;
        return head;
    }
   return head;
};

struct node* insertionAtTail(struct node* head){
    printf("Insertion at tail");
    int data;
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

struct node* deleteAtPos(struct node*head){
    int i = 1;
    int pos;
    printf("Deletion of an element\n");
    printf("Enter the position of the element to be deleted:");
    scanf("%d", &pos);
    struct node* deleteNode;
    struct node* ptr = head;
    int idx = pos-2;
    int l = length(head);
    if(head == NULL){
        printf("linked list is empty");
        return NULL;
    }
    if(pos>l){
        printf("Invalid");
        return head;
    }
    if(pos == 1){
        deleteNode = head;
        head = head->next;
        free(deleteNode);
        return head;
    }
    if(pos == 2){
        deleteNode = head->next;
        head->next = deleteNode->next;
        free(deleteNode);
        return head;
    }
    while(i<pos-1 && ptr != NULL){
        ptr = ptr->next;
        i++;
    }
    deleteNode = ptr->next;
    ptr->next = deleteNode->next;
    free(deleteNode);
    return head;
};

int main(){
    struct node*head = NULL;
    int a;
    do{
        int data;
        int pos;
    printf("Operations:\n");
    printf("1.Insert at head\n");
    printf("2.Insert at tail\n");
    printf("3.Delete a node\n");
    printf("4.Display linked list\n");
    scanf("%d", &a);

        switch(a){

        case 1:
        head = insertionAtHead(head);
        break;

        case 2:
        head = insertionAtTail(head);
        break;
        
        case 3:
        head = deleteAtPos(head);
        break;
        
        case 4:
        display(head);
        break;
        
        case 5:
        printf("Exit");

        default:
        printf("Invalid choice.Please try again");
        
        }
    }
    while(a != 5);
    return 0;
}