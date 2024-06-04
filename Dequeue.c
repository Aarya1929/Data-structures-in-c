#include<stdio.h>
#define MAX 7
struct dequeue
{
    int data[MAX];
    int rear,front;
};

void initialize(struct dequeue * d)
{
    d->front=-1;
    d->rear=-1;
}

int empty(struct dequeue * d)
{
    if(d->rear==-1)
        return 1;
    return 0;
}

int full(struct dequeue * d)
{
    if((d->rear+1)%MAX==d->front)
        return 1;
    return 0;
}

void insert_r(struct dequeue * d,int x)
{
    if(empty(d))
    {
        d->rear=0;
        d->front=0;
        d->data[0]=x;
    }
    else
    {
        d->rear=(d->rear+1)%MAX;
        d->data[d->rear]=x;
    }
}

void insert_f(struct dequeue * d,int x)
{
    if(empty(d))
    {
        d->rear=0;
        d->front=0;
        d->data[0]=x;
    }
    else
    {
        d->front=(d->front-1+MAX)%MAX;
        d->data[d->front]=x;
    }
}

int delete_f(struct dequeue * d)
{
    int x;
    x=d->data[d->front];
    if(d->rear==d->front)
        initialize(d);
    else
        d->front=(d->front+1)%MAX;
    return x;
}

int delete_r(struct dequeue * d)
{
    int x;
    x=d->data[d->rear];
    if(d->rear==d->front)
        initialize(d);
    else
        d->rear=(d->rear-1+MAX)%MAX;
    return x;
}

int display(struct dequeue * d)
{
    if(empty(d))
    {
        printf("\nEmpty Queue");
        return 0;
    }
    int i;
    i=d->front;
    while(i!=d->rear)
    {
        printf("\n%d",d->data[i]);
        i=(i+1)%MAX;
    }
    printf("\n%d\n",d->data[d->rear]);
}

int main()
{
    int i,x,ch;
    int exit=1;
    struct dequeue q;
    initialize(&q);
    do
    {
        printf("MENU:\n 1.Insert front\t 2.Insert rear\t 3.Delete front\t 4.Delete rear\t 5.Display\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the element to be inserted:");
            scanf("%d",&x);
            if(full(&q))
            {
                printf("\nQueue is full!!");
                return 0;
            }
            insert_f(&q,x);
            break;
        case 2:
            printf("\nEnter the element to be inserted:");
            scanf("%d",&x);
            if(full(&q))
            {
                printf("\nQueue is full!!");
                return 0;
            }
            insert_r(&q,x);
            break;
        case 3:
            if(empty(&q))
            {
                printf("\nQueue is empty!!");
                return 0;
            }
            x=delete_f(&q);
            printf("\nElement deleted is %d\n",x);
            break;
        case 4:
            if(empty(&q))
            {
                printf("\nQueue is empty!!");
                return 0;
            }
            x=delete_r(&q);
            printf("\nElement deleted is %d\n",x);
            break;
        case 5:
            display(&q);
            break;
        default:
            exit=0;
            break;
        }
    }while(exit);
    return 0;
}
