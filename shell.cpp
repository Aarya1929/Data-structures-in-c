#include <stdio.h>
#include<string.h>

struct employee
{
	char employee_name1[100];
	int emp_no;
	int emp_salary;	
};
struct employee arr[30];
int k,num,i;

void shellsort()
{
    int i, j, k, tmp,count=0,tmp3;
    char tmp1[100];
    
    for (i = num / 2; i >=1; i = i / 2)
    {
        for (j = i; j <= num; j++)
        {
            for(k = j - i; k > 0; k = k - i)
            {
                if (arr[k+i].emp_no > arr[k].emp_no)
                    break;
                else
                {
                    tmp = arr[k].emp_no;
                    arr[k].emp_no = arr[k+i].emp_no;
                    arr[k+i].emp_no = tmp;
                    
                    strcpy(tmp1,arr[k].employee_name1);
    				strcpy(arr[k].employee_name1,arr[k+i].employee_name1);
    				strcpy( arr[k+i].employee_name1,tmp1);
                    
                    tmp3 = arr[k].emp_salary;
                    arr[k].emp_salary = arr[k+i].emp_salary;
                    arr[k+i].emp_salary = tmp3;
                    
                    count++;
                }
            }
        }
    }
    printf("No. of times swap performed:%d",count);
}
int main()
{
    printf("Enter total no. of employees : ");
    scanf("%d", &num);
    
    
   	printf("Enter details:\n");
	for (i=1;i<=num;i++)
	{
		printf("%d) Enter name:",i);
        scanf("%s", &arr[i].employee_name1);
    
		printf("Enter Employee No.:");
		scanf("%d",&arr[i].emp_no);
		
		printf("  Enter Salary:");
		scanf("%d",&arr[i].emp_salary);
	}
    shellsort();
   
    printf("\nSorted array :\n ");
    for (k = 1; k <= num; k++)
    {
    	printf("\n%d) Name:",k);
    	printf("%s ", arr[k].employee_name1);
    	printf("\n    Emp_no: %d", arr[k].emp_no);
    	printf("\n    Salary: %d",arr[k].emp_salary);
	}
    return 0;
}
