#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;	
};
struct node *first;
struct node *newl,*temp,*prev;
int n,x,i,y;
	
int insert()
{
	newl=(struct node *) malloc(sizeof(struct node*));
	if(first==NULL)
	{
		newl->data=x;
		newl->next=NULL;
		first=newl;
	}
	else
	{
		newl->data=x;
		newl->next=NULL;
		temp=first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newl;
	}
}

int insertatstart()
{
	newl=(struct node *) malloc(sizeof(struct node*));
	if(first==NULL)
	{
		newl->data=x;
		newl->next=NULL;
		first=newl;
	}
	else
	{
		newl->data=x;
		newl->next=first;
		first=newl;
	}
}

int insertafter()
{
	newl=(struct node *) malloc(sizeof(struct node*));
	if(first==NULL)
	{
		newl->data=x;
		newl->next=NULL;
		first=newl;
	}
	else
	{
		newl->data=x;
		temp=first;
		while(temp->data!=y)
			temp=temp->next;
		newl->next=temp->next;
		temp->next=newl;
	}
}

int insertbefore()
{
	newl=(struct node *) malloc(sizeof(struct node*));
	if(first==NULL)
	{
		newl->data=x;
		newl->next=NULL;
		first=newl;
	}
	else
	{
		newl->data=x;
		temp=first;
		while(temp->data!=y)
		{
			prev=temp;
			temp=temp->next;
		}
		newl->next=prev->next;
	    prev->next=newl;
	}
}

int main()
{
	int choice,exit=1;
	
	do
	{
		printf("MENU:\n1.Insertion at end\t2.Insertion at start\t3.Insertion after a specific node\t4.Insertion before a specific node\t5.Display");
		printf("\nEnter choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter no. of elements:");
				scanf("%d",&n);
				
				printf("Enter numbers:");
				for(i=0;i<n;i++)
				{
					scanf("%d",&x);
					insert();
				}
				break;
			case 2:
				printf("Enter no. of elements:");
				scanf("%d",&n);
				
				printf("Enter numbers:");
				for(i=0;i<n;i++)
				{
					scanf("%d",&x);
					insertatstart();
				}
				break;
			case 3:
				printf("Enter after which value to insert:");
				scanf("%d",&y);
				
				printf("Enter no. of elements:");
				scanf("%d",&n);
				
				printf("Enter numbers:");
				for(i=0;i<n;i++)
				{
					scanf("%d",&x);
					insertafter();
				}
				
				break;
			case 4:
				printf("Enter before which value to insert:");
				scanf("%d",&y);
				
				printf("Enter no. of elements:");
				scanf("%d",&n);
				
				printf("Enter numbers:");
				for(i=0;i<n;i++)
				{
					scanf("%d",&x);
					insertbefore();
				}
				break;
			case 5:   
			    if(first == NULL)  
			    {  
			        printf("Nothing to print\n");  
			    }  
			    else  
			    {  
			        printf("\nprinting values . . . . .\n");   
			        while (first!=NULL)  
			        {  
			            printf("\n%d",first->data);  
			            first = first -> next;  
			        }  
			        printf("\n");
			    }  
				break;
			default:
				exit=0;
				break;
		}
	}
	while(exit);
	return 0;
}

