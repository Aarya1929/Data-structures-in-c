#include <stdio.h>
#include <string.h>
struct employee
{
    char employee_name1[100];
    int emp_no;
    int emp_salary;
};
struct employee arr[30];
int k, num, i, size;
int  j,  tmp, count = 0, tmp3;
char tmp1[100];

void bubbleSort(int size) {

  for (int step = 0; step < size - 1; ++step) {
      
    for (int i = 0; i < size - step - 1; ++i) {
      
      if (arr[i].emp_no > arr[i + 1].emp_no) {
        
        int temp = arr[i].emp_no;
        arr[i].emp_no = arr[i + 1].emp_no;
        arr[i + 1].emp_no = temp;
        
        strcpy(tmp1,arr[i].employee_name1);
    	strcpy(arr[i].employee_name1,arr[i+1].employee_name1);
    	strcpy( arr[i+1].employee_name1,tmp1);
                    
        tmp3 = arr[i].emp_salary;
        arr[i].emp_salary = arr[i+1].emp_salary;
        arr[i+1].emp_salary = tmp3;
        
        count++;
      }
    }
  }
  printf("No. of swap:%d",count);
}

int main()
{
    printf("Enter total no. of employees : ");
    scanf("%d", &num);

    printf("Enter details:\n");
    for (i = 0; i < num; i++)
    {
        printf("%d) Enter name:", i+1);
        scanf("%s", &arr[i].employee_name1);

        printf("Enter Employee No.:");
        scanf("%d", &arr[i].emp_no);

        printf("  Enter Salary:");
        scanf("%d", &arr[i].emp_salary);
    }
    bubbleSort(num);

    printf("\nSorted array :\n ");
    for (k = 0; k < num; k++)
    {
        printf("\n%d) Name:", k+1);
        printf("%s ", arr[k].employee_name1);
        printf("\n    Emp_no: %d", arr[k].emp_no);
        printf("\n    Salary: %d", arr[k].emp_salary);
    }
    return 0;
}
