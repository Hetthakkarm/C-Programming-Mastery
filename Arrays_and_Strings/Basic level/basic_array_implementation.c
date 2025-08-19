//C program that take 5 integer values and print them out using for loop 
#include <stdio.h>

int main() {
    int a[5],i;//delcaration of array a with size 5
    for(i=0;i<5;i++)//for loop runs untill value of i is less 5 so from 0 to 4 hence 5
    {
        printf("enter element a[%d]",i);
        scanf("%d",&a[i]);//takes input elements for each a of i
    }
    printf("printing array elements:");
    for(i=0;i<5;i++)//for loop use to print the array out
    {
        printf("array a[%d]=%d",i,a[i]);
    }
    return 0;
}
