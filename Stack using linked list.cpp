#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *newl,*temp;
struct node *top=NULL;

int x;

void push()
{
	
	printf("Enter element:");
	scanf("%d",&x);
	
		newl=(struct node *)malloc(sizeof(struct node *));
		newl->data=x;
		if(top==NULL)
		{
			newl->next=NULL;
			top=newl;	
		}	
		else
		{
			newl->next=top;
			top=newl;
		}
}

int pop() 
{
    if (top == NULL) 
	{
        printf("\nStack Underflow\n");
    } 
	else 
	{
        temp = top;
        top = top->next;
        free(temp);
    }
}


void display() 
{
    if (top == NULL) 
	{
        printf("\nStack Underflow\n");
    } 
	else 
	{
        printf("The stack is \n");
        struct node *temp = top;
        while (temp->next != NULL) {
            printf("%d =>", temp->data);
            temp = temp->next;
        }
        printf("%d=>NULL\n\n", temp->data);
    }
}


int main()
{
	int choice,exit=1;
	
	do
	{
		printf("MENU\n1.Push\t2.Pop\t3.Display\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				exit=0;
				break;
		}
	}while(exit);
}


