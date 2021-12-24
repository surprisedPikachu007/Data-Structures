#include <stdio.h>
#define max 100
int top;
int stack[max];

void push(int data){
    if(top==max-1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=data;
}

void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n",stack[top]);
    top--;
}

int main(){
    top = -1;
    int choice;
    do{
    printf("Enter choice\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Quit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter data\n");
            int data;
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            break;
        default:
            printf("Invalid choice\n");
    }
    }while (choice!=3);
}
