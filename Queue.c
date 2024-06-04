#include<stdio.h>

struct queue
{
    int front,rear;
    int data[50];
};

int full(struct queue * q)
{
    if(q->rear==49)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q,int x)
{
    if(q->rear==-1)
    {
        q->rear=q->rear+1;
        q->front=q->rear;
        q->data[q->rear]=x;
        printf("Inserted 1");
    }
    else
    {
        q->rear=q->rear+1;
        q->data[q->rear]=x;
        printf("Inserted other.");
    }
}

void dequeue(struct queue * q)
{
    if(q->front==q->rear)
    {
        printf("Empty queue");
        q->front=q->rear=-1;
    }
    else
    {
       printf("Deleted first element:%d",q->data[q->front]);
       q->front=q->front+1;
    }
}

void display(struct queue * q)
{
    while(q->front!=q->rear)
    {
        printf("%d\t",q->data[q->front]);
        q->front++;
    }
    printf("%d",q->data[q->front]);
}

int main()
{
    struct queue q;
    q.rear=-1,q.front=-1;
    int choice,exit=1,n,val,i;
    do
    {
        printf("\nMENU:\n1.Insert\t2.Delete\t3.Display\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                printf("Enter element:");
                scanf("%d",&val);
                if(!full(&q))
                {
                    enqueue(&q,val);
                }
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        default:
            exit=0;
            break;
        }
    }while(exit);
}
