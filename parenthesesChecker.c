#include <stdio.h>
#include <string.h>

void stack(){
    int top = -1;
    int i = 0;
    char str[100];
    printf("Enter expression:");
    scanf("%s", str);
    int size = strlen(str);
    int arr[size];

    for (i=0;i<size;i++){
        if(str[i] == '(' || str[i]  == '{' || str[i] == '[' ){
        top++;
        arr[top] = str[i];
        }

        else if(str[i] == ')' || str[i]  == '}' || str[i] == ']'){
            if(top == -1){
                printf("False");
                return;
            }
            else if((str[i]==')' && arr[top]=='(') || (str[i]=='}' && arr[top]) || (str[i]==']' && arr[top]=='[')){
                top--;
            }
            else{
                printf("False");
                return;
            }
        }
    }

    if (top == -1){
        printf("True");
    }
    else{
        printf("False");
    }
}

int main(){
    stack();
}