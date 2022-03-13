#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % 100;
    }
    queue[rear] = x;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % 100;
        }
    }
}

void postfix_evaluation(char str[]){
    int i;
    for(i=0;str[i]!='\0';i++){
        if(str[i]>='0' && str[i]<='9'){
            enqueue(str[i]-'0');
        }
        else{
            int a = queue[front];
            dequeue();
            int b = queue[front];
            dequeue();
            switch(str[i]){
                case '+':
                    enqueue(a+b);
                    break;
                case '-':
                    enqueue(a-b);
                    break;
                case '*':
                    enqueue(a*b);
                    break;
                case '/':
                    enqueue(a/b);
                    break;
            }
        }
    }
    printf("%d\n",queue[front]);
}

int main(){
    char str[100];
    scanf("%s", str);
    postfix_evaluation(str);
    return 0;
}