#include<stdio.h>
int main()
{
  int c, right, left, mid1,mid2, n, search, array[100];

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  printf("Enter value to find\n");
  scanf("%d", &search);


  while (left <= right) {
  	left = 0;
  	right = n - 1;
  	mid1= left+(right-left)/3;
  	mid2=right-(right-left)/3;
  	
  	if(array[mid1]==search || array[mid2]==search)
  	{
  		printf("Found at %d",mid1+1);
  		break;
	  }
  
    if (array[mid1] > search)
      right = mid1-1;
    else if(search>array[mid2])
    	left=mid2+1;
    else
      left=mid1+1;
      right=mid2-1;
  }
  if (left > right)
    printf("Not found! %d isn't present in the list.\n", search);

  return 0;

}
