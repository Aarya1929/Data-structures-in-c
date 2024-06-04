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
char *name[100];
int cnt1=0,cnt2=0;
 
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

int main()
{
    printf("Enter total no. of employees : ");
    scanf("%d", &num);
    
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
    	printf("\n   Salary: %d",arr[k].emp_salary);
	}
    return 0;
}

