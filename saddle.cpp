#include<stdio.h>

int main()
{
	int a[3][3],i,j,k,col,max=0,min=0,m,n;
	
	printf("Enter number of rows and columns respectively:");
	scanf("%d %d",&m,&n);
	
	printf("Enter elements of matrix:\n");
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for (i=0;i<m;i++)
	{
		min=a[i][0];
		col=0;
		for (j=0;j<n;j++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
				col=j;
			}
		}
		max=0;
		for(k=0;k<n;k++)
		{
			if (max<a[k][col])
			{
				max=a[k][col];
			}
		}
	}
		if (max==min)
		{
			printf("Saddle point at %d",max);
		}
		else
		{
			printf("No Saddle point");
		}
	

}
