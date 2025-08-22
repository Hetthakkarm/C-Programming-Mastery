//C program to find sum of array elements
#include<stdio.h>

int main(){
  int a[10],i,sum=0;
  for(i=0;i<10;i++)  //for loop to take input
  {
    printf("enter element a[%d]:",i);
    scanf("%d",&a[i]);
  }
  for(i=0;i<10;i++) //for loop to find the sum of elements
  {
    sum=sum+a[i];
  }
  printf("sum of array elements:%d",sum); //output printed
  return 0;
}
