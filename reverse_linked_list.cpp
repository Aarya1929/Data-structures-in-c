#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *first,*temp,*newl;

int i,n,x;

void insert()
{
	newl=(struct node *)malloc(sizeof(struct node *));
	newl->data=x;
	if(first==NULL)
	{
		newl->next=NULL;
		first=newl;	
	}	
	else
	{
		newl->next=NULL;
		temp=first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newl;
	}
} 

reverse()
{
	struct node *x=NULL,*y=first,*z=first->next;
	
	while(y!=NULL)
	{
		y->next=x;
		x=y;
		y=z;
		if(z!=NULL)
		{
			z=z->next;
		}
		first=x;
	}
}

display()
{
	while(first!=NULL)
	{
		printf("%d\t",first->data);
		first=first->next;
	}
}


int main()
{
	printf("Enter no .of nodes:");
	scanf("%d",&n);
	
	printf("Enter values:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert();
	}
	
	printf("Reversed:");
	reverse();
	
	display();
}
