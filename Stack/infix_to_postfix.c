#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char data){
    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=data;
}

int pop(){
    int x=stack[top];
    top--;
    return x;
}

int peek(){
    if(top!=-1)
    return stack[top];
}

int precedence(char character){
    switch(character){
        case '#':
        return 0;
        case '(':
        return 1;
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        return 3;
    }
    return 0;
}

void infix_to_postfix(char str[]){
    push('#');
    int i=0;

    while(str[i]!='\0'){
        if(isalnum(str[i])){
            printf("%c",str[i]);
        }
        else if(str[i]=='('){
            push(str[i]);
        }
        else if(str[i]==')'){
            while(peek()!='('){
                printf("%c",pop());
            }
            pop();
        }
        else{
            while(precedence(str[i])<=precedence(peek())){
                printf("%c",pop());
            }
            push(str[i]);
        }
        i++;
    }
    while(peek()!='#'){
       printf("%c",pop());
    }
}

int main(){
    char str[] = "a+b*(c-d)/e";
    infix_to_postfix(str);
}