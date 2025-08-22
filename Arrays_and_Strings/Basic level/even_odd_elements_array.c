//C program to find weather element is even or odd and than add them into another array even and odd respectively

#include<stdio.h>

int main()
{
  int a[10],even[10],odd[10],i,j=0,k=0; //declaring variables
  printf("Enter Array Element:\n");
  for(i=0;i<10;i++) //for loop to take input
  {
    printf("enter element a[%d]:",i);
    scanf("%d",&a[i]);
  }

  for(i=0;i<10;i++) //for loop to find weather element is even or odd
  {
    if(a[i]%2==0)
    {
      even[j]=a[i];
      j++;
    }
    else
    {
      odd[k]=a[i];
      k++;
    }
  }
  printf("Even Elements:\n");   //printting even elements
  for(i=0;i<j;i++)
  {
    printf("%d\n",even[i]);
  }
  printf("Odd Elements:\n");  //printting odd elements
  for(i=0;i<k;i++)
  {
    printf("%d\n",odd[i]);
  }
  return 0;
}
