#include<stdio.h>
int main()
{
    int r,co,i,j,a[10][10],b[10][10],c[10][10];

    printf("Enter no. of rows:");
    scanf("%d",&r);
    printf("\nEnter no. of columns:");
    scanf("%d",&co);

    printf("\nEnter first matrix:");
    for(i=0;i<r;i++)
    {
        for(j=0;j<co;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter second matrix:");
    for(i=0;i<r;i++)
    {
        for(j=0;j<co;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<co;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    printf("\nAddition of both matrices is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<co;j++)
        {
            printf("%d",c[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}
