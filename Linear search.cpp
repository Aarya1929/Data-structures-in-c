#include<stdio.h>
int main()
{
	int a[10],n,num,i;
	
	printf("Enter no. of elements in array=");
	scanf("%d",&n);
	
	printf("Enter elements:");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Enter number=");
	scanf("%d",&num);
	
	for (i=0;i<n;i++)
	{
		if (a[i]==num)
		{
			printf("Found at place %d",i+1);
		}
		else
		{
			printf("Not present");
		}
	}
}
