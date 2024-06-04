#include<stdio.h>
#include<string.h>

struct employee
{
	char employee_name1[100];
	int emp_no;
	int emp_salary;	
};
struct employee arr[30];
int k,num,i,array[30],salary[100];
char tmp1[100];
int cnt1=0,cnt2=0,count=0;

void heapify(int* arr, int n, int i)
{

    int largest = i;
 
    int left = 2 * i + 1;
    int right  = 2 * i + 2;
 
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
 
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    } 
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        int tmp3 = salary[i];
        salary[i] = salary[largest];
        salary[largest] = tmp3;
        
        cnt1++;
        
        heapify(arr, n, largest);
    }
}

void heapsort(int* arr, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
 
    for (int i = n - 1; i >= 0; i--)
    {

        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        int tmp3 = salary[i];
        salary[i] = salary[0];
        salary[0] = tmp3;
        
        cnt2++;
 
        heapify(arr, i, 0);
    }
}

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
	int choice,exit=1;
	
	do
	{
		printf("Menu:\n1.Heap sort\t2.Shell sort\n");
		
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		 printf("Enter total no. of employees : ");
         scanf("%d", &num);
		
		switch(choice){
			case 1:
				printf("Enter details:\n");
	for (i=0;i<num;i++)
	{
		printf("%d) Enter name:",i+1);
        scanf("%s", &arr[i].employee_name1);
   
		printf("Enter Employee No.:");
		scanf("%d",&arr[i].emp_no);
		array[i]=arr[i].emp_no;
		
		printf("  Enter Salary:");
		scanf("%d",&arr[i].emp_salary);
		salary[i]=arr[i].emp_salary;
	}
	
    heapsort(array,num);
	
	for(i=0;i<num;i++)
	{
		arr[i].emp_no=array[i];
		arr[i].emp_salary=salary[i];
	}
	
	printf("Total swap=%d",cnt1+cnt2);
	
    printf("\nSorted array :\n ");
    for (k = 0; k < num; k++)
    {
    	printf("\n%d)Emp_no: %d",k+1, arr[k].emp_no);
    	printf("\n   Salary: %d\n",arr[k].emp_salary);
	}
				break;
			case 2:
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
    	printf("\n    Salary: %d\n",arr[k].emp_salary);
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
