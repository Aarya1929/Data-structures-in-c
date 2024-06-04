#include<stdio.h>

int main()
{
	int a[100],n,i,key,j;
	
	printf("Enter no. of elements=");
	scanf("%d",&n);
	
	printf("Enter elements:");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for (i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
			a[j+1]=key;
	}
	
	printf("Sorted array:");
	for (i=0;i<n;i++)
	{
		printf("%d",a[i]);
		printf("\n");
	}
}
